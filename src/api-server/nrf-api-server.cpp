/**
 * RNI API
 * The ETSI MEC ISG MEC012 Radio Network Information API described using OpenAPI
 *
 * OpenAPI spec version: 1.1.1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */
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

#include "nrf-api-server.h"
#include "logger.hpp"
#include "pistache/endpoint.h"
#include "pistache/http.h"
#include "pistache/router.h"
#ifdef __linux__
#include <vector>
#include <signal.h>
#include <unistd.h>
#endif

#define PISTACHE_SERVER_MAX_PAYLOAD 32768

#ifdef __linux__
void sigHandler(int sig) {
  switch (sig) {
    case SIGINT:
    case SIGQUIT:
    case SIGTERM:
    case SIGHUP:
    default:
      break;
  }
  exit(0);
}

void setUpUnixSignals(std::vector<int> quitSignals) {
  sigset_t blocking_mask;
  sigemptyset(&blocking_mask);
  for (auto sig : quitSignals)
    sigaddset(&blocking_mask, sig);

  struct sigaction sa;
  sa.sa_handler = sigHandler;
  sa.sa_mask = blocking_mask;
  sa.sa_flags = 0;

  for (auto sig : quitSignals)
    sigaction(sig, &sa, nullptr);
}
#endif

using namespace oai::nrf::api;

void NRFApiServer::init(size_t thr) {
  auto opts = Pistache::Http::Endpoint::options().threads(thr);
  opts.flags(Pistache::Tcp::Options::ReuseAddr);
  opts.maxRequestSize(PISTACHE_SERVER_MAX_PAYLOAD);
  m_httpEndpoint->init(opts);

  m_completeStoredSearchDocumentApiImpl->init();
  m_nfInstancesStoreApiImpl->init();
  m_storedSearchDocumentApiImpl->init();
  m_nfInstanceIDDocumentApiImpl->init();
  m_subscriptionIDDocumentApiImpl->init();
  m_subscriptionsCollectionApiImpl->init();
  m_discNFInstancesStoreApiImpl->init();
}
void NRFApiServer::start() {
  Logger::nrf_sbi().info("HTTP1 server started");
  m_httpEndpoint->setHandler(m_router->handler());
  m_httpEndpoint->serve();

}
void NRFApiServer::shutdown() {
  m_httpEndpoint->shutdown();
}
