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

/*! \file nrf_profile.hpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: tien-thinh.nguyen@eurecom.fr
 */

#ifndef FILE_NRF_PROFILE_HPP_SEEN
#define FILE_NRF_PROFILE_HPP_SEEN

#include <map>
//#include <mutex>
#include <shared_mutex>
#include <memory>
#include <utility>
#include <vector>


namespace oai {
namespace nrf{

class nrf_profile : public std::enable_shared_from_this<nrf_profile> {

 public:
  nrf_profile()
  {
  }

  nrf_profile(nrf_profile &b) = delete;

 private:
  //lock
  mutable std::shared_mutex m_nrf_profile;

};
}
}

#endif
