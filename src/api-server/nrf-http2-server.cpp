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

/*! \file nrf_http2-server.cpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: tien-thinh.nguyen@eurecom.fr
 */

#include "nrf-http2-server.h"
#include <boost/algorithm/string.hpp>
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>
#include <nlohmann/json.hpp>
#include <string>

#include "logger.hpp"
#include "nrf_config.hpp"
#include "3gpp_29.500.h"
#include "mime_parser.hpp"

using namespace nghttp2::asio_http2;
using namespace nghttp2::asio_http2::server;
using namespace oai::nrf::model;

extern nrf_config nrf_cfg;

//------------------------------------------------------------------------------
void nrf_http2_server::start() {
  boost::system::error_code ec;

  Logger::nrf_app().info("HTTP2 server started");
  std::string nfInstanceID          = {};
  std::string subscriptionID        = {};
  SubscriptionData subscriptionData = {};

  // NF Instances
  server.handle(
      NNRF_NFM_BASE + nrf_cfg.sbi_api_version + NNRF_NFM_NF_INSTANCE,
      [&](const request& request, const response& response) {
        request.on_data([&](const uint8_t* data, std::size_t len) {
          std::string msg((char*) data, len);
          NFProfile nFProfile;
          try {
            if (request.method().compare("PUT") == 0 && len > 0) {
              nlohmann::json::parse(msg.c_str()).get_to(nFProfile);
              this->register_nf_instance_handler(nFProfile, response);
            }
            if (request.method().compare("GET") == 0) {
              nlohmann::json::parse(msg.c_str()).get_to(nFProfile);
              std::vector<std::string> split_result;
              boost::split(
                  split_result, request.uri().path, boost::is_any_of("/"));
              nfInstanceID = split_result[split_result.size() - 1].c_str();
              this->get_nf_instance_handler(nfInstanceID, response);
            }
            if (request.method().compare("PATCH") == 0 && len > 0) {
              std::vector<PatchItem> patchItem;
              nlohmann::json::parse(msg.c_str()).get_to(patchItem);
              std::vector<std::string> split_result;
              boost::split(
                  split_result, request.uri().path, boost::is_any_of("/"));
              nfInstanceID = split_result[split_result.size() - 1].c_str();
              this->update_instance_handler(nfInstanceID, patchItem, response);
            }
            if (request.method().compare("DELETE") == 0) {
              std::vector<std::string> split_result;
              boost::split(
                  split_result, request.uri().path, boost::is_any_of("/"));
              nfInstanceID = split_result[split_result.size() - 1].c_str();
              this->deregister_nf_instance_handler(nfInstanceID, response);
            }
          } catch (nlohmann::detail::exception& e) {
            Logger::nrf_sbi().warn(
                "Can not parse the json data (error: %s)!", e.what());
            response.write_head(
                http_status_code_e::HTTP_STATUS_CODE_400_BAD_REQUEST);
            response.end();
            return;
          }
        });
      });

  // Subscriptions
  server.handle(
      NNRF_NFM_BASE + nrf_cfg.sbi_api_version + NNRF_NFM_STATUS_SUBSCRIBE_URL,
      [&](const request& request, const response& response) {
        request.on_data([&](const uint8_t* data, std::size_t len) {
          std::string msg((char*) data, len);
          try {
            if (request.method().compare("POST") == 0 && len > 0) {
              nlohmann::json::parse(msg.c_str()).get_to(subscriptionData);
              this->create_subscription_handler(subscriptionData, response);
            }
            if (request.method().compare("PATCH") == 0 && len > 0) {
              std::vector<PatchItem> patchItem;
              nlohmann::json::parse(msg.c_str()).get_to(patchItem);
              std::vector<std::string> split_result;
              boost::split(
                  split_result, request.uri().path, boost::is_any_of("/"));
              subscriptionID = split_result[split_result.size() - 1].c_str();
              this->update_subscription_handler(
                  subscriptionID, patchItem, response);
            }
            if (request.method().compare("DELETE") == 0) {
              std::vector<std::string> split_result;
              boost::split(
                  split_result, request.uri().path, boost::is_any_of("/"));
              subscriptionID = split_result[split_result.size() - 1].c_str();
              this->remove_subscription_handler(subscriptionID, response);
            }

          } catch (nlohmann::detail::exception& e) {
            Logger::nrf_sbi().warn(
                "Can not parse the json data (error: %s)!", e.what());
            response.write_head(
                http_status_code_e::HTTP_STATUS_CODE_400_BAD_REQUEST);
            response.end();
            return;
          }
        });
      });

  if (server.listen_and_serve(ec, m_address, std::to_string(m_port))) {
    std::cerr << "HTTP Server error: " << ec.message() << std::endl;
  }
}

