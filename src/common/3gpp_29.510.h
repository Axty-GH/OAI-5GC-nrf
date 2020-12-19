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

#include <string>
#include "3gpp_23.003.h"

enum class nf_status_e { REGISTERED = 0, SUSPENDED = 1, UNDISCOVERABLE = 2 };

static const std::vector<std::string> nf_status_e2str = {
    "REGISTERED", "SUSPENDED", "UNDISCOVERABLE"};

enum subscr_condition_type_e { //TODO: use enum class
  UNKNOWN_CONDITION = 0,
  NF_INSTANCE_ID_COND = 1,
  NF_TYPE_COND = 2,
  SERVICE_NAME_COND = 3,
  AMF_COND = 4,
  GUAMI_LIST_COND = 5,
  NETWOTK_SLICE_COND = 6,
  NF_GROUP_COND = 7
};

static const std::vector<std::string> subscription_condition_type_e2str = {
    "UNKNOWN_CONDITION",  "NF_INSTANCE_ID_COND",
    "NF_TYPE_COND",       "SERVICE_NAME_COND",
    "AMF_COND",           "GUAMI_LIST_COND",
    "NETWOTK_SLICE_COND", "NF_GROUP_COND"};

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

  subscription_condition_s() : type(0), nf_instance_id() {}

  subscription_condition_s(uint8_t t) : type(t) {}

  subscription_condition_s(const subscription_condition_s &s)
      : subscription_condition_s() {
    type = s.type;
    switch (s.type) {
      case NF_INSTANCE_ID_COND: {
        nf_instance_id = s.nf_instance_id;
      } break;
      case NF_TYPE_COND: {
        nf_type = s.nf_type;
      } break;

      case SERVICE_NAME_COND: {
        service_name = s.service_name;
      } break;
      case AMF_COND: {
        amf_info.amf_set_id = s.amf_info.amf_set_id;
        amf_info.amf_region_id = s.amf_info.amf_region_id;
      } break;

      case GUAMI_LIST_COND: {
        // TODO:
      } break;

      case NETWOTK_SLICE_COND: {
        // TODO:
      } break;

      case NF_GROUP_COND: {
        // TODO:
      } break;

      default: {
        // TODO:
      }
    }
    // TODO:
  }
  bool operator==(const struct subscription_condition_s &s) const {
    return (s.type == type);
  }

  bool operator==(const uint8_t &t) const { return (t == type); }

  subscription_condition_s &operator=(const subscription_condition_s &s) {
    type = s.type;
    switch (s.type) {
      case NF_INSTANCE_ID_COND: {
        nf_instance_id = s.nf_instance_id;
      } break;
      case NF_TYPE_COND: {
        nf_type = s.nf_type;
      } break;

      case SERVICE_NAME_COND: {
        service_name = s.service_name;
      } break;
      case AMF_COND: {
        amf_info.amf_set_id = s.amf_info.amf_set_id;
        amf_info.amf_region_id = s.amf_info.amf_region_id;
      } break;

      case GUAMI_LIST_COND: {
        // TODO:
      } break;

      case NETWOTK_SLICE_COND: {
        // TODO:
      } break;

      case NF_GROUP_COND: {
        // TODO:
      } break;

      default: {
        // TODO:
      }
    }
    // TODO:
  }

  virtual ~subscription_condition_s(){};

} subscription_condition_t;

enum notification_event_type_t {
  NOTIFICATION_TYPE_NF_REGISTERED = 0,
  NOTIFICATION_TYPE_NF_DEREGISTERED = 1,
  NOTIFICATION_TYPE_NF_PROFILE_CHANGED = 2
};

#endif
