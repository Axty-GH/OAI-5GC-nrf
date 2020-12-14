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

/*! \file nrf_profile.cpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: tien-thinh.nguyen@eurecom.fr
 */

#include "nrf_profile.hpp"

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

#include "api_conversions.hpp"
#include "logger.hpp"
#include "string.hpp"

using namespace std;
using namespace oai::nrf::app;

//------------------------------------------------------------------------------
void nrf_profile::set_nf_instance_id(const std::string &instance_id) {
  nf_instance_id = instance_id;
}

//------------------------------------------------------------------------------
void nrf_profile::get_nf_instance_id(std::string &instance_id) const {
  instance_id = nf_instance_id;
}

//------------------------------------------------------------------------------
void nrf_profile::set_nf_instance_name(const std::string &instance_name) {
  nf_instance_name = instance_name;
}

//------------------------------------------------------------------------------
void nrf_profile::get_nf_instance_name(std::string &instance_name) const {
  instance_name = nf_instance_name;
}

//------------------------------------------------------------------------------
std::string nrf_profile::get_nf_instance_name() const {
  return nf_instance_name;
}

//------------------------------------------------------------------------------
void nrf_profile::set_nf_type(const nf_type_t &type) {
  nf_type = type;
}

//------------------------------------------------------------------------------
nf_type_t nrf_profile::get_nf_type() const {
  return nf_type;
}
//------------------------------------------------------------------------------
void nrf_profile::set_nf_status(const std::string &status) {
  nf_status = status;
}

//------------------------------------------------------------------------------
void nrf_profile::get_nf_status(std::string &status) const {
  status = nf_status;
}

//------------------------------------------------------------------------------
std::string nrf_profile::get_nf_status() const {
  return nf_status;
}

//------------------------------------------------------------------------------
void nrf_profile::set_nf_heartBeat_timer(const int32_t &timer) {
  heartBeat_timer = timer;
}

//------------------------------------------------------------------------------
void nrf_profile::get_nf_heartBeat_timer(int32_t &timer) const {
  timer = heartBeat_timer;
}

//------------------------------------------------------------------------------
int32_t nrf_profile::get_nf_heartBeat_timer() const {
  return heartBeat_timer;
}

//------------------------------------------------------------------------------
void nrf_profile::set_nf_priority(const uint16_t &p) {
  priority = p;
}

//------------------------------------------------------------------------------
void nrf_profile::get_nf_priority(uint16_t &p) const {
  p = priority;
}

//------------------------------------------------------------------------------
uint16_t nrf_profile::get_nf_priority() const {
  return priority;
}

//------------------------------------------------------------------------------
void nrf_profile::set_nf_capacity(const uint16_t &c) {
  capacity = c;
}

//------------------------------------------------------------------------------
void nrf_profile::get_nf_capacity(uint16_t &c) const {
  c = capacity;
}

//------------------------------------------------------------------------------
uint16_t nrf_profile::get_nf_capacity() const {
  return capacity;
}

//------------------------------------------------------------------------------
void nrf_profile::set_nf_snssais(const std::vector<snssai_t> &s) {
  snssais = s;
}

//------------------------------------------------------------------------------
void nrf_profile::get_nf_snssais(std::vector<snssai_t> &s) const {
  s = snssais;
}

//------------------------------------------------------------------------------
void nrf_profile::add_snssai(const snssai_t &s) {
  snssais.push_back(s);
}
//------------------------------------------------------------------------------
void nrf_profile::set_nf_ipv4_addresses(const std::vector<struct in_addr> &a) {
  ipv4_addresses = a;
}

//------------------------------------------------------------------------------
void nrf_profile::add_nf_ipv4_addresses(const struct in_addr &a) {
  ipv4_addresses.push_back(a);
}
//------------------------------------------------------------------------------
void nrf_profile::get_nf_ipv4_addresses(std::vector<struct in_addr> &a) const {
  a = ipv4_addresses;
}

