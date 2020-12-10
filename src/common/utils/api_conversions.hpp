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

using namespace oai::nrf::model;
using namespace oai::nrf::app;

namespace oai {
namespace nrf {
namespace api_conv {

bool profile_api_to_amf_profile(const NFProfile &api_profile,
		std::shared_ptr<nrf_profile> &profile);

//bool profile_api_to_amf_profile(const NFProfile &api_profile,
//		std::shared_ptr<amf_profile> &profile);

}  // namespace api_conv
}
}

#endif /* FILE_API_CONVERSIONS_HPP_SEEN */
