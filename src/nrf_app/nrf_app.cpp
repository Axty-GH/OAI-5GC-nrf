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

using namespace oai::nrf;

extern nrf_app *nrf_app_inst;
extern nrf_config nrf_cfg;

//------------------------------------------------------------------------------
nrf_app::nrf_app(const std::string &config_file) {
  Logger::nrf_app().startup("Starting...");
  Logger::nrf_app().startup("Started");
}

//------------------------------------------------------------------------------
void nrf_app::handle_nf_instance_registration_request(
    const std::string &nf_instance_id, oai::nrf::model::NFProfile &nf_profile,
    int &http_code, const uint8_t http_version) {

  Logger::nrf_app().info(
      "Handle a NF Instance Registration Request (HTTP version %d)",
      http_version);
  //Check if nfInstanceID is a valid UUID (version 4)
  //TODO

  //Create NF and store
  std::shared_ptr<amf_profile> sa = { };
  if (find_nf_profile(nf_instance_id, sa)) {
    //if a profile exist with this ID, return error
  } else {
    //create
    Logger::nrf_app().debug("Create a new NF Profile with ID %s",
                            nf_instance_id);
    sa = std::shared_ptr < amf_profile > (new amf_profile(nf_instance_id));
    //sa.get()->
    add_nf_profile(nf_instance_id, sa);
  }

  //location header - URI of created resource: can be used with ID - UUID

}

//------------------------------------------------------------------------------
bool nrf_app::add_nf_profile(const std::string &profile_id,
                             const std::shared_ptr<nrf_profile> &p) {
  return true;
}

//------------------------------------------------------------------------------
bool nrf_app::find_nf_profile(const std::string &profile_id,
                              const std::shared_ptr<nrf_profile> &snp) {
  //TODO
  return true;

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