//------------------------------------------------------------------------------
void nrf_profile::set_json_data(const nlohmann::json &data) {
  json_data = data;
}

//------------------------------------------------------------------------------
void nrf_profile::get_json_data(nlohmann::json &data) const {
  data = json_data;
}

//------------------------------------------------------------------------------
void nrf_profile::display() {

  Logger::nrf_app().debug("............Instance ID: %s",
                          nf_instance_id.c_str());

  Logger::nrf_app().debug("............Instance name: %s",
                          nf_instance_name.c_str());
  Logger::nrf_app().debug("............Instance type: %s",
                          nf_type_e2str[nf_type].c_str());
  Logger::nrf_app().debug("............Status: %s", nf_status.c_str());
  Logger::nrf_app().debug("............HeartBeat timer: %d", heartBeat_timer);
  Logger::nrf_app().debug("............Priority: %d", priority);
  Logger::nrf_app().debug("............Capacity: %d", capacity);
  //SNSSAIs
  for (auto s : snssais) {
    Logger::nrf_app().debug("............NNSSAI(SST, SD): %d, %s", s.sST,
                            s.sD.c_str());
  }

  //IPv4 Addresses
  for (auto address : ipv4_addresses) {
    Logger::nrf_app().debug("............IPv4 Addr: %s", inet_ntoa(address));
  }

  if (!json_data.empty()) {
    Logger::nrf_app().debug("............Json Data: %s",
                            json_data.dump().c_str());
  }
}

//------------------------------------------------------------------------------
bool nrf_profile::replace_profile_info(const std::string &path,
                                       const std::string &value) {

  Logger::nrf_app().debug("Replace member %s with new value %s", path.c_str(),
                          value.c_str());
  if (path.compare("nfInstanceName") == 0) {
    nf_instance_name = value;
    return true;
  }

  if (path.compare("nfStatus") == 0) {
    nf_status = value;
    return true;
  }

  if (path.compare("nfType") == 0) {
    nf_type = api_conv::string_to_nf_type(value);
    return true;
  }

  if (path.compare("heartBeatTimer") == 0) {
    try {
      heartBeat_timer = std::stoi(value);
      return true;
    } catch (const std::exception &err) {
      Logger::nrf_app().debug("Bad value!");
      return false;
    }
  }

  if (path.compare("priority") == 0) {
    try {
      priority = (uint16_t) std::stoi(value);
      return true;
    } catch (const std::exception &err) {
      Logger::nrf_app().debug("Bad value!");
      return false;
    }
  }

  if (path.compare("capacity") == 0) {
    try {
      capacity = (uint16_t) std::stoi(value);
      return true;
    } catch (const std::exception &err) {
      Logger::nrf_app().debug("Bad value!");
      return false;
    }
  }

  //Replace an array
  if (path.compare("ipv4Addresses") == 0) {
    Logger::nrf_app().info("Does not support this operation for ipv4Addresses");
    return false;
  }

  if (path.compare("sNssais") == 0) {
    Logger::nrf_app().info("Does not support this operation for sNssais");
    return false;
  }

  return false;
}

