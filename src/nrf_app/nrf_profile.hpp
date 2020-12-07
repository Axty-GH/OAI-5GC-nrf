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

  //From NFProfile (Section 6.1.6.2.2@3GPP TS 29.510 V16.0.0 (2019-06))
   std::string nf_instance_id;
   std::string nf_instance_name;
   std::string nf_type;
   std::string nf_status;


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
   std::vector<std::string> m_Ipv4Addresses;
   bool m_Ipv4AddressesIsSet;
   std::vector<Ipv6Addr> m_Ipv6Addresses;
   bool m_Ipv6AddressesIsSet;
   int32_t m_Capacity;
   bool m_CapacityIsSet;
   int32_t m_Load;
   bool m_LoadIsSet;
   std::string m_Locality;
   bool m_LocalityIsSet;
   int32_t m_Priority;
   bool m_PriorityIsSet;
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
}
}

#endif
