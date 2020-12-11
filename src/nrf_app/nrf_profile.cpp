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
#include "logger.hpp"

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

  Logger::nrf_app().debug("............AMF Set ID: %s, AMF Region ID: %s",
                          amf_info.amf_set_id.c_str(),
                          amf_info.amf_region_id.c_str());

  for (auto g : amf_info.guami_list) {
    Logger::nrf_app().debug("............AMF GUAMI, AMF_ID:  %s",
                            g.amf_id.c_str());
    Logger::nrf_app().debug("....................., PLMN (MCC: %s, MNC: %s)",
                            g.plmn.mcc.c_str(), g.plmn.mnc.c_str());
  }

}
