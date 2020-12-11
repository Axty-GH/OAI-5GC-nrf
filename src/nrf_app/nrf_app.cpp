/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
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
#include "common_defs.h"
#include "nrf_config.hpp"
#include "logger.hpp"
#include "api_conversions.hpp"
#include "3gpp_29.500.h"

using namespace oai::nrf::app;
using namespace oai::nrf::model;

extern nrf_app *nrf_app_inst;
extern nrf_config nrf_cfg;

//------------------------------------------------------------------------------
nrf_app::nrf_app(const std::string &config_file) {
  Logger::nrf_app().startup("Starting...");
  Logger::nrf_app().startup("Started");
}

//------------------------------------------------------------------------------
void nrf_app::handle_register_nf_instance(
    const std::string &nf_instance_id,
    const oai::nrf::model::NFProfile &nf_profile, int &http_code,
    const uint8_t http_version) {

  Logger::nrf_app().info("Handle NF Instance Registration (HTTP version %d)",
                         http_version);
  //Check if nfInstanceID is a valid UUID (version 4)
  //TODO

  //Create NF and store
  /*
   std::shared_ptr<nrf_profile> sn = { };
   sn = find_nf_profile(nf_instance_id);
   if (sn.get() != nullptr) {
   if (sn.get()->get_nf_type() == NF_TYPE_AMF) {
   std::shared_ptr<amf_profile> sa = std::static_pointer_cast
   < amf_profile > (sn);
   if (!api_conv::profile_api_to_amf_profile(nf_profile, sa)) {
   //error, TODO
   Logger::nrf_app().warn(
   "Cannot convert a NF profile generated from OpenAPI to an AMF profile (profile ID %s)",
   nf_instance_id.c_str());
   }

   update_nf_profile(nf_instance_id, sa);
   }

   //if (is_profile_exist(nf_instance_id)) {
   //if (find_nf_profile(nf_instance_id, sn)) {
   //if a profile exist with this ID, return error
   //sa = std::static_pointer_cast <amf_profile> (sn);
   //update_nf_profile(nf_instance_id, sa);
   } else {
   //create a new NF profile
   Logger::nrf_app().debug("NF Profile with (ID %s, NF type %s)",
   nf_instance_id.c_str(), nf_profile.getNfType().c_str());

   std::shared_ptr<amf_profile> sa = { };
   if (nf_profile.getNfType().compare("AMF") == 0) {
   sa = std::shared_ptr < amf_profile
   > (new amf_profile(nf_instance_id));
   if (!api_conv::profile_api_to_amf_profile(nf_profile, sa)) {
   //error, TODO
   }
   }
   add_nf_profile(nf_instance_id, sa);
   }
   */
  /*
   //create/Update NF profile
   Logger::nrf_app().debug("NF Profile with (ID %s, NF type %s)",
   nf_instance_id.c_str(), nf_profile.getNfType().c_str());

   if (nf_profile.getNfType().compare("AMF") == 0) {
   std::shared_ptr<amf_profile> sa = { };
   sa = std::shared_ptr < amf_profile > (new amf_profile(nf_instance_id));
   if (!api_conv::profile_api_to_amf_profile(nf_profile, sa)) {
   //error, TODO
   Logger::nrf_app().warn(
   "Cannot convert a NF profile generated from OpenAPI to an AMF profile (profile ID %s)",
   nf_instance_id.c_str());
   http_code = 412; //Precondition Failed
   } else {
   add_nf_profile(nf_instance_id, sa);
   http_code = 200;
   }
   }
   */

  nf_type_t type = api_conv::string_to_nf_type(nf_profile.getNfType());
  //Create a new NF profile or Update an existing NF profile
  Logger::nrf_app().debug("NF Profile with (ID %s, NF type %s)",
                          nf_instance_id.c_str(),
                          nf_profile.getNfType().c_str());


  std::shared_ptr<nrf_profile> sn = { };

  switch (type) {
    case NF_TYPE_AMF:
      sn = std::make_shared<amf_profile>();
      break;
    case NF_TYPE_SMF:
      //TODO
      break;
    default:
      sn = std::make_shared<nrf_profile>();
  }
  /*
  if (nf_profile.getNfType().compare("AMF") == 0) {
    sn = std::make_shared<amf_profile>();
  } else if (nf_profile.getNfType().compare("SMF") == 0) {
    //TODO:

  } else {
    //default
    sn = std::make_shared<nrf_profile>();
  }
*/
  //convert to nrf_profile
  if (api_conv::profile_api_to_amf_profile(nf_profile, sn)) {
    add_nf_profile(nf_instance_id, sn);
    http_code = HTTP_STATUS_CODE_201_CREATED;

    Logger::nrf_app().debug("Added NF Profile to the DB");
    if (nf_profile.getNfType().compare("AMF") == 0)
      std::static_pointer_cast < amf_profile > (sn).get()->display();

  } else {
    //error
    Logger::nrf_app().warn(
        "Cannot convert a NF profile generated from OpenAPI to an AMF profile (profile ID %s)",
        nf_instance_id.c_str());
    http_code = HTTP_STATUS_CODE_412_PRECONDITION_FAILED;
  }

  //For Debug purpose
  /*      std::vector < std::shared_ptr < nrf_profile >> profiles = { };
   find_nf_profiles("AMF", profiles);
   for (auto profile : profiles) {
   (std::static_pointer_cast < amf_profile > (profile)).get()->display();
   }
   */

}

