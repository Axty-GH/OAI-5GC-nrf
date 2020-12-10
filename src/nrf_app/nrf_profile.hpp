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

#include <arpa/inet.h>
#include <netinet/in.h>
#include <map>
#include <shared_mutex>
#include <memory>
#include <utility>
#include <vector>

#include "nrf.h"

namespace oai {
namespace nrf {
namespace app {

using namespace std;

class nrf_profile : public std::enable_shared_from_this<nrf_profile> {

 public:
  nrf_profile() = delete;
  nrf_profile(const nf_type_t type)
      :
      heartBeat_timer(0),
      snssais(),
      ipv4_addresses(),
      priority(0),
      capacity(0) {
    nf_type = type;
    nf_instance_name = "";
    nf_status = "";
  }

  nrf_profile(const std::string &id)
      :
      nf_instance_id(id),
      heartBeat_timer(0),
      snssais(),
      ipv4_addresses(),
      priority(0),
      capacity(0) {
    nf_instance_name = "";
    nf_status = "";
    nf_type = NF_TYPE_UNKNOWN;
  }

  nrf_profile(nrf_profile &b) = delete;

  /*
   * Set NF instance ID
   * @param [const std::string &] instance_id: instance id
   * @return void
   */
  void set_nf_instance_id(const std::string &instance_id);
  /*
   * Get NF instance ID
   * @param [std::string &] instance_id: store instance id
   * @return void:
   */
  void get_nf_instance_id(std::string &instance_id) const;

  /*
   * Set NF instance name
   * @param [const std::string &] instance_name: instance name
   * @return void
   */
  void set_nf_instance_name(const std::string &instance_name);
  /*
   * Get NF instance ID
   * @param [std::string &] instance_name: store instance name
   * @return void:
   */
  void get_nf_instance_name(std::string &instance_name) const;

  std::string get_nf_instance_name() const;
  /*
   * Set NF instance status
   * @param [const std::string &] status: instance status
   * @return void
   */
  void set_nf_status(const std::string &status);
  /*
   * Get NF instance status
   * @param [std::string &] status: store instance status
   * @return void:
   */
  void get_nf_status(std::string &status) const;
  std::string get_nf_status() const;

  nf_type_t get_nf_type() const;

  /*
   * Set NF instance heartBeat_timer
   * @param [const std::string &] timer: heartBeat_timer
   * @return void
   */
  void set_nf_heartBeat_timer(const int32_t &timer);
  /*
   * Get NF instance heartBeat_timer
   * @param [std::string &] timer: store heartBeat_timer
   * @return void:
   */
  void get_nf_hertBeat_timer(int32_t &timer) const;
  int32_t get_nf_hertBeat_timer() const;

  /*
   * Set NF instance priority
   * @param [const uint16_t] p: instance priority
   * @return void
   */
  void set_nf_priority(const uint16_t &p);
  /*
   * Get NF instance priority
   * @param [uint16_t] p: store instance priority
   * @return void:
   */
  void get_nf_priority(uint16_t &p) const;
  uint16_t get_nf_priority() const;
  /*
   * Set NF instance capacity
   * @param [const uint16_t] c: instance capacity
   * @return void
   */
  void set_nf_capacity(const uint16_t &c);
  /*
   * Get NF instance priority
   * @param [uint16_t ] c: store instance capacity
   * @return void:
   */
  void get_nf_capacity(uint16_t &c) const;
  uint16_t get_nf_capacity() const;
  /*
   * Set NF instance SNSSAIs
   * @param [std::vector<snssai_t> &] s: SNSSAIs
   * @return void
   */
  void set_nf_snssais(const std::vector<snssai_t> &s);

  /*
   * Add SNSSAI
   * @param [snssai_t &] s: SNSSAI
   * @return void
   */
  void add_snssai(const snssai_t &s);

  /*
   * Get NF instance SNSSAIs
   * @param [std::vector<snssai_t> &] s: store instance's SNSSAIs
   * @return void:
   */
  void get_nf_snssais(std::vector<snssai_t> &s) const;

