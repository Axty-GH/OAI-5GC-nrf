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

/*! \file nrf_subscription.hpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: Tien-Thinh.Nguyen@eurecom.fr
 */

#ifndef FILE_NRF_SUBSCRIPTION_HPP_SEEN
#define FILE_NRF_SUBSCRIPTION_HPP_SEEN

#include "3gpp_29.510.h"
#include "logger.hpp"
#include "nrf_event.hpp"
#include "nrf_profile.hpp"

namespace oai {
namespace nrf {
namespace app {
using namespace std;

class nrf_subscription {
 public:
  nrf_subscription(nrf_event &ev)
      : m_event_sub(ev){
        };

  nrf_subscription(nrf_subscription const &) = delete;

  virtual ~nrf_subscription() {
    Logger::nrf_app().debug("Delete NRF Subscription instance...");
    if (ev_connection.connected()) ev_connection.disconnect();
  }

  void operator=(nrf_subscription const &) = delete;

  void set_subscription_id(const std::string &sub_id);
  void get_subscription_id(std::string &sub_id) const;
  std::string get_subscription_id() const;
  void set_notification_uri(const std::string &notification_uri);
  void get_notification_uri(std::string &notification_uri) const;
  void display();
  void set_sub_condition(const subscription_condition_t &c);
  void get_sub_condition(subscription_condition_t &c) const;
  // subscription_condition_t get_sub_condition() const;

  void set_notif_events(const std::vector<uint8_t> &ev_types);
  void add_notif_event(const uint8_t &ev_type);
  void get_notif_events(std::vector<uint8_t> &ev_types) const;
  std::vector<uint8_t> get_notif_events() const;

  void subscribe_nf_status_registered();
  void handle_nf_status_registered(const std::shared_ptr<nrf_profile> &profile);

 private:
  std::string nf_status_notification_uri;
  std::string subscription_id;
  subscription_condition_t sub_condition;
  std::vector<uint8_t> notif_events;
  nrf_event &m_event_sub;
  bs2::connection ev_connection;
};
}  // namespace app
}  // namespace nrf
}  // namespace oai

#endif /* FILE_NRF_SUBSCRIPTION_HPP_SEEN */
