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

/*! \file nrf_client.cpp
 \brief
 \author  Tien-Thinh NGUYEN
 \company Eurecom
 \date 2020
 \email: Tien-Thinh.Nguyen@eurecom.fr
 */

#include <stdexcept>

#include <curl/curl.h>
#include <pistache/http.h>
#include <pistache/mime.h>
#include <nlohmann/json.hpp>

#include "logger.hpp"
#include "nrf_client.hpp"

using namespace Pistache::Http;
using namespace Pistache::Http::Mime;
using namespace oai::nrf::app;
using json = nlohmann::json;

extern nrf_client *nrf_client_inst;

// To read content of the response from NF
static std::size_t callback(const char *in, std::size_t size, std::size_t num,
                            std::string *out) {
  const std::size_t totalBytes(size * num);
  out->append(in, totalBytes);
  return totalBytes;
}

CURL *nrf_client::curl_create_handle(const std::string &uri,
                                     std::string *httpData) {
  // create handle for a curl request
  struct curl_slist *headers = NULL;
  headers = curl_slist_append(headers, "Accept: application/json");
  headers = curl_slist_append(headers, "Content-Type: application/json");
  headers = curl_slist_append(headers, "charsets: utf-8");

  CURL *curl = curl_easy_init();

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, uri.c_str());
    // curl_easy_setopt(curl, CURLOPT_PRIVATE, str);
    // curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 100L);
    // Hook up data handling function.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  }
  return curl;
}

void nrf_client::notify_subscribed_event(
    const std::shared_ptr<nrf_profile> &profile,
    const std::vector<std::string> &uris) {
  Logger::nrf_app().debug(
      "Send notification for the subscribed event to the subscription");

  int still_running = 0, numfds = 0, res = 0;
  CURLMsg *curl_msg = nullptr;
  CURL *curl = nullptr;
  CURLcode return_code = {};
  int http_status_code = 0, msgs_left = 0;
  CURLM *m_curl_multi = nullptr;
  char *url = nullptr;

  std::unique_ptr<std::string> httpData(new std::string());
  std::string data;

  curl_global_init(CURL_GLOBAL_ALL);
  m_curl_multi = curl_multi_init();
  // init header
  struct curl_slist *headers = NULL;
  headers = curl_slist_append(headers, "Accept: application/json");
  headers = curl_slist_append(headers, "Content-Type: application/json");
  headers = curl_slist_append(headers, "charsets: utf-8");

  // Fill the json part
  nlohmann::json json_data = {};
  json_data["event"] = "NF_REGISTERED";
  json_data["nfInstanceUri"] = profile.get()->get_nf_instance_id();
  std::string body = json_data.dump();

  int index = 0;
  // create and add an easy handle to a  multi curl request
  for (auto i : uris) {
    CURL *curl = curl_easy_init();
    if (curl) {
      std::string url = i;
      Logger::nrf_app().debug("Send notification to NF with URI: %s",
                              url.c_str());
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
      curl_easy_setopt(curl, CURLOPT_HTTPPOST, 1);
      curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 100L);
      // Hook up data handling function.
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &callback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
      curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
      curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
    }
    curl_multi_add_handle(m_curl_multi, curl);
    index++;
  }

  curl_multi_perform(m_curl_multi, &still_running);
  // block until activity is detected on at least one of the handles or
  // MAX_WAIT_MSECS has passed.
  do {
    res = curl_multi_wait(m_curl_multi, NULL, 0, 1000, &numfds);
    if (res != CURLM_OK) {
      Logger::nrf_app().debug("curl_multi_wait() returned %d!", res);
    }
    curl_multi_perform(m_curl_multi, &still_running);
  } while (still_running);

  // process multiple curl
  // read the messages
  while ((curl_msg = curl_multi_info_read(m_curl_multi, &msgs_left))) {
    if (curl_msg->msg == CURLMSG_DONE) {
      curl = curl_msg->easy_handle;
      return_code = curl_msg->data.result;
      res = curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

      if (return_code != CURLE_OK) {
        Logger::nrf_app().debug("CURL error code  %d!", curl_msg->data.result);
        continue;
      }
      // Get HTTP status code
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_status_code);
      Logger::nrf_app().debug("HTTP status code  %d!", http_status_code);

      // remove this handle from the multi session and end this handle
      curl_multi_remove_handle(m_curl_multi, curl);
      curl_easy_cleanup(curl);
    } else {
      Logger::nrf_app().debug("Error after curl_multi_info_read(), CURLMsg %s",
                              curl_msg->msg);
    }
  }
}

//------------------------------------------------------------------------------
void nrf_client::notify_subscribed_event(
    const std::shared_ptr<nrf_profile> &profile, const std::string &uri) {
  Logger::nrf_app().debug(
      "Send notification for the subscribed event to the subscription");

  Logger::nrf_app().debug("NF URI: %s", uri.c_str());
  // Fill the json part
  nlohmann::json json_data = {};
  json_data["event"] = "NF_REGISTERED";
  json_data["nfInstanceUri"] = profile.get()->get_nf_instance_id();
  std::string body = json_data.dump();

  curl_global_init(CURL_GLOBAL_ALL);
  CURL *curl = curl = curl_easy_init();

  if (curl) {
    CURLcode res = {};
    struct curl_slist *headers = nullptr;
    // headers = curl_slist_append(headers, "charsets: utf-8");
    headers = curl_slist_append(headers, "content-type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, uri.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 100L);

    // Response information.
    long httpCode = {0};
    std::unique_ptr<std::string> httpData(new std::string());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
    res = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

    Logger::nrf_app().debug("Response from NF, Http Code: %d", httpCode);
    // TODO: in case of "307 temporary redirect"

    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
}
