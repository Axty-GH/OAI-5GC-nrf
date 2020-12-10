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

/*! \file api_conversions.cpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: tien-thinh.nguyen@eurecom.fr
 */

#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include "api_conversions.hpp"
#include "string.hpp"
#include "nrf.h"
//#include "api_conversions.hpp"

#include "logger.hpp"

using namespace oai::nrf::model;
using namespace oai::nrf::app;
using namespace oai::nrf;
//------------------------------------------------------------------------------
/*
 bool api_conv::profile_api_to_amf_profile(const NFProfile &api_profile,
 std::shared_ptr<amf_profile> &profile) {

 Logger::nrf_app().debug(
 "Convert a NF profile generated from OpenAPI to an AMF profile (profile name %s)",
 api_profile.getNfInstanceName().c_str());
 profile.get()->set_nf_instance_name(api_profile.getNfInstanceName());
 Logger::nrf_app().debug("AMF profile, instance name %s",
 profile.get()->get_nf_instance_name().c_str());
 profile.get()->set_nf_status(api_profile.getNfStatus());
 Logger::nrf_app().debug("AMF profile, status %s",
 profile.get()->get_nf_status().c_str());
 profile.get()->set_nf_heartBeat_timer(api_profile.getHeartBeatTimer());
 Logger::nrf_app().debug("AMF profile, status %d",
 profile.get()->get_nf_hertBeat_timer());
 profile.get()->set_nf_priority(api_profile.getPriority());
 Logger::nrf_app().debug("AMF profile, priority %d",
 profile.get()->get_nf_priority());
 profile.get()->set_nf_capacity(api_profile.getCapacity());
 Logger::nrf_app().debug("AMF profile, capacity %d",
 profile.get()->get_nf_capacity());
 //SNSSAIs
 std::vector<Snssai> snssai = api_profile.getSNssais();
 for (auto s : snssai) {
 snssai_t sn = { };
 sn.sD = s.getSd();
 sn.sST = s.getSst();
 profile.get()->add_snssai(sn);
 Logger::nrf_app().debug("AMF profile, snssai %d, %s", sn.sST,
 sn.sD.c_str());
 }


 std::vector < std::string > ipv4_addr_str = api_profile.getIpv4Addresses();
 for (auto address : ipv4_addr_str) {
 struct in_addr addr4 = { };
 unsigned char buf_in_addr[sizeof(struct in_addr)];
 if (inet_pton(AF_INET, util::trim(address).c_str(), buf_in_addr) == 1) {
 memcpy(&addr4, buf_in_addr, sizeof(struct in_addr));
 } else {
 Logger::nrf_app().warn("NF IPv4 Addr conversion: Bad value %s",
 util::trim(address).c_str());
 }

 Logger::nrf_app().debug("AMF profile, IPv4 Addr %s", address.c_str());
 profile.get()->add_nf_ipv4_addresses(addr4);
 }

 return true;
 }
 */

bool api_conv::profile_api_to_amf_profile(
    const NFProfile &api_profile, std::shared_ptr<nrf_profile> &profile) {

  Logger::nrf_app().debug(
      "Convert a NF profile generated from OpenAPI to an AMF profile (profile name %s)",
      api_profile.getNfInstanceName().c_str());
  profile.get()->set_nf_instance_name(api_profile.getNfInstanceName());
  Logger::nrf_app().debug("NF profile, instance name %s",
                          profile.get()->get_nf_instance_name().c_str());
  profile.get()->set_nf_status(api_profile.getNfStatus());
  Logger::nrf_app().debug("NF profile, status %s",
                          profile.get()->get_nf_status().c_str());
  profile.get()->set_nf_heartBeat_timer(api_profile.getHeartBeatTimer());
  Logger::nrf_app().debug("NF profile, status %d",
                          profile.get()->get_nf_hertBeat_timer());
  profile.get()->set_nf_priority(api_profile.getPriority());
  Logger::nrf_app().debug("NF profile, priority %d",
                          profile.get()->get_nf_priority());
  profile.get()->set_nf_capacity(api_profile.getCapacity());
  Logger::nrf_app().debug("NF profile, capacity %d",
                          profile.get()->get_nf_capacity());
  //SNSSAIs
  std::vector<Snssai> snssai = api_profile.getSNssais();
  for (auto s : snssai) {
    snssai_t sn = { };
    sn.sD = s.getSd();
    sn.sST = s.getSst();
    profile.get()->add_snssai(sn);
    Logger::nrf_app().debug("NF profile, SNSSAI SD %d, SST %s", sn.sST,
                            sn.sD.c_str());
  }

  std::vector < std::string > ipv4_addr_str = api_profile.getIpv4Addresses();
  for (auto address : ipv4_addr_str) {
    struct in_addr addr4 = { };
    unsigned char buf_in_addr[sizeof(struct in_addr)];
    if (inet_pton(AF_INET, util::trim(address).c_str(), buf_in_addr) == 1) {
      memcpy(&addr4, buf_in_addr, sizeof(struct in_addr));
    } else {
      Logger::nrf_app().warn("NF IPv4, address conversion: Bad value %s",
                             util::trim(address).c_str());
    }

    Logger::nrf_app().debug("NF profile, IPv4 Addr %s", address.c_str());
    profile.get()->add_nf_ipv4_addresses(addr4);
  }

  if (api_profile.getNfType().compare("AMF") == 0) {
    Logger::nrf_app().debug("AMF profile, AMF Info");
    amf_info_t info = { };
    info.amf_region_id = "AMF_REGION_ID";
    info.amf_set_id = "AMF_SET_ID";
    (std::static_pointer_cast < amf_profile > (profile)).get()->add_amf_info(
        info);
  }

  return true;
}