void nrf_http2_server::register_nf_instance_handler(
    const NFProfile& NFProfiledata, const response& response) {
  std::string nfInstanceID = {};
  nfInstanceID             = NFProfiledata.getNfInstanceId();
  Logger::nrf_sbi().info(
      "Got a request to register an NF instance/Update an NF instance, "
      "Instance ID: %s",
      nfInstanceID.c_str());
  int http_code                  = 0;
  ProblemDetails problem_details = {};
  nlohmann::json json_data       = {};
  std::string content_type       = "application/json";
  std::string json_format;

  m_nrf_app->handle_register_nf_instance(
      nfInstanceID, NFProfiledata, http_code, 2, problem_details);

  if ((http_code != HTTP_STATUS_CODE_200_OK) and
      (http_code != HTTP_STATUS_CODE_201_CREATED) and
      (http_code != HTTP_STATUS_CODE_202_ACCEPTED)) {
    to_json(json_data, problem_details);
    content_type = "application/problem+json";
  } else {
    std::shared_ptr<nrf_profile> profile =
        m_nrf_app->find_nf_profile(nfInstanceID);
    if (profile.get() != nullptr) {
      profile.get()->to_json(json_data);
    }
  }
  header_map h;
  h.emplace(
      "location", header_value{
                      m_address + NNRF_NFM_BASE + nrf_cfg.sbi_api_version +
                      "/nf-instances/" + nfInstanceID});
  h.emplace("content-type", header_value{content_type});
  response.write_head(http_code, h);
  response.end(json_data.dump().c_str());
};

void nrf_http2_server::get_nf_instance_handler(
    const std::string& nfInstanceID, const response& response) {
  Logger::nrf_sbi().info(
      "Got a request to retrieve the profile of a given NF Instance, Instance "
      "ID: %s",
      nfInstanceID.c_str());
  int http_code                        = 0;
  ProblemDetails problem_details       = {};
  nlohmann::json json_data             = {};
  std::string content_type             = "application/json";
  std::shared_ptr<nrf_profile> profile = {};

  m_nrf_app->handle_get_nf_instance(
      nfInstanceID, profile, http_code, 2, problem_details);

  if (http_code != HTTP_STATUS_CODE_200_OK) {
    to_json(json_data, problem_details);
    content_type = "application/problem+json";
  } else {
    profile.get()->to_json(json_data);
  }

  header_map h;
  h.emplace(
      "location", header_value{
                      m_address + NNRF_NFM_BASE + nrf_cfg.sbi_api_version +
                      "/nf-instances/" + nfInstanceID});
  h.emplace("content-type", header_value{content_type});
  response.write_head(http_code, h);
  response.end(json_data.dump().c_str());
}

void nrf_http2_server::get_nf_instances_handler(
    const std::string& nfInstanceID, const response& response) {
  Logger::nrf_sbi().info(
      "Got a request to retrieve  a collection of NF Instances");

  std::string nf_type = {};
  // if (!nfType.isEmpty()) {
  //   nf_type = nfType.get();
  //   Logger::nrf_sbi().debug("\tNF type:  %s", nf_type.c_str());
  // }

  uint32_t limit_item = 0;
  // if (!limit.isEmpty()) {
  //   limit_item = limit.get();
  //   Logger::nrf_sbi().debug("\tLimit number of items: %d", limit_item);
  // }

  int http_code                        = 0;
  ProblemDetails problem_details       = {};
  nlohmann::json json_data             = {};
  std::string content_type             = "application/json";
  std::shared_ptr<nrf_profile> profile = {};
  std::vector<std::string> uris        = {};

  m_nrf_app->handle_get_nf_instances(
      nf_type, uris, limit_item, http_code, 2, problem_details);

  if (http_code != HTTP_STATUS_CODE_200_OK) {
    to_json(json_data, problem_details);
    content_type = "application/problem+json";
  } else {
    profile.get()->to_json(json_data);
  }

  header_map h;
  h.emplace(
      "location", header_value{
                      m_address + NNRF_NFM_BASE + nrf_cfg.sbi_api_version +
                      "/nf-instances/" + nfInstanceID});
  h.emplace("content-type", header_value{content_type});
  response.write_head(http_code, h);
  response.end();
}