//------------------------------------------------------------------------------
bool nrf_profile::add_profile_info(const std::string &path,
                                   const std::string &value) {
  Logger::nrf_app().debug(
      "Add an array element (value, array member), or a new member (value, member):  %s, %s",
      value.c_str(), path.c_str());

  //update an existing member
  if (path.compare("nfInstanceName") == 0) {
    nf_instance_name = value;
    return true;
  }

  if (path.compare("nfStatus") == 0) {
    nf_status = value;
    return true;
  }

  if (path.compare("nfType") == 0) {
    nf_type = api_conv::string_to_nf_type(value);
    return true;
  }

  if (path.compare("heartBeatTimer") == 0) {
    try {
      heartBeat_timer = std::stoi(value);
      return true;
    } catch (const std::exception &err) {
      Logger::nrf_app().debug("Bad value!");
      return false;
    }
  }

  if (path.compare("priority") == 0) {
    try {
      priority = (uint16_t) std::stoi(value);
      return true;
    } catch (const std::exception &err) {
      Logger::nrf_app().debug("Bad value!");
      return false;
    }
  }

  if (path.compare("capacity") == 0) {
    try {
      capacity = (uint16_t) std::stoi(value);
      return true;
    } catch (const std::exception &err) {
      Logger::nrf_app().debug("Bad value!");
      return false;
    }
  }

  //add an element to a list
  if (path.compare("ipv4Addresses") == 0) {
    std::string address = value;
    struct in_addr addr4 = { };
    unsigned char buf_in_addr[sizeof(struct in_addr)];
    if (inet_pton(AF_INET, util::trim(address).c_str(), buf_in_addr) == 1) {
      memcpy(&addr4, buf_in_addr, sizeof(struct in_addr));
    } else {
      Logger::nrf_app().warn("Address conversion: Bad value %s",
                             util::trim(address).c_str());
      return false;
    }
    Logger::nrf_app().debug("Added IPv4 Addr: %s", address.c_str());
    ipv4_addresses.push_back(addr4);
    return true;
  }

  //add an element to a list of json object
  if (path.compare("sNssais") == 0) {
    Logger::nrf_app().info("Does not support this operation for snssais");
    return false;
  }

  return false;
}

//------------------------------------------------------------------------------
bool nrf_profile::remove_profile_info(
    const std::string &path) {

  Logger::nrf_app().debug("Remove an array element or a member: %s",
                          path.c_str());
  if (path.compare("nfInstanceName") == 0) {
    nf_instance_name = "";
    return true;
  }

  if (path.compare("nfStatus") == 0) {
    nf_status = "";
    return true;
  }

  if (path.compare("nfType") == 0) {
    nf_type = NF_TYPE_UNKNOWN;
    return true;
  }

  if (path.compare("heartBeatTimer") == 0) {
    heartBeat_timer = 0;
    return true;
  }

  if (path.compare("priority") == 0) {
    priority = 0;
    return true;
  }

  if (path.compare("capacity") == 0) {
    priority = 0;
    return true;
  }

  //path: e.g., /ipv4Addresses/4
  if (path.find("ipv4Addresses") != std::string::npos) {
    std::vector < std::string > parts;
    boost::split(parts, path, boost::is_any_of("/"), boost::token_compress_on);
    if (parts.size() != 2) {
      Logger::nrf_app().warn("Bad value for path: %s ", path.c_str());
      return false;
    }
    //get and check index
    uint32_t index = 0;
    try {
      index = std::stoi(parts.at(1));
    } catch (const std::exception &err) {
      Logger::nrf_app().warn("Bad value for path: %s ", path.c_str());
      return false;
    }

    if (index >= ipv4_addresses.size()) {
      Logger::nrf_app().warn("Bad value for path: %s ", path.c_str());
      return false;
    } else {
      Logger::nrf_app().debug("Removed IPv4 Addr: %s",
                              inet_ntoa(ipv4_addresses[index]));
      ipv4_addresses.erase(ipv4_addresses.begin() + index);
      return true;
    }
  }

  if (path.find("sNssais") != std::string::npos) {
    Logger::nrf_app().info("Does not support this operation for snssais");
    return false;
  }

  Logger::nrf_app().debug("Member (%s) not found!", path.c_str());
  return false;
}

