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

/*! \file nrf_jwt.cpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: tien-thinh.nguyen@eurecom.fr
 */

#include "nrf_jwt.hpp"

#include <iostream>

#include "jwt/jwt.hpp"

using namespace oai::nrf::app;

//------------------------------------------------------------------------------
bool nrf_jwt::generate_signature(const std::string &nf_consumer_id,
                                 std::string &signature) const {
  std::string key;
  get_secret_key(nf_consumer_id, key);
  // Create JWT object
  //TODO
  jwt::jwt_object obj{jwt::params::algorithm("HS256"),
                      jwt::params::payload({{"iss", "nrf_instance_id"},
                                            {"sub", "nf_consumer_id"},
                                            {"aud", "nf_producer_id"},
                                            {"scope", "nf_producer_name"},
                                            {"exp", "100"}}),
                      jwt::params::secret(key)};

  // Get the encoded string/assertion
  signature = obj.signature();
}

//------------------------------------------------------------------------------
bool nrf_jwt::get_secret_key(const std::string &nf_consumer_id,
                             std::string &key) const {
  // TODO:
  key = "secret";
}

//------------------------------------------------------------------------------
void nrf_jwt::test_jwt() {
  using namespace jwt::params;

  auto key = "secret";  // Secret to use for the algorithm
  // Create JWT object
  jwt::jwt_object obj{algorithm("HS256"), payload({{"some", "payload"}}),
                      secret(key)};

  // Get the encoded string/assertion
  auto enc_str = obj.signature();
  std::cout << enc_str << std::endl;

  // Decode
  auto dec_obj = jwt::decode(enc_str, algorithms({"HS256"}), secret(key));
  std::cout << dec_obj.header() << std::endl;
  std::cout << dec_obj.payload() << std::endl;
}
