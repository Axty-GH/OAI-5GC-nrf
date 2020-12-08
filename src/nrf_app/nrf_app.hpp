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
 \email: tien-thinh.nguyen@eurecom.fr
 */

#ifndef FILE_NRF_APP_HPP_SEEN
#define FILE_NRF_APP_HPP_SEEN

#include <string>
#include "NFProfile.h"
#include "nrf_profile.hpp"

namespace oai {
namespace nrf {
class nrf_config;
class nrf_app {

 public:
  explicit nrf_app(const std::string &config_file);
  nrf_app(nrf_app const&) = delete;
  void operator=(nrf_app const&) = delete;

  void handle_nf_instance_registration_request(
      const std::string &nf_instance_id,
      oai::nrf::model::NFProfile &nf_profile,
      int &http_code,
      const uint8_t http_version);

  /*
   * Insert a nrf profile
   * @param [const std::string &] profile_id: Profile ID
   * @param [std::shared_ptr<nrf_profile> &] p: profile to be added
   * @return true if successful, otherwise, return false
   */
  bool add_nf_profile(const std::string &profile_id, const std::shared_ptr<nrf_profile> &p);

  /*
   * Find a nf profile with its ID
   * @param [const std::string &] profile_id: Profile ID
   * @param [std::shared_ptr<nrf_profile> &] snp: Stored nf profile if found
   * @return void
   */
  bool find_nf_profile(const std::string &profile_id,
                      const std::shared_ptr<nrf_profile> &snp);

  /*
   * Remove a nf profile from the list
   * @param [std::shared_ptr<nrf_profile> &] snp: profile to be removed
   * @return true if successful, otherwise, return false
   */
  bool remove_nf_profile(std::shared_ptr<nrf_profile> &snp);

  /*
   * Remove a nf profile from the list
   * @param [std::string &] profile_id: ID of the profile to be removed
   * @return true if successful, otherwise, return false
   */
  bool remove_nf_profile(std::string &profile_id);


 private:
  std::map<std::string, std::shared_ptr<nrf_profile>> instance_id2nrf_profile;
  mutable std::shared_mutex m_instance_id2nrf_profile;
};
}
}
#include "nrf_config.hpp"

#endif /* FILE_SMF_APP_HPP_SEEN */