//------------------------------------------------------------------------------
void nrf_profile::to_json(nlohmann::json &data) const {

  data["nfInstanceId"] = nf_instance_id;
  data["nfInstanceName"] = nf_instance_name;
  data["nfType"] = nf_type_e2str[nf_type];
  data["nfStatus"] = nf_status;
  data["heartBeatTimer"] = heartBeat_timer;
  //SNSSAIs
  data["sNssais"] = nlohmann::json::array();
  for (auto s : snssais) {
    nlohmann::json tmp = { };
    tmp["sst"] = s.sST;
    tmp["sd"] = s.sD;
    ;
    data["sNssais"].push_back(tmp);
  }
  //ipv4_addresses
  data["ipv4Addresses"] = nlohmann::json::array();
  for (auto address : ipv4_addresses) {
    nlohmann::json tmp = inet_ntoa(address);
    data["ipv4Addresses"].push_back(tmp);
  }

  data["priority"] = priority;
  data["capacity"] = capacity;
  data["json_data"] = json_data;
}


//------------------------------------------------------------------------------
void nrf_profile::subscribe_task_tick(uint64_t ms) {

  struct itimerspec its;
  its.it_value.tv_sec = 10;  //seconds
  its.it_value.tv_nsec = 0;  //100 * 1000 * 1000; //100ms

  const uint64_t interval = its.it_value.tv_sec * 1000
      + its.it_value.tv_nsec / 1000000;  // convert sec, nsec to msec

      //uint64_t interval =10;
      // m_event_sub.subscribe_task_tick(
      //     boost::bind<void>(&nrf_app::handle_heartbeart_timeout, _1), interval, 0 /* start at time 0 */);

  Logger::nrf_app().debug("subscribe_task_tick2 %d", ms);
  m_event_sub.subscribe_task_tick(
      boost::bind(&nrf_profile::handle_heartbeart_timeout, this, _1), interval,
      ms % 10000 /* start at time 0 */);

}

//------------------------------------------------------------------------------
void nrf_profile::handle_heartbeart_timeout(uint64_t ms) {
  Logger::nrf_app().info("NRF PROFILE handle_heartbeart_timeout1 %d, PROFILE ID %s", ms, nf_instance_id.c_str());
}


//------------------------------------------------------------------------------
void amf_profile::add_amf_info(const amf_info_t &info) {
  amf_info = info;
}

//------------------------------------------------------------------------------
void amf_profile::get_amf_info(amf_info_t &infos) const {
  infos = amf_info;
}

//------------------------------------------------------------------------------
void amf_profile::display() {

  nrf_profile::display();
  Logger::nrf_app().debug("............AMF Info");
  Logger::nrf_app().debug(
      ".....................AMF Set ID: %s, AMF Region ID: %s",
      amf_info.amf_set_id.c_str(), amf_info.amf_region_id.c_str());

  for (auto g : amf_info.guami_list) {
    Logger::nrf_app().debug(".....................AMF GUAMI List, AMF_ID:  %s",
                            g.amf_id.c_str());
    Logger::nrf_app().debug(
        "........................AMF GUAMI List, PLMN (MCC: %s, MNC: %s)",
        g.plmn.mcc.c_str(), g.plmn.mnc.c_str());
  }
}

//------------------------------------------------------------------------------
bool amf_profile::replace_profile_info(const std::string &path,
                                       const std::string &value) {

  bool result = nrf_profile::replace_profile_info(path, value);
  if (result)
    return true;
  //for AMF info
  if (path.compare("amfInfo") == 0) {
    Logger::nrf_app().debug("Does not support this operation for amfInfo");
    return false;
  }

  if ((path.compare("nfInstanceId") != 0)
      and (path.compare("nfInstanceName") != 0)
      and (path.compare("nfType") != 0) and (path.compare("nfStatus") != 0)
      and (path.compare("heartBeatTimer") != 0)
      and (path.compare("sNssais") != 0)
      and (path.compare("ipv4Addresses") != 0)
      and (path.compare("priority") != 0) and (path.compare("capacity") != 0)
      and (path.compare("priority") != 0) and (path.compare("amfInfo") != 0)) {
    Logger::nrf_app().debug("Member (%s) not found!", path.c_str());
    return false;
  }

  return false;
}

