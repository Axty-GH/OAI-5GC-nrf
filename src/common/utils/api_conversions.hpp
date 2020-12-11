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

/*! \file api_conversions.hpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: tien-thinh.nguyen@eurecom.fr
 */

#ifndef FILE_API_CONVERSIONS_HPP_SEEN
#define FILE_API_CONVERSIONS_HPP_SEEN

#include "NFProfile.h"
#include "nrf_profile.hpp"
#include "nrf.h"

using namespace oai::nrf::model;
using namespace oai::nrf::app;

namespace oai {
namespace nrf {
namespace api_conv {

/*
 * Convert a json-type profile to a NF profile
 * @param [const NFProfile &] NFProfile: Json-type profile from OpenAPITool
 * @param [std::shared_ptr<nrf_profile> &] profile: NF profile
 * @return true if successful, otherwise, return false
 */
bool profile_api_to_amf_profile(const NFProfile &api_profile,
                                std::shared_ptr<nrf_profile> &profile);

/*
 * Convert a string to nf type
 * @param [const std::string &] str: string input
 * @return the corresponding nf_type
 */
nf_type_t string_to_nf_type(const std::string &str);

/*
 * Convert a string to Patch operation
 * @param [const std::string &] str: string input
 * @return the corresponding Patch operation
 */
patch_op_type_t string_to_patch_operation(const std::string &str);


bool validate_uuid(const std::string &str);

}  // namespace api_conv
}
}

#endif /* FILE_API_CONVERSIONS_HPP_SEEN */
