/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this
 *file except in compliance with the License. You may obtain a copy of the
 *License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*! \file nrf_app.cpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: tien-thinh.nguyen@eurecom.fr
 */

#include "nrf_app.hpp"
#include <chrono>
#include "3gpp_29.500.h"
#include "api_conversions.hpp"
#include "common_defs.h"
#include "logger.hpp"
#include "nrf_config.hpp"

using namespace oai::nrf::app;
using namespace oai::nrf::model;
using namespace std::chrono;

extern nrf_app *nrf_app_inst;
extern nrf_config nrf_cfg;

//------------------------------------------------------------------------------
nrf_app::nrf_app(const std::string &config_file, nrf_event &ev)
    : m_event_sub(ev) {
  Logger::nrf_app().startup("Starting...");
  Logger::nrf_app().startup("Started");
}

//------------------------------------------------------------------------------
void nrf_app::handle_register_nf_instance(
    const std::string &nf_instance_id,
    const oai::nrf::model::NFProfile &nf_profile, int &http_code,
    const uint8_t http_version,
    oai::nrf::model::ProblemDetails &problem_details) {
  Logger::nrf_app().info(
      "Handle Register NF Instance/Update NF Instance (HTTP version %d)",
      http_version);

  // Check if nfInstanceID is a valid UUID (version 4)
  if (!api_conv::validate_uuid(nf_instance_id)) {
    http_code = HTTP_STATUS_CODE_400_BAD_REQUEST;
    Logger::nrf_app().debug("Bad UUID format for NF Instance ID (%s)",
                            nf_instance_id.c_str());
    problem_details.setCause(
        protocol_application_error_e2str[MANDATORY_QUERY_PARAM_INCORRECT]);
    return;
  }

  nf_type_t type = api_conv::string_to_nf_type(nf_profile.getNfType());
  // Create a new NF profile or Update an existing NF profile
  Logger::nrf_app().debug("NF Profile with (ID %s, NF type %s)",
                          nf_instance_id.c_str(),
                          nf_profile.getNfType().c_str());

  std::shared_ptr<nrf_profile> sn = {};
  switch (type) {
    case NF_TYPE_AMF: {
      sn = std::make_shared<amf_profile>(m_event_sub);
    } break;

    case NF_TYPE_SMF: {
      sn = std::make_shared<smf_profile>(m_event_sub);
    } break;

    default: { sn = std::make_shared<nrf_profile>(m_event_sub); }
  }

  // convert to nrf_profile
  if (api_conv::profile_api_to_nrf_profile(nf_profile, sn)) {
    // set default value for hearbeattimer
    sn.get()->set_nf_heartBeat_timer(HEART_BEAT_TIMER);
    if (is_profile_exist(nf_instance_id))
      http_code = HTTP_STATUS_CODE_200_OK;
    else
      http_code = HTTP_STATUS_CODE_201_CREATED;
    // add to the DB
    add_nf_profile(nf_instance_id, sn);
    Logger::nrf_app().debug("Added/Updated NF Profile to the DB");
    // display the info
    sn.get()->display();
  } else {
    // error
    Logger::nrf_app().warn(
        "Cannot convert a NF profile generated from OpenAPI to an AMF profile "
        "(profile ID %s)",
        nf_instance_id.c_str());
    http_code = HTTP_STATUS_CODE_400_BAD_REQUEST;
    problem_details.setCause(
        protocol_application_error_e2str[MANDATORY_IE_INCORRECT]);
  }
}

