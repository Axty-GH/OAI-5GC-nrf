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

namespace oai {
namespace nrf {
class nrf_config;
class nrf_app {

 public:
  explicit nrf_app(const std::string &config_file);
  nrf_app(nrf_app const&) = delete;
  void operator=(nrf_app const&) = delete;

  void handle_nf_instance_registration_request(
      const std::string &nfInstanceID,
      oai::nrf::model::NFProfile &nf_profile,
      int &http_code,
      const uint8_t http_version);

};
}
}
#include "nrf_config.hpp"

#endif /* FILE_SMF_APP_HPP_SEEN */