//------------------------------------------------------------------------------
bool amf_profile::add_profile_info(const std::string &path,
                                   const std::string &value) {
  bool result = nrf_profile::add_profile_info(path, value);
  if (result)
    return true;

  //add an element to a list of json object
  if (path.compare("amfInfo") == 0) {
    Logger::nrf_app().info("Does not support this operation for amfInfo");
    return false;
  }

  if ((path.compare("nfInstanceId") != 0)
      and (path.compare("nfInstanceName") != 0)
      and (path.compare("nfType") != 0) and (path.compare("nfStatus") != 0)
      and (path.compare("heartBeatTimer") != 0)
      and (path.compare("sNssais") != 0)
      and (path.compare("ipv4Addresses") != 0)
      and (path.compare("priority") != 0) and (path.compare("capacity") != 0)
      and (path.compare("priority") != 0) and (path.compare("amfInfo") != 0)) {
    Logger::nrf_app().debug("Add new member: %s", path.c_str());
    //add new member
    json_data[path] = value;
    return true;
  }

  return false;
}

//------------------------------------------------------------------------------
bool amf_profile::remove_profile_info(
    const std::string &path) {

  bool result = nrf_profile::remove_profile_info(path);
  if (result)
    return true;
  //for AMF info
  if (path.compare("amfInfo") == 0) {
    Logger::nrf_app().debug("Does not support this operation for amfInfo");
    return false;
  }

  if ((path.compare("nfInstanceId") != 0)
      and (path.compare("nfInstanceName") != 0)
      and (path.compare("nfType") != 0) and (path.compare("nfStatus") != 0)
      and (path.compare("heartBeatTimer") != 0)
      and (path.compare("sNssais") != 0)
      and (path.compare("ipv4Addresses") != 0)
      and (path.compare("priority") != 0) and (path.compare("capacity") != 0)
      and (path.compare("priority") != 0) and (path.compare("amfInfo") != 0)) {
    Logger::nrf_app().debug("Member (%s) not found!", path.c_str());
    return false;
  }

  return false;

}

//------------------------------------------------------------------------------
void amf_profile::to_json(nlohmann::json &data) const {
  nrf_profile::to_json(data);
  Logger::nrf_app().debug("[AMF] To Json");
  //AMF Info
  data["amfInfo"]["amfSetId"] = amf_info.amf_set_id;
  data["amfInfo"]["amfRegionId"] = amf_info.amf_region_id;
  //guamiList
  data["amfInfo"]["guamiList"] = nlohmann::json::array();
  for (auto guami : amf_info.guami_list) {
    nlohmann::json tmp = { };
    tmp["amfId"] = guami.amf_id;
    tmp["plmnId"]["mnc"] = guami.plmn.mnc;
    tmp["plmnId"]["mcc"] = guami.plmn.mcc;
    data["amfInfo"]["guamiList"].push_back(tmp);
  }
}

//------------------------------------------------------------------------------
void smf_profile::add_smf_info(const smf_info_t &info) {
  smf_info = info;
}

//------------------------------------------------------------------------------
void smf_profile::get_smf_info(smf_info_t &infos) const {
  infos = smf_info;
}

//------------------------------------------------------------------------------
void smf_profile::display() {

  nrf_profile::display();

  Logger::nrf_app().debug("............SMF Info");

  for (auto s : smf_info.snssai_smf_info_list) {
    Logger::nrf_app().debug(
        "....................SNSSAI SMF Info List, SNSSAI (SD: %s, SST: %d)",
        s.snssai.sD.c_str(), s.snssai.sST);
    for (auto d : s.dnn_smf_info_list) {
      Logger::nrf_app().debug(
          "....................SNSSAI SMF Info List, DNN List: %s",
          d.dnn.c_str());
    }
  }
}

