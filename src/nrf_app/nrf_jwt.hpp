/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the
 * License at
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

/*! \file nrf_jwt.hpp
 * \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: tien-thinh.nguyen@eurecom.fr
 */

#ifndef FILE_NRF_JWT_HPP_SEEN
#define FILE_NRF_JWT_HPP_SEEN

#include <string>

namespace oai {
namespace nrf {
namespace app {

class nrf_jwt {
 private:
 public:
  void test_jwt();
  bool generate_signature(const std::string &nf_consumer_id,
                          std::string &signature) const;
  bool get_secret_key(const std::string &nf_consumer_id,
                      std::string &key) const;
};

}  // namespace app
}  // namespace nrf
}  // namespace oai

#endif /* FILE_NRF_JWT_HPP_SEEN */
