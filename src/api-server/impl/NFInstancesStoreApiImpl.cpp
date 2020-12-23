/**
 * NRF NFManagement Service
 * NRF NFManagement Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "NFInstancesStoreApiImpl.h"
#include "3gpp_29.500.h"
#include "logger.hpp"

namespace oai {
namespace nrf {
namespace api {

using namespace oai::nrf::model;
using namespace oai::nrf::app;

NFInstancesStoreApiImpl::NFInstancesStoreApiImpl(
    std::shared_ptr<Pistache::Rest::Router> rtr, nrf_app *nrf_app_inst,
    std::string address)
    : NFInstancesStoreApi(rtr), m_nrf_app(nrf_app_inst), m_address(address) {}
void NFInstancesStoreApiImpl::get_nf_instances(
    const Pistache::Optional<std::string> &nfType,
    const Pistache::Optional<int32_t> &limit,
    Pistache::Http::ResponseWriter &response) {
  Logger::nrf_sbi().info(
      "Got a request to retrieve  a collection of NF Instances");

  std::string nf_type = {};
  if (!nfType.isEmpty()) {
    nf_type = nfType.get();
    Logger::nrf_sbi().debug("\tNF type:  %s", nf_type.c_str());
  }

  uint32_t limit_item = 0;
  if (!limit.isEmpty()) {
    limit_item = limit.get();
    Logger::nrf_sbi().debug("\tLimit number of items: %d", limit_item);
  }

  int http_code = 0;
  std::vector<std::string> uris = {};
  ProblemDetails problem_details = {};
  m_nrf_app->handle_get_nf_instances(nf_type, uris, limit_item, http_code, 1,
                                     problem_details);

  nlohmann::json json_data = {};
  // TODO: std::string content_type = "application/3gppHal+json";
  std::string content_type = "application/json";

  if (http_code != HTTP_STATUS_CODE_200_OK) {
    to_json(json_data, problem_details);
    content_type = "application/problem+json";
  } else {
    // convert URIs to Json
    json_data["_links"]["item"] = nlohmann::json::array();
    json_data["_links"]["self"] = "";
    for (auto u : uris) {
      nlohmann::json json_item = {};
      json_item["href"] = u;
      json_data["_links"]["item"].push_back(json_item);
    }
  }

  Logger::nrf_sbi().debug("Json data: %s", json_data.dump().c_str());

  // content type
  response.headers().add<Pistache::Http::Header::ContentType>(
      Pistache::Http::Mime::MediaType(content_type));
  response.send(Pistache::Http::Code(http_code), json_data.dump().c_str());
}
void NFInstancesStoreApiImpl::options_nf_instances(
    Pistache::Http::ResponseWriter &response) {
  response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}

}  // namespace api
}  // namespace nrf
}  // namespace oai