void nrf_http2_server::update_instance_handler(
    const std::string& nfInstanceID, const std::vector<PatchItem>& patchItem,
    const response& response) {
  Logger::nrf_sbi().info("");
  Logger::nrf_sbi().info(
      "Got a request to update an NF instance, Instance ID: %s",
      nfInstanceID.c_str());

  int http_code                  = 0;
  ProblemDetails problem_details = {};
  m_nrf_app->handle_update_nf_instance(
      nfInstanceID, patchItem, http_code, 2, problem_details);

  nlohmann::json json_data = {};
  std::string content_type = "application/json";

  std::shared_ptr<nrf_profile> profile =
      m_nrf_app->find_nf_profile(nfInstanceID);

  if ((http_code != HTTP_STATUS_CODE_200_OK) and
      (http_code != HTTP_STATUS_CODE_204_NO_CONTENT)) {
    to_json(json_data, problem_details);
    content_type = "application/problem+json";
  } else if (http_code == HTTP_STATUS_CODE_200_OK) {
    if (profile.get() != nullptr)
      // convert the profile to Json
      profile.get()->to_json(json_data);
  }

  Logger::nrf_sbi().debug("Json data: %s", json_data.dump().c_str());
  header_map h;
  h.emplace(
      "location", header_value{
                      m_address + NNRF_NFM_BASE + nrf_cfg.sbi_api_version +
                      "/nf-instances/" + nfInstanceID});
  h.emplace("content-type", header_value{content_type});
  response.write_head(http_code, h);
  response.end(json_data.dump().c_str());
}

void nrf_http2_server::deregister_nf_instance_handler(
    const std::string& nfInstanceID, const response& response) {
  Logger::nrf_sbi().info(
      "Got a request to de-register a given NF Instance, Instance ID: %s",
      nfInstanceID.c_str());

  int http_code                  = 0;
  ProblemDetails problem_details = {};
  nlohmann::json json_data       = {};
  std::string content_type       = "application/json";

  m_nrf_app->handle_deregister_nf_instance(
      nfInstanceID, http_code, 2, problem_details);

  header_map h;
  h.emplace(
      "location", header_value{
                      m_address + NNRF_NFM_BASE + nrf_cfg.sbi_api_version +
                      "/nf-instances/" + nfInstanceID});
  h.emplace("content-type", header_value{content_type});
  response.write_head(http_code, h);
  response.end();
};

void nrf_http2_server::create_subscription_handler(
    const SubscriptionData& subscriptionData, const response& response) {
  Logger::nrf_sbi().info("Got a request to create a new subscription");
  int http_code                  = 0;
  ProblemDetails problem_details = {};
  std::string sub_id;
  nlohmann::json json_sub  = {};
  nlohmann::json json_data = {};
  std::string content_type = "application/json";

  Logger::nrf_sbi().debug("Subscription data %s", json_sub.dump().c_str());
  m_nrf_app->handle_create_subscription(
      subscriptionData, sub_id, http_code, 2, problem_details);

  if (http_code != HTTP_STATUS_CODE_201_CREATED) {
    to_json(json_data, problem_details);
    content_type = "application/problem+json";
  } else {
    to_json(json_data, subscriptionData);
    json_data["subscriptionId"] = sub_id;
  }

  header_map h;
  h.emplace(
      "location", header_value{
                      m_address + NNRF_NFM_BASE + nrf_cfg.sbi_api_version +
                      NNRF_NFM_STATUS_SUBSCRIBE_URL});
  h.emplace("content-type", header_value{content_type});
  response.write_head(http_code, h);
  response.end(json_data.dump().c_str());
};