  /*
   * Set NF instance ipv4_addresses
   * @param [std::vector<struct in_addr> &] a: ipv4_addresses
   * @return void
   */
  void set_nf_ipv4_addresses(const std::vector<struct in_addr> &a);
  void add_nf_ipv4_addresses(const struct in_addr &a);
  /*
   * Get NF instance ipv4_addresses
   * @param [std::vector<struct in_addr> &] a: store instance's ipv4_addresses
   * @return void:
   */
  void get_nf_ipv4_addresses(std::vector<struct in_addr> &a) const;

 protected:
  //From NFProfile (Section 6.1.6.2.2@3GPP TS 29.510 V16.0.0 (2019-06))
  std::string nf_instance_id;
  std::string nf_instance_name;
  nf_type_t nf_type;
  std::string nf_status;
  int32_t heartBeat_timer;
  std::vector<snssai_t> snssais;
  std::vector<struct in_addr> ipv4_addresses;
  uint16_t priority;
  uint16_t capacity;

  /*
   std::vector<PlmnId> m_PlmnList;
   bool m_PlmnListIsSet;
   std::vector<Snssai> m_SNssais;
   bool m_SNssaisIsSet;
   std::vector<PlmnSnssai> m_PerPlmnSnssaiList;
   bool m_PerPlmnSnssaiListIsSet;
   std::vector<std::string> m_NsiList;
   bool m_NsiListIsSet;
   std::string m_Fqdn;
   bool m_FqdnIsSet;
   std::vector<Ipv6Addr> m_Ipv6Addresses;
   bool m_Ipv6AddressesIsSet;
   int32_t m_Load;
   bool m_LoadIsSet;
   std::string m_Locality;
   bool m_LocalityIsSet;
   UdrInfo m_UdrInfo;
   bool m_UdrInfoIsSet;
   std::vector<UdrInfo> m_UdrInfoExt;
   bool m_UdrInfoExtIsSet;
   UdmInfo m_UdmInfo;
   bool m_UdmInfoIsSet;
   std::vector<UdmInfo> m_UdmInfoExt;
   bool m_UdmInfoExtIsSet;
   AusfInfo m_AusfInfo;
   bool m_AusfInfoIsSet;
   std::vector<AusfInfo> m_AusfInfoExt;
   bool m_AusfInfoExtIsSet;
   AmfInfo m_AmfInfo;
   bool m_AmfInfoIsSet;
   std::vector<AmfInfo> m_AmfInfoExt;
   bool m_AmfInfoExtIsSet;
   SmfInfo m_SmfInfo;
   bool m_SmfInfoIsSet;
   std::vector<SmfInfo> m_SmfInfoExt;
   bool m_SmfInfoExtIsSet;
   UpfInfo m_UpfInfo;
   bool m_UpfInfoIsSet;
   std::vector<UpfInfo> m_UpfInfoExt;
   bool m_UpfInfoExtIsSet;
   PcfInfo m_PcfInfo;
   bool m_PcfInfoIsSet;
   std::vector<PcfInfo> m_PcfInfoExt;
   bool m_PcfInfoExtIsSet;
   BsfInfo m_BsfInfo;
   bool m_BsfInfoIsSet;
   std::vector<BsfInfo> m_BsfInfoExt;
   bool m_BsfInfoExtIsSet;
   ChfInfo m_ChfInfo;
   bool m_ChfInfoIsSet;
   std::vector<ChfInfo> m_ChfInfoExt;
   bool m_ChfInfoExtIsSet;
   NwdafInfo m_NwdafInfo;
   bool m_NwdafInfoIsSet;
   std::string m_RecoveryTime;
   bool m_RecoveryTimeIsSet;
   bool m_NfServicePersistence;
   bool m_NfServicePersistenceIsSet;
   std::vector<NFService> m_NfServices;
   bool m_NfServicesIsSet;
   std::vector<DefaultNotificationSubscription> m_DefaultNotificationSubscriptions;
   bool m_DefaultNotificationSubscriptionsIsSet;
   */

};

class amf_profile : public nrf_profile {

 public:
  amf_profile()
      :
      nrf_profile(NF_TYPE_AMF) {
    amf_info = { };
  }

  amf_profile(const std::string &id)
      :
      nrf_profile(id) {
	  nf_type = NF_TYPE_AMF;
    amf_info = { };
  }

  amf_profile(amf_profile &b) = delete;

 private:
  std::vector<amf_info_t> amf_info;
};

}
}
}

#endif
