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

/*! \file nrf_app.hpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: Tien-Thinh.Nguyen@eurecom.fr
 */

#ifndef FILE_NRF_APP_HPP_SEEN
#define FILE_NRF_APP_HPP_SEEN

#include <string>
#include "NFProfile.h"
#include "nrf_profile.hpp"
#include "nrf_subscription.hpp"
#include "nrf_event.hpp"
#include "PatchItem.h"
#include "ProblemDetails.h"
#include "SubscriptionData.h"
#include "uint_generator.hpp"

namespace oai {
namespace nrf {
namespace app {

using namespace oai::nrf::model;
class nrf_config;
class nrf_app {

 public:
  explicit nrf_app(const std::string &config_file, nrf_event& ev);
  nrf_app(nrf_app const&) = delete;
  void operator=(nrf_app const&) = delete;

  virtual ~nrf_app() {
    Logger::nrf_app().debug("Delete NRF_APP instance...");
    for (auto i: connections) {
    	if (i.connected()) i.disconnect();
    }
  }


  /*
   * Handle a Register NF Instance request
   * @param [const std::string &] nf_instance_id: Instance ID
   * @param [NFProfile &] nf_profile: NF profile
   * @param [int &] http_code: HTTP code used to return to the consumer
   * @param [const uint8_t] http_version: HTTP version
   * @param [ProblemDetails &] problem_details: Store details of the error
   * @return void
   */
  void handle_register_nf_instance(
      const std::string &nf_instance_id,
      const NFProfile &nf_profile, int &http_code,
      const uint8_t http_version,
      ProblemDetails &problem_details);

  /*
   * Handle a Get NF Instance Information
   * @param [const std::string &] nf_type: NF's type
   * @param [const uint32_t &] limit_item: Maximum number of items returned
   * @param [int &] http_code: HTTP code used to return to the consumer
   * @param [const uint8_t] http_version: HTTP version
   * @return void
   */
  void handle_get_nf_instances(const std::string &nf_type,
                               const uint32_t &limit_item, int &http_code,
                               const uint8_t http_version);

  /*
   * Handle a Update NF Instance request
   * @param [const std::string &] nf_instance_id: Instance ID
   * @param [const std::vector<PatchItem> &] patchItem: List of modifications need to be applied
   * @param [int &] http_code: HTTP code used to return to the consumer
   * @param [const uint8_t] http_version: HTTP version
   * @param [ProblemDetails &] problem_details: Store details of the error
   * @return void
   */
  void handle_update_nf_instance(
      const std::string &nf_instance_id,
      const std::vector<PatchItem> &patchItem, int &http_code,
      const uint8_t http_version,
      ProblemDetails &problem_details);

  /*
   * Handle a Get NF Instance request
   * @param [const std::string &] nf_instance_id: Instance ID
   * @param [nrf_profile &] profile: NF profile
   * @param [int &] http_code: HTTP code used to return to the consumer
   * @param [const uint8_t] http_version: HTTP version
   * @param [ProblemDetails &] problem_details: Store details of the error
   * @return void
   */
  void handle_get_nf_instance(
      const std::string &nf_instance_id,
      std::shared_ptr < nrf_profile > &profile, int &http_code,
      const uint8_t http_version,
      ProblemDetails &problem_details);

  /*
   * Handle De-register a given NF Instance
   * @param [const std::string &] nf_instance_id: Instance ID
   * @param [int &] http_code: HTTP code used to return to the consumer
   * @param [const uint8_t] http_version: HTTP version
   * @param [ProblemDetails &] problem_details: Store details of the error
   * @return void
   */
  void handle_deregister_nf_instance(
      const std::string &nf_instance_id,
      int &http_code,
      const uint8_t http_version,
      ProblemDetails &problem_details);

  /*
   * Handle a Register NF Instance request
   * @param [SubscriptionData &] subscription_data: Subscription data
   * @param [int &] http_code: HTTP code used to return to the consumer
   * @param [const uint8_t] http_version: HTTP version
   * @param [ProblemDetails &] problem_details: Store details of the error
   * @return void
   */
  void handle_create_subscription(
      const SubscriptionData &subscription_data, std::string &sub_id, int &http_code,
      const uint8_t http_version,
      ProblemDetails &problem_details);

