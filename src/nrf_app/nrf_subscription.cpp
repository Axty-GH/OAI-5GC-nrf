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

/*! \file nrf_subscription.cpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: Tien-Thinh.Nguyen@eurecom.fr
 */

#include "nrf_subscription.hpp"
#include "logger.hpp"
#include <nlohmann/json.hpp>

using namespace oai::nrf::app;

//------------------------------------------------------------------------------
void nrf_subscription::set_subscription_id(const std::string &sub) {
  subscription_id = sub;
}

//------------------------------------------------------------------------------
void nrf_subscription::get_subscription_id(std::string &sub) const {
  sub = subscription_id;
}

//------------------------------------------------------------------------------
std::string nrf_subscription::get_subscription_id() const {
  return subscription_id;
}

void nrf_subscription::set_notification_uri(
    const std::string &notification_uri) {
  nf_status_notification_uri = notification_uri;
}

void nrf_subscription::get_notification_uri(
    std::string &notification_uri) const {
  notification_uri = nf_status_notification_uri;
}

//------------------------------------------------------------------------------
void nrf_subscription::display() {
  Logger::nrf_app().debug("Subscription ID: %s", subscription_id.c_str());

  Logger::nrf_app().debug("Notification URI: %s",
                          nf_status_notification_uri.c_str());
}


//------------------------------------------------------------------------------
void nrf_subscription::subscribe_nf_status_change() {

  Logger::nrf_app().debug("Subscribe to NF status change event");
  ev_connection = m_event_sub.subscribe_nf_status_change(
      boost::bind(&nrf_subscription::handle_nf_status_change, this, _1));
}

//------------------------------------------------------------------------------
void nrf_subscription::handle_nf_status_change(const std::shared_ptr<nrf_profile> &profile) {
	std::string nf_instance_id;
	profile.get()->get_nf_instance_id(nf_instance_id);
  Logger::nrf_app().info("Handle NF status change (subscription ID %s), profile ID %s", subscription_id.c_str(), nf_instance_id.c_str());
  //TODO:
  nlohmann::json notification_data = {};
  notification_data["event"] = "NF_REGISTERED";
  notification_data["nfInstanceUri"] = "";
  //get NF profile based on profile_id
  //NFStatusNotify
  //curl...
}


