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

#ifndef FILE_NRF_SEEN
#define FILE_NRF_SEEN
#include "3gpp_23.003.h"

#define HEART_BEAT_TIMER 10

typedef enum nf_type_s {
  NF_TYPE_NRF = 0,
  NF_TYPE_AMF = 1,
  NF_TYPE_SMF = 2,
  NF_TYPE_AUSF = 3,
  NF_TYPE_NEF = 4,
  NF_TYPE_PCF = 5,
  NF_TYPE_SMSF = 6,
  NF_TYPE_NSSF = 7,
  NF_TYPE_UDR = 8,
  NF_TYPE_LMF = 9,
  NF_TYPE_GMLC = 10,
  NF_TYPE_5G_EIR = 11,
  NF_TYPE_SEPP = 12,
  NF_TYPE_UPF = 13,
  NF_TYPE_N3IWF = 14,
  NF_TYPE_AF = 15,
  NF_TYPE_UDSF = 16,
  NF_TYPE_BSF = 17,
  NF_TYPE_CHF = 18,
  NF_TYPE_NWDAF = 19,
  NF_TYPE_UNKNOWN = 20
} nf_type_t;

static const std::vector<std::string> nf_type_e2str = { "NF_TYPE_NRF",
    "NF_TYPE_AMF", "NF_TYPE_SMF", "NF_TYPE_AUSF", "NF_TYPE_NEF", "NF_TYPE_PCF",
    "NF_TYPE_SMSF", "NF_TYPE_NSSF", "NF_TYPE_UDR", "NF_TYPE_LMF",
    "NF_TYPE_GMLC", "NF_TYPE_5G_EIR", "NF_TYPE_SEPP", "NF_TYPE_UPF",
    "NF_TYPE_N3IWF", "NF_TYPE_AF", "NF_TYPE_UDSF", "NF_TYPE_BSF", "NF_TYPE_CHF",
    "NF_TYPE_NWDAF", "NF_TYPE_UNKNOWN" };

typedef struct s_nssai  // section 28.4, TS23.003
{
  uint8_t sST;
  //uint32_t sD:24;
  std::string sD;
  //s_nssai(const uint8_t& sst,  const uint32_t sd) : sST(sst), sD(sd) {}
  s_nssai(const uint8_t &sst, const std::string sd)
      :
      sST(sst),
      sD(sd) {
  }
  s_nssai()
      :
      sST(),
      sD() {
  }
  s_nssai(const s_nssai &p)
      :
      sST(p.sST),
      sD(p.sD) {
  }
  bool operator==(const struct s_nssai &s) const {
    if ((s.sST == this->sST) && (s.sD.compare(this->sD) == 0)) {
      return true;
    } else {
      return false;
    }
  }

} snssai_t;

typedef struct guami_s {
  plmn_t plmn;
  std::string amf_id;
} guami_t;

typedef struct amf_info_s {
  std::string amf_set_id;
  std::string amf_region_id;
  std::vector<guami_t> guami_list;
} amf_info_t;

#endif