void nrf_app::handle_update_nf_instance(const std::string &nf_instance_id,
                                        const std::vector<PatchItem> &patchItem,
                                        int &http_code,
                                        const uint8_t http_version) {

  Logger::nrf_app().info("Handle Update NF Instance request (HTTP version %d)",
                         http_version);

  //Find the profile corresponding to the instance ID
  std::shared_ptr<nrf_profile> sn = { };
  sn = find_nf_profile(nf_instance_id);
  if (sn.get() != nullptr) {
    //if (find_nf_profile(nf_instance_id, sn)) {
    //if a profile exist with this ID, return error
    //sa = std::static_pointer_cast <amf_profile> (sn);
    //update_nf_profile(nf_instance_id, sa);

    //std::shared_ptr<amf_profile> sa = { };
    if (sn.get()->get_nf_type() == NF_TYPE_AMF) {
      std::shared_ptr<amf_profile> sa = std::static_pointer_cast < amf_profile
          > (sn);
      update_nf_profile(nf_instance_id, sa);
    }
    //add_nf_profile(nf_instance_id, sa);
  } else {
    Logger::nrf_app().debug("NF Profile with ID %s does not exit",
                            nf_instance_id.c_str());

  }

  //location header - URI of created resource: can be used with ID - UUID
}
//------------------------------------------------------------------------------
void nrf_app::handle_get_nf_instances(const std::string &nf_type,
                                      const uint32_t limit_item, int &http_code,
                                      const uint8_t http_version) {
  Logger::nrf_app().info(
      "Handle Retrieve a collection of NF Instances (HTTP version %d)",
      http_version);

  std::vector < std::shared_ptr < nrf_profile >> profiles = { };
  nf_type_t type = api_conv::string_to_nf_type(nf_type);
  find_nf_profiles(type, profiles);
  if (profiles.size() == 0) {
    Logger::nrf_app().debug("No profile found with type %s", nf_type.c_str());
  }
  for (auto profile : profiles) {
    (std::static_pointer_cast < amf_profile > (profile)).get()->display();
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
  //Create or update if profile exist
  instance_id2nrf_profile[profile_id] = p;
  return true;
}

//------------------------------------------------------------------------------
bool nrf_app::update_nf_profile(const std::string &profile_id,
                                const std::shared_ptr<nrf_profile> &p) {
  std::unique_lock lock(m_instance_id2nrf_profile);
  //if profile with this id exist, return false
  if (instance_id2nrf_profile.count(profile_id) > 0) {
    //if not, update to the list
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

  std::unique_lock lock(m_instance_id2nrf_profile);
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

  std::unique_lock lock(m_instance_id2nrf_profile);
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
  for (auto profile : instance_id2nrf_profile) {
    //std::string type = profile.second.get()->get_nf_type();
    if (profile.second.get()->get_nf_type() == nf_type) {
      profiles.push_back(profile.second);
    }
  }
  //return true;
}

//------------------------------------------------------------------------------
bool nrf_app::is_profile_exist(const std::string &profile_id) const {
  Logger::nrf_app().info("Check if a profile with this ID %d exist",
                         profile_id.c_str());

  std::unique_lock lock(m_instance_id2nrf_profile);
  if (instance_id2nrf_profile.count(profile_id) > 0) {
    return true;
  } else {
    Logger::nrf_app().info("NF profile (ID %d) not found", profile_id.c_str());
    return false;
  }

}

//------------------------------------------------------------------------------
bool nrf_app::remove_nf_profile(std::shared_ptr<nrf_profile> &snp) {
  //TODO
  return true;
}

//------------------------------------------------------------------------------
bool nrf_app::remove_nf_profile(std::string &profile_id) {
  //TODO
  return true;
}

