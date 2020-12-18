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

#ifndef FILE_3GPP_29_510_NRF_SEEN
#define FILE_3GPP_29_510_NRF_SEEN

#include "3gpp_23.003.h"

enum class nf_status_e { REGISTERED = 0, SUSPENDED = 1, UNDISCOVERABLE = 2 };

static const std::vector<std::string> nf_status_e2str = {
    "REGISTERED", "SUSPENDED", "UNDISCOVERABLE"};

enum subscription_condition_type {
  UNKNOWN_CONDITION = 0,
  NF_INSTANCE_ID_COND = 1,
  NF_TYPE_COND = 2,
  SERVICE_NAME_COND = 3,
  AMF_COND = 4,
  GUAMI_LIST_COND = 5,
  NETWOTK_SLICE_COND = 6,
  NF_GROUP_COND = 7
};

typedef struct amf_cond_s {
  std::string amf_set_id;
  std::string amf_region_id;
} amf_cond_t;

typedef struct network_slice_cond_s {
  std::vector<snssai_t> snssai_list;
  std::vector<std::string> nsi_list;
} network_slice_cond_t;

typedef struct nf_group_cond_s {
  std::string nf_type;

  std::string nf_group_id;
} nf_group_cond_t;

typedef struct subscription_condition_s {
  uint8_t type;
  union {
    std::string nf_instance_id;
    std::string nf_type;
    std::string service_name;
    amf_cond_t amf_info;
    std::vector<guami_t> guami_list;
    network_slice_cond_t network_slice;
    nf_group_cond_t nf_group;
  };

  subscription_condition_s() : type(0) {}

  subscription_condition_s(uint8_t t) : type(t) {}

  bool operator==(const struct subscription_condition_s &s) const {
    return (s.type == type);
  }

  bool operator==(const uint8_t &t) const { return (t == type); }

  virtual ~subscription_condition_s(){};

} subscription_condition_t;

#endif