//------------------------------------------------------------------------------
void nrf_app::handle_update_nf_instance(
    const std::string &nf_instance_id, const std::vector<PatchItem> &patchItem,
    int &http_code, const uint8_t http_version,
    oai::nrf::model::ProblemDetails &problem_details) {
  Logger::nrf_app().info("Handle Update NF Instance request (HTTP version %d)",
                         http_version);

  // Find the profile corresponding to the instance ID
  std::shared_ptr<nrf_profile> sn = {};
  sn = find_nf_profile(nf_instance_id);
  bool op_success = true;
  bool is_heartbeart_procedure = false;

  if (sn.get() != nullptr) {
    for (auto p : patchItem) {
      patch_op_type_t op = api_conv::string_to_patch_operation(p.getOp());
      // Verify Path
      if ((p.getPath().substr(0, 1).compare("/") != 0) or
          (p.getPath().length() < 2)) {
        Logger::nrf_app().warn("Bad value for operation path: %s ",
                               p.getPath().c_str());
        http_code = HTTP_STATUS_CODE_400_BAD_REQUEST;
        problem_details.setCause(
            protocol_application_error_e2str[MANDATORY_IE_INCORRECT]);
        return;
      }

      std::string path = p.getPath().substr(1);

      switch (op) {
        case PATCH_OP_REPLACE: {
          if (path.compare("nfStatus") == 0) is_heartbeart_procedure = true;
          if (sn.get()->replace_profile_info(path, p.getValue())) {
            update_nf_profile(nf_instance_id, sn);
            http_code = HTTP_STATUS_CODE_200_OK;
          } else {
            op_success = false;
          }
        } break;

        case PATCH_OP_ADD: {
          if (sn.get()->add_profile_info(path, p.getValue())) {
            update_nf_profile(nf_instance_id, sn);
            http_code = HTTP_STATUS_CODE_200_OK;
          } else {
            op_success = false;
          }
        } break;

        case PATCH_OP_REMOVE: {
          if (sn.get()->remove_profile_info(path)) {
            update_nf_profile(nf_instance_id, sn);
            http_code = HTTP_STATUS_CODE_200_OK;
          } else {
            op_success = false;
          }
        } break;

        default: {
          Logger::nrf_app().warn("Requested operation is not valid!");
        }
      }

      if (!op_success) {
        http_code = HTTP_STATUS_CODE_400_BAD_REQUEST;
        problem_details.setCause(
            protocol_application_error_e2str[MANDATORY_IE_INCORRECT]);
      }
    }

    // for NF Heartbeat procedure
    if (is_heartbeart_procedure && (http_code = HTTP_STATUS_CODE_200_OK)) {
      http_code = HTTP_STATUS_CODE_204_NO_CONTENT;
    }

  } else {
    Logger::nrf_app().debug("NF Profile with ID %s does not exit",
                            nf_instance_id.c_str());
    http_code = HTTP_STATUS_CODE_404_NOT_FOUND;
    problem_details.setCause(
        protocol_application_error_e2str[RESOURCE_URI_STRUCTURE_NOT_FOUND]);
  }
}

//------------------------------------------------------------------------------
void nrf_app::handle_get_nf_instances(const std::string &nf_type,
                                      const uint32_t &limit_item,
                                      int &http_code,
                                      const uint8_t http_version) {
  Logger::nrf_app().info(
      "Handle Retrieve a collection of NF Instances (HTTP version %d)",
      http_version);

  std::vector<std::shared_ptr<nrf_profile>> profiles = {};
  nf_type_t type = api_conv::string_to_nf_type(nf_type);
  find_nf_profiles(type, profiles);

  if (profiles.size() == 0) {
    Logger::nrf_app().debug("No profile found (NF type: %s)", nf_type.c_str());
  }

  for (auto profile : profiles) {
    profile.get()->display();
  }
}

void nrf_app::handle_get_nf_instance(const std::string &nf_instance_id,
                                     std::shared_ptr<nrf_profile> &profile,
                                     int &http_code, const uint8_t http_version,
                                     ProblemDetails &problem_details) {
  Logger::nrf_app().info("Handle Retrieve an NF Instance (HTTP version %d)",
                         http_version);

  // TODO:  If the NF Service Consumer is not allowed to retrieve the NF profile
  // of this specific registered NF instance, the  NRF shall return "403
  // Forbidden" status code.

  profile = find_nf_profile(nf_instance_id);
  if (profile.get() == nullptr) {
    Logger::nrf_app().debug("Profile with profile ID %s not found",
                            nf_instance_id.c_str());
    http_code = HTTP_STATUS_CODE_404_NOT_FOUND;
    problem_details.setCause(
        protocol_application_error_e2str[RESOURCE_URI_STRUCTURE_NOT_FOUND]);
    return;
  } else {
    Logger::nrf_app().debug("Profile with profile ID %s",
                            nf_instance_id.c_str());
    profile.get()->display();
    http_code = HTTP_STATUS_CODE_200_OK;
    return;
  }
}

//------------------------------------------------------------------------------
void nrf_app::handle_deregister_nf_instance(const std::string &nf_instance_id,
                                            int &http_code,
                                            const uint8_t http_version,
                                            ProblemDetails &problem_details) {
  Logger::nrf_app().info("Handle Deregister an NF Instance (HTTP version %d)",
                         http_version);

  if (is_profile_exist(nf_instance_id)) {
    if (remove_nf_profile(nf_instance_id)) {
      Logger::nrf_app().debug("Removed NF profile with profile ID %s",
                              nf_instance_id.c_str());
      http_code = HTTP_STATUS_CODE_204_NO_CONTENT;
      return;
    } else {
      http_code = HTTP_STATUS_CODE_500_INTERNAL_SERVER_ERROR;
      problem_details.setCause(
          protocol_application_error_e2str[SYSTEM_FAILURE]);
      return;
    }
  } else {
    Logger::nrf_app().debug("Profile with profile ID %s not found",
                            nf_instance_id.c_str());
    http_code = HTTP_STATUS_CODE_404_NOT_FOUND;
    problem_details.setCause(
        protocol_application_error_e2str[RESOURCE_URI_STRUCTURE_NOT_FOUND]);
    return;
  }
}

