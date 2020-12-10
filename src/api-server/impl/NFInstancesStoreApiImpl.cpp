/**
 * NRF NFManagement Service
 * NRF NFManagement Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include "NFInstancesStoreApiImpl.h"
#include "logger.hpp"
#include "nrf_app.hpp"

namespace oai {
namespace nrf {
namespace api {

using namespace oai::nrf::model;
using namespace oai::nrf::app;

NFInstancesStoreApiImpl::NFInstancesStoreApiImpl(
    std::shared_ptr<Pistache::Rest::Router> rtr, nrf_app *nrf_app_inst,
    std::string address)
    :
    NFInstancesStoreApi(rtr),
    m_nrf_app(nrf_app_inst),
    m_address(address) {
}
void NFInstancesStoreApiImpl::get_nf_instances(
    const Pistache::Optional<std::string> &nfType,
    const Pistache::Optional<int32_t> &limit,
    Pistache::Http::ResponseWriter &response) {

  Logger::nrf_sbi().info(
      "Got a request to retrieve  a collection of NF Instances");

  std::string nf_type = { };
  if (!nfType.isEmpty()) {
    nf_type = nfType.get();
    Logger::nrf_sbi().debug(
        "Retrieve  a collection of NF Instances, NF type:  %s",
        nf_type.c_str());
  }

  uint32_t limit_item = 0;
  if (!limit.isEmpty()) {
    limit_item = limit.get();
    Logger::nrf_sbi().debug(
        "Retrieve  a collection of NF Instances, limit number of items: %d",
        limit_item);

  }

  int http_code = 0;
  m_nrf_app->handle_get_nf_instances(nf_type, limit_item, http_code, 1);

  nlohmann::json json_data = { };
  //to_json(json_data, nf_profile);
  //response.send(Pistache::Http::Code::Ok, json_data.dump().c_str());

  response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void NFInstancesStoreApiImpl::options_nf_instances(
    Pistache::Http::ResponseWriter &response) {
  response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}

}
}
}