//------------------------------------------------------------------------------
bool smf_profile::add_profile_info(
    const std::string &path, const std::string &value) {
  bool result = nrf_profile::add_profile_info(path, value);
  if (result)
    return true;

  //add an element to a list of json object
  if (path.compare("smfInfo") == 0) {
    Logger::nrf_app().info("Does not support this operation for smfInfo");
    return false;
  }

  if ((path.compare("nfInstanceId") != 0)
      and (path.compare("nfInstanceName") != 0)
      and (path.compare("nfType") != 0) and (path.compare("nfStatus") != 0)
      and (path.compare("heartBeatTimer") != 0)
      and (path.compare("sNssais") != 0)
      and (path.compare("ipv4Addresses") != 0)
      and (path.compare("priority") != 0) and (path.compare("capacity") != 0)
      and (path.compare("priority") != 0) and (path.compare("smfInfo") != 0)) {
    Logger::nrf_app().debug("Add new member: %s", path.c_str());
    //add new member
    json_data[path] = value;
    return true;
  }

  return false;
}

//------------------------------------------------------------------------------
bool smf_profile::replace_profile_info(const std::string &path,
                                       const std::string &value) {

  bool result = nrf_profile::replace_profile_info(path, value);
  if (result)
    return true;
  //for SMF info
  if (path.compare("smfInfo") == 0) {
    Logger::nrf_app().debug("Does not support this operation for amfInfo");
    return false;
  }

  if ((path.compare("nfInstanceId") != 0)
      and (path.compare("nfInstanceName") != 0)
      and (path.compare("nfType") != 0) and (path.compare("nfStatus") != 0)
      and (path.compare("heartBeatTimer") != 0)
      and (path.compare("sNssais") != 0)
      and (path.compare("ipv4Addresses") != 0)
      and (path.compare("priority") != 0) and (path.compare("capacity") != 0)
      and (path.compare("priority") != 0) and (path.compare("amfInfo") != 0)) {
    Logger::nrf_app().debug("Member (%s) not found!", path.c_str());
    return false;
  }

  return false;
}

//------------------------------------------------------------------------------
bool smf_profile::remove_profile_info(
    const std::string &path) {
  bool result = nrf_profile::remove_profile_info(path);
  if (result)
    return true;
  //for SMF info
  if (path.compare("smfInfo") == 0) {
    Logger::nrf_app().debug("Does not support this operation for smfInfo");
    return false;
  }

  if ((path.compare("nfInstanceId") != 0)
      and (path.compare("nfInstanceName") != 0)
      and (path.compare("nfType") != 0) and (path.compare("nfStatus") != 0)
      and (path.compare("heartBeatTimer") != 0)
      and (path.compare("sNssais") != 0)
      and (path.compare("ipv4Addresses") != 0)
      and (path.compare("priority") != 0) and (path.compare("capacity") != 0)
      and (path.compare("priority") != 0) and (path.compare("smfInfo") != 0)) {
    Logger::nrf_app().debug("Member (%s) not found!", path.c_str());
    return false;
  }

  return false;
}

//------------------------------------------------------------------------------
void smf_profile::to_json(nlohmann::json &data) const {
  nrf_profile::to_json(data);
  //SMF Info
  data["smfInfo"]["sNssaiSmfInfoList"] = nlohmann::json::array();
  for (auto snssai : smf_info.snssai_smf_info_list) {
    nlohmann::json tmp = { };
    tmp["sNssai"]["sst"] = snssai.snssai.sST;
    tmp["sNssai"]["sd"] = snssai.snssai.sD;
    tmp["dnnSmfInfoList"] = nlohmann::json::array();
    for (auto d : snssai.dnn_smf_info_list) {
      nlohmann::json tmp_dnn = { };
      tmp_dnn["dnn"] = d.dnn;
      tmp["dnnSmfInfoList"].push_back(tmp_dnn);
    }
    data["smfInfo"]["sNssaiSmfInfoList"].push_back(tmp);
  }
}