//------------------------------------------------------------------------------
void nrf_app::handle_create_subscription(
    const SubscriptionData &subscription_data, std::string &sub_id, int &http_code,
    const uint8_t http_version, ProblemDetails &problem_details) {
  std::string evsub_id;

  Logger::nrf_app().info("Handle Create a new subscription (HTTP version %d)",
                         http_version);
  std::shared_ptr<nrf_subscription> ss = std::make_shared<nrf_subscription>(m_event_sub);

  // convert to nrf_subscription
  if (api_conv::subscription_api_to_nrf_subscription(subscription_data, ss)) {
    if (authorize_subscription(ss)) {
        // generate a subscription ID
        generate_ev_subscription_id(evsub_id);
        //subscribe to NF status change
        ss.get()->subscribe_nf_status_change();
        // add to the DB
        add_subscription(evsub_id, ss);
        Logger::nrf_app().debug("Added a subscription to the DB");
        // display the info
        ss.get()->display();
        //assign info for API server
        http_code = HTTP_STATUS_CODE_201_CREATED;
        sub_id = evsub_id;
        return;
    } else {
    	Logger::nrf_app().debug("Subscription is not authorized!");
    	http_code = HTTP_STATUS_CODE_401_UNAUTHORIZED;
    	return;
    }

  } else {
    // error
    Logger::nrf_app().warn(
        "Cannot convert the subscription data (from OpenAPI) to an NRF "
        "subscription data");
    http_code = HTTP_STATUS_CODE_400_BAD_REQUEST;
    problem_details.setCause(
        protocol_application_error_e2str[MANDATORY_IE_INCORRECT]);
  }
}

//------------------------------------------------------------------------------
bool nrf_app::add_nf_profile(const std::string &profile_id,
                             const std::shared_ptr<nrf_profile> &p) {
  std::unique_lock lock(m_instance_id2nrf_profile);
  /*
   //if profile with this id exist, update
   if (instance_id2nrf_profile.count(profile_id) > 0) {
   Logger::nrf_app().info(
   "Update a NF profile to the list (profile ID %s)",
   profile_id.c_str());
   instance_id2nrf_profile.at(profile_id) = p;
   } else {
   //if not, add to the list
   Logger::nrf_app().info(
   "Insert a NF profile to the list (profile ID %s)",
   profile_id.c_str());
   instance_id2nrf_profile.emplace(profile_id, p);
   }*/
  // Create or update if profile exist
  instance_id2nrf_profile[profile_id] = p;

  // heartbeart management for this NF profile
  // get current time
  uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch())
                    .count();
  p.get()->subscribe_task_tick(ms);

  return true;
}

//------------------------------------------------------------------------------
bool nrf_app::update_nf_profile(const std::string &profile_id,
                                const std::shared_ptr<nrf_profile> &p) {
  std::unique_lock lock(m_instance_id2nrf_profile);
  // if profile with this id exist, return false
  if (instance_id2nrf_profile.count(profile_id) > 0) {
    // if not, update to the list
    Logger::nrf_app().info("Update a NF profile to the list (profile ID %s)",
                           profile_id.c_str());
    instance_id2nrf_profile.at(profile_id) = p;
    return true;
  } else {
    Logger::nrf_app().info("NF profile (ID %d) not found", profile_id.c_str());
    return false;
  }
}

//------------------------------------------------------------------------------
std::shared_ptr<nrf_profile> nrf_app::find_nf_profile(
    const std::string &profile_id) const {
  Logger::nrf_app().info("Find a NF profile with ID %s", profile_id.c_str());

  std::shared_lock lock(m_instance_id2nrf_profile);
  if (instance_id2nrf_profile.count(profile_id) > 0) {
    return instance_id2nrf_profile.at(profile_id);
  } else {
    Logger::nrf_app().info("NF profile (ID %s) not found", profile_id.c_str());
    return nullptr;
  }
}