void nrf_http2_server::update_subscription_handler(
    const std::string& subscriptionID, const std::vector<PatchItem>& patchItem,
    const response& response) {
  Logger::nrf_sbi().info(
      "Got a request to update of subscription to NF instances, subscription "
      "ID %s",
      subscriptionID.c_str());

  int http_code                  = 0;
  ProblemDetails problem_details = {};
  nlohmann::json json_data       = {};
  std::string content_type       = "application/json";

  m_nrf_app->handle_update_subscription(
      subscriptionID, patchItem, http_code, 1, problem_details);

  // TODO: (section 5.2.2.5.6, Update of Subscription to NF Instances,
  // 3GPP TS 29.510 V16.0.0 (2019-06)) if the NRF accepts the extension
  // of the lifetime of the subscription, but it assigns a validity time
  // different than the value suggested by the NF Service Consumer, a
  // "200 OK" response code shall be returned
  header_map h;
  h.emplace("content-type", header_value{content_type});

  if (http_code != HTTP_STATUS_CODE_204_NO_CONTENT) {
    to_json(json_data, problem_details);
    response.write_head(http_code, h);
    response.end(json_data.dump().c_str());
  } else {
    response.write_head(http_code, h);
    response.end();
  }
}

void nrf_http2_server::remove_subscription_handler(
    const std::string& subscriptionID, const response& response) {
  Logger::nrf_sbi().info(
      "Got a request to remove an existing subscription, subscription ID %s",
      subscriptionID.c_str());
  int http_code                  = 0;
  ProblemDetails problem_details = {};
  nlohmann::json json_data       = {};
  std::string content_type       = "application/json";

  m_nrf_app->handle_remove_subscription(
      subscriptionID, http_code, 2, problem_details);

  header_map h;
  h.emplace("content-type", header_value{content_type});

  if (http_code != HTTP_STATUS_CODE_204_NO_CONTENT) {
    to_json(json_data, problem_details);
    response.write_head(http_code, h);
    response.end(json_data.dump().c_str());
  } else {
    response.write_head(http_code, h);
    response.end();
  }
}

void nrf_http2_server::search_nf_instances_handler(
    const SubscriptionData& subscriptionData, const response& response) {
  Logger::nrf_sbi().info(
      "Got a request to discover the set of NF instances that satisfies a "
      "number of input query parameters");

  std::string target_nf_type = {};
  // if (!targetNfType.isEmpty()) {
  //   target_nf_type = targetNfType.get();
  //   Logger::nrf_sbi().debug("\tTarget NF type:  %s", target_nf_type.c_str());
  // }

  std::string requester_nf_type = {};
  // if (!requesterNfType.isEmpty()) {
  //   requester_nf_type = requesterNfType.get();
  //   Logger::nrf_sbi().debug(
  //       "\tRequested NF type:  %s", requester_nf_type.c_str());
  // }

  std::string requester_nf_instance_id = {};
  // if (!requesterNfInstanceId.isEmpty()) {
  //   requester_nf_instance_id = requesterNfInstanceId.get();
  //   Logger::nrf_sbi().debug(
  //       "\tRequested NF instance id:  %s", requester_nf_instance_id.c_str());
  // }

  uint32_t limit_nfs = 0;
  // if (!limit.isEmpty()) {
  //   limit_nfs = limit.get();
  //   Logger::nrf_sbi().debug(
  //       "\tMaximum number of NFProfiles to be returned in the response: %d",
  //       limit_nfs);
  // }

  // TODO: other query parameters

  int http_code                  = 0;
  ProblemDetails problem_details = {};
  std::string search_id          = {};
  m_nrf_app->handle_search_nf_instances(
      target_nf_type, requester_nf_type, requester_nf_instance_id, limit_nfs,
      search_id, http_code, 1, problem_details);

  nlohmann::json json_data = {};
  std::string content_type = "application/json";

  std::shared_ptr<nrf_search_result> search_result = {};
  m_nrf_app->find_search_result(search_id, search_result);

  if (http_code != HTTP_STATUS_CODE_200_OK) {
    to_json(json_data, problem_details);
    content_type = "application/problem+json";
  } else {
    // convert the profile to Json
    if (search_result != nullptr)
      search_result.get()->to_json(json_data, limit_nfs);
  }

  // TODO: applying client restrictions in terms of the number of
  // instances to be returned (i.e. "limit" or "max-
  // payload-size" query parameters) .

  Logger::nrf_sbi().debug("Json data: %s", json_data.dump().c_str());

  header_map h;
  h.emplace("content-type", header_value{content_type});
  response.write_head(http_code, h);
  response.end(json_data.dump().c_str());
}

void nrf_http2_server::access_token_request_handler(
    const SubscriptionData& subscriptionData, const response& response) {}

//------------------------------------------------------------------------------
void nrf_http2_server::stop() {
  server.stop();
}
