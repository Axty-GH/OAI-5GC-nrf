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
#include <regex>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

#include "AmfInfo.h"
#include "api_conversions.hpp"
#include "logger.hpp"
#include "nrf.h"
#include "string.hpp"

using namespace oai::nrf::model;
using namespace oai::nrf::app;
using namespace oai::nrf;

//------------------------------------------------------------------------------
bool api_conv::profile_api_to_amf_profile(
    const NFProfile &api_profile, std::shared_ptr<nrf_profile> &profile) {

  Logger::nrf_app().debug(
      "Convert a json-type profile a NF profile (profile ID: %s)",
      api_profile.getNfInstanceId().c_str());

  profile.get()->set_nf_instance_id(api_profile.getNfInstanceId());
  profile.get()->set_nf_instance_name(api_profile.getNfInstanceName());
  Logger::nrf_app().debug("............Instance name: %s",
                          profile.get()->get_nf_instance_name().c_str());

  profile.get()->set_nf_status(api_profile.getNfStatus());
  Logger::nrf_app().debug("............Status: %s",
                          profile.get()->get_nf_status().c_str());
  profile.get()->set_nf_heartBeat_timer(api_profile.getHeartBeatTimer());
  Logger::nrf_app().debug("............HeartBeart timer: %d",
                          profile.get()->get_nf_heartBeat_timer());
  profile.get()->set_nf_priority(api_profile.getPriority());
  Logger::nrf_app().debug("............Priority: %d",
                          profile.get()->get_nf_priority());
  profile.get()->set_nf_capacity(api_profile.getCapacity());
  Logger::nrf_app().debug("............Capacity: %d",
                          profile.get()->get_nf_capacity());
  //SNSSAIs
  std::vector<Snssai> snssai = api_profile.getSNssais();
  for (auto s : snssai) {
    snssai_t sn = { };
    sn.sD = s.getSd();
    sn.sST = s.getSst();
    profile.get()->add_snssai(sn);
    Logger::nrf_app().debug("............SNSSAI (SD, SST): %d, %s", sn.sST,
                            sn.sD.c_str());
  }

  std::vector < std::string > ipv4_addr_str = api_profile.getIpv4Addresses();
  for (auto address : ipv4_addr_str) {
    struct in_addr addr4 = { };
    unsigned char buf_in_addr[sizeof(struct in_addr)];
    if (inet_pton(AF_INET, util::trim(address).c_str(), buf_in_addr) == 1) {
      memcpy(&addr4, buf_in_addr, sizeof(struct in_addr));
    } else {
      Logger::nrf_app().warn("Address conversion: Bad value %s",
                             util::trim(address).c_str());
    }

    Logger::nrf_app().debug("............IPv4 Addr: %s", address.c_str());
    profile.get()->add_nf_ipv4_addresses(addr4);
  }

  nf_type_t nf_type = string_to_nf_type(api_profile.getNfType());

  switch (nf_type) {
    case NF_TYPE_AMF: {
      Logger::nrf_app().debug("............AMF profile, AMF Info");
      profile.get()->set_nf_type(NF_TYPE_AMF);
      amf_info_t info = { };
      AmfInfo amf_info_api = api_profile.getAmfInfo();
      info.amf_region_id = amf_info_api.getAmfRegionId();
      info.amf_set_id = amf_info_api.getAmfSetId();

      Logger::nrf_app().debug("............AMF Set ID: %s, AMF Region ID: %s",
                              info.amf_set_id.c_str(),
                              info.amf_region_id.c_str());

      for (auto g : amf_info_api.getGuamiList()) {
        guami_t guami = { };
        guami.amf_id = g.getAmfId();
        guami.plmn.mcc = g.getPlmnId().getMcc();
        guami.plmn.mnc = g.getPlmnId().getMnc();
        info.guami_list.push_back(guami);
        Logger::nrf_app().debug("............AMF GUAMI, AMF_ID:  %s",
                                guami.amf_id.c_str());
        Logger::nrf_app().debug(
            "....................., PLMN (MCC: %s, MNC: %s)",
            guami.plmn.mcc.c_str(), guami.plmn.mnc.c_str());

      }
      (std::static_pointer_cast < amf_profile > (profile)).get()->add_amf_info(
          info);
    }
      break;
    case NF_TYPE_SMF: {

    }
      break;
    default: {

    }

  }

  return true;
}

//------------------------------------------------------------------------------
nf_type_t api_conv::string_to_nf_type(const std::string &str) {
  if (str.compare("NRF") == 0)
    return NF_TYPE_NRF;
  if (str.compare("AMF") == 0)
    return NF_TYPE_AMF;
  if (str.compare("SMF") == 0)
    return NF_TYPE_SMF;
  if (str.compare("AUSF") == 0)
    return NF_TYPE_AUSF;
  if (str.compare("NEF") == 0)
    return NF_TYPE_NEF;
  if (str.compare("PCP") == 0)
    return NF_TYPE_PCF;
  if (str.compare("SMSF") == 0)
    return NF_TYPE_SMSF;
  if (str.compare("NSSF") == 0)
    return NF_TYPE_NSSF;
  if (str.compare("UDR") == 0)
    return NF_TYPE_UDR;
  if (str.compare("LMF") == 0)
    return NF_TYPE_LMF;
  if (str.compare("GMLC") == 0)
    return NF_TYPE_GMLC;
  if (str.compare("5G_EIR") == 0)
    return NF_TYPE_5G_EIR;
  if (str.compare("SEPP") == 0)
    return NF_TYPE_SEPP;
  if (str.compare("UPF") == 0)
    return NF_TYPE_UPF;
  if (str.compare("N3IWF") == 0)
    return NF_TYPE_N3IWF;
  if (str.compare("AF") == 0)
    return NF_TYPE_AF;
  if (str.compare("UDSF") == 0)
    return NF_TYPE_UDSF;
  if (str.compare("BSF") == 0)
    return NF_TYPE_BSF;
  if (str.compare("CHF") == 0)
    return NF_TYPE_CHF;
  if (str.compare("NWDAF") == 0)
    return NF_TYPE_NWDAF;
  //default
  return NF_TYPE_UNKNOWN;
}

//------------------------------------------------------------------------------
patch_op_type_t api_conv::string_to_patch_operation(const std::string &str) {
  if (str.compare("add") == 0)
    return PATCH_OP_ADD;
  if (str.compare("copy") == 0)
    return PATCH_OP_COPY;
  if (str.compare("move") == 0)
    return PATCH_OP_MOVE;
  if (str.compare("remove") == 0)
    return PATCH_OP_REMOVE;
  if (str.compare("replace") == 0)
    return PATCH_OP_REPLACE;
  if (str.compare("test") == 0)
    return PATCH_OP_TEST;
  //default
  return PATCH_OP_UNKNOWN;
}


bool api_conv::validate_uuid(const std::string &str) {
  //should be verified with Capital letter
  static const std::regex e("[a-f0-9]{8}-[a-f0-9]{4}-4[a-f0-9]{3}-[89aAbB][a-f0-9]{3}-[a-f0-9]{12}");
    return regex_match(str, e);
}