//------------------------------------------------------------------------------
bool nrf_app::find_nf_profile(const std::string &profile_id,
                              std::shared_ptr<nrf_profile> &p) const {
  Logger::nrf_app().info("Find a NF profile with ID %s", profile_id.c_str());

  std::shared_lock lock(m_instance_id2nrf_profile);
  if (instance_id2nrf_profile.count(profile_id) > 0) {
    p = instance_id2nrf_profile.at(profile_id);
    return true;
  } else {
    Logger::nrf_app().info("NF profile (ID %d) not found", profile_id.c_str());
    return false;
  }
}

//------------------------------------------------------------------------------
void nrf_app::find_nf_profiles(
    const nf_type_t &nf_type,
    std::vector<std::shared_ptr<nrf_profile>> &profiles) const {
  std::shared_lock lock(m_instance_id2nrf_profile);
  for (auto profile : instance_id2nrf_profile) {
    if (profile.second.get()->get_nf_type() == nf_type) {
      profiles.push_back(profile.second);
    }
  }
}

//------------------------------------------------------------------------------
bool nrf_app::is_profile_exist(const std::string &profile_id) const {
  Logger::nrf_app().info("Check if a profile with this ID %d exist",
                         profile_id.c_str());

  std::shared_lock lock(m_instance_id2nrf_profile);
  if (instance_id2nrf_profile.count(profile_id) > 0) {
    return true;
  } else {
    Logger::nrf_app().info("NF profile (ID %d) not found", profile_id.c_str());
    return false;
  }
}

//------------------------------------------------------------------------------
bool nrf_app::remove_nf_profile(const std::shared_ptr<nrf_profile> &snp) {
  std::string key;
  snp.get()->get_nf_instance_id(key);
  std::unique_lock lock(m_instance_id2nrf_profile);
  if (instance_id2nrf_profile.erase(key)) {
    Logger::nrf_app().info("Removed NF profile (ID %d) from the list",
                           key.c_str());
    return true;
  } else {
    Logger::nrf_app().info("Remove_NF_profile, profile not found (ID %d)",
                           key.c_str());
    return false;
  }
}

//------------------------------------------------------------------------------
bool nrf_app::remove_nf_profile(const std::string &profile_id) {
  std::unique_lock lock(m_instance_id2nrf_profile);
  if (instance_id2nrf_profile.erase(profile_id)) {
    Logger::nrf_app().info("Removed NF profile (ID %d) from the list",
                           profile_id.c_str());
    return true;
  } else {
    Logger::nrf_app().info("Remove_NF_profile, profile not found (ID %d)",
                           profile_id.c_str());
    return false;
  }
}

//------------------------------------------------------------------------------
bool nrf_app::add_subscription(const std::string &sub_id,
                               const std::shared_ptr<nrf_subscription> &s) {
  std::unique_lock lock(m_instance_id2nrf_subscription);
  /*
   //if profile with this id exist, update
   if (instance_id2nrf_subscription.count(sub_id) > 0) {
   Logger::nrf_app().info(
   "Update a subscription to the list (Subscription ID %s)",
   sub_id.c_str());
   instance_id2nrf_subscription.at(sub_id) = s;
   } else {
   //if not, add to the list
   Logger::nrf_app().info(
   "Insert a subscription to the list (Subscription ID %s)",
   sub_id.c_str());
   instance_id2nrf_subscription.emplace(sub_id, s);
   }*/
  // Create or update if subscription exist
  instance_id2nrf_subscription[sub_id] = s;
  return true;
}

//------------------------------------------------------------------------------
void nrf_app::subscribe_task_tick(uint64_t ms) {
  struct itimerspec its;
  its.it_value.tv_sec = 20;  // seconds
  its.it_value.tv_nsec = 0;  // 100 * 1000 * 1000; //100ms

  const uint64_t interval =
      its.it_value.tv_sec * 1000 +
      its.it_value.tv_nsec / 1000000;  // convert sec, nsec to msec

  Logger::nrf_app().debug("subscribe task_tick: %d", ms);
  m_event_sub.subscribe_task_tick(
      boost::bind(&nrf_app::handle_heartbeart_timeout, this, _1), interval,
      ms % 20000);
}

//------------------------------------------------------------------------------
void nrf_app::handle_heartbeart_timeout(uint64_t ms) {
  Logger::nrf_app().info("handle_heartbeart_timeout %d", ms);
}

bool nrf_app::authorize_subscription(const std::shared_ptr<nrf_subscription> &s) const {
	//TODO:
	return true;
}
//------------------------------------------------------------------------------
void nrf_app::generate_ev_subscription_id(std::string &sub_id) {
  sub_id = std::to_string(evsub_id_generator.get_uid());
}

//------------------------------------------------------------------------------
evsub_id_t nrf_app::generate_ev_subscription_id() {
  return evsub_id_generator.get_uid();
}