  /*
   * Insert a nrf profile
   * @param [const std::string &] profile_id: Profile ID
   * @param [std::shared_ptr<nrf_profile> &] p: profile to be added
   * @return true if successful, otherwise, return false
   */
  bool add_nf_profile(const std::string &profile_id,
                      const std::shared_ptr<nrf_profile> &p);

  /*
   * Update a nrf profile
   * @param [const std::string &] profile_id: Profile ID
   * @param [std::shared_ptr<nrf_profile> &] p: profile to be added
   * @return true if successful, otherwise, return false
   */
  bool update_nf_profile(const std::string &profile_id,
                         const std::shared_ptr<nrf_profile> &p);

  /*
   * Find a nf profile with its ID
   * @param [const std::string &] profile_id: Profile ID
   * @return shared pointer to the profile if found
   */
  std::shared_ptr<nrf_profile> find_nf_profile(
      const std::string &profile_id) const;

  /*
   * Find a nf profile with its ID
   * @param [const std::string &] profile_id: Profile ID
   * @return shared pointer to the profile if found
   */
  bool find_nf_profile(const std::string &profile_id,
                       std::shared_ptr<nrf_profile> &p) const;

  /*
   * Find a list of nf profiles with a type
   * @param [const nf_type_t &] nf_type: Type of NF profile
   * @param [std::vector<std::shared_ptr<nrf_profile>> &] profiles: Store list of corresponding profiles
   * @return shared pointer to the profile if found
   */
  void find_nf_profiles(
      const nf_type_t &nf_type,
      std::vector<std::shared_ptr<nrf_profile>> &profiles) const;

  /*
   * Check if a profile with an ID exist
   * @param [const std::string &] profile_id: Profile ID
   * @return true if profile exist, otherwise, return false
   */
  bool is_profile_exist(const std::string &profile_id) const;

  /*
   * Remove a nf profile from the list
   * @param [std::shared_ptr<nrf_profile> &] snp: profile to be removed
   * @return true if successful, otherwise, return false
   */
  bool remove_nf_profile(const std::shared_ptr<nrf_profile> &snp);

  /*
   * Remove a nf profile from the list
   * @param [std::string &] profile_id: ID of the profile to be removed
   * @return true if successful, otherwise, return false
   */
  bool remove_nf_profile(const std::string &profile_id);

  bool add_subscription(const std::string &sub_id,
                               const std::shared_ptr<nrf_subscription> &s);

  void subscribe_task_tick (uint64_t ms);
  void handle_heartbeart_timeout(uint64_t ms);

  bool authorize_subscription(const std::shared_ptr<nrf_subscription> &s) const;
  void generate_ev_subscription_id(std::string &sub_id);
  evsub_id_t generate_ev_subscription_id();

  void subscribe_nf_status();
  void subscribe_nf_status_registered();
  void handle_nf_status_registered(const std::string &profile_id);
  void subscribe_nf_status_deregistered();
  void handle_nf_status_deregistered(const std::string &profile_id);
  void subscribe_nf_status_profile_changed();
  void handle_nf_status_profile_changed(const std::string &profile_id);

  void get_subscription_list(const std::string &profile_id, uint8_t notification_type, std::vector<std::string> &uris);

 private:
  std::map<std::string, std::shared_ptr<nrf_profile>> instance_id2nrf_profile;
  mutable std::shared_mutex m_instance_id2nrf_profile;

  std::map<std::string, std::shared_ptr<nrf_subscription>> instance_id2nrf_subscription;
  mutable std::shared_mutex m_instance_id2nrf_subscription;
  nrf_event& m_event_sub;
  util::uint_generator<uint32_t> evsub_id_generator;
  std::vector<bs2::connection> connections;
};
}
}
}
#include "nrf_config.hpp"

#endif /* FILE_SMF_APP_HPP_SEEN */
