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

#include "NFInstanceIDDocumentApiImpl.h"
#include "logger.hpp"
#include "nrf_app.hpp"
#include "nrf_config.hpp"
#include "ProblemDetails.h"
#include "3gpp_29.500.h"

extern oai::nrf::app::nrf_config nrf_cfg;

namespace oai {
namespace nrf {
namespace api {

using namespace oai::nrf::model;
using namespace oai::nrf::app;
using namespace oai::nrf;

NFInstanceIDDocumentApiImpl::NFInstanceIDDocumentApiImpl(
    std::shared_ptr<Pistache::Rest::Router> rtr, nrf_app *nrf_app_inst,
    std::string address)
    :
    NFInstanceIDDocumentApi(rtr),
    m_nrf_app(nrf_app_inst),
    m_address(address) {
}

void NFInstanceIDDocumentApiImpl::deregister_nf_instance(
    const std::string &nfInstanceID, Pistache::Http::ResponseWriter &response) {
  response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void NFInstanceIDDocumentApiImpl::get_nf_instance(
    const std::string &nfInstanceID, Pistache::Http::ResponseWriter &response) {
  response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void NFInstanceIDDocumentApiImpl::register_nf_instance(
    const std::string &nfInstanceID, const NFProfile &nFProfile,
    const Pistache::Optional<Pistache::Http::Header::Raw> &contentEncoding,
    Pistache::Http::ResponseWriter &response) {
  Logger::nrf_sbi().info(
      "Got a request to register an NF instance/Update an NF instance, Instance ID: %s",
      nfInstanceID.c_str());

  NFProfile nf_profile = nFProfile;
  int http_code = 0;
  ProblemDetails problem_details = { };
  m_nrf_app->handle_register_nf_instance(nfInstanceID, nFProfile, http_code, 1,
                                         problem_details);

  nlohmann::json json_data = { };
  std::string content_type = "application/json";

  if ((http_code != HTTP_STATUS_CODE_200_OK)
      and (http_code != HTTP_STATUS_CODE_201_CREATED)
      and (http_code != HTTP_STATUS_CODE_202_ACCEPTED)) {
    to_json(json_data, problem_details);
    content_type = "application/problem+json";
  } else {
    to_json(json_data, nf_profile);
  }

  //content type
  response.headers().add < Pistache::Http::Header::ContentType
      > (Pistache::Http::Mime::MediaType(content_type));
  //Location header
  response.headers().add < Pistache::Http::Header::Location
      > (m_address + base + nrf_cfg.sbi_api_version + "/nf-instances/"
          + nfInstanceID);
  response.send(Pistache::Http::Code(http_code), json_data.dump().c_str());
}
void NFInstanceIDDocumentApiImpl::update_nf_instance(
    const std::string &nfInstanceID, const std::vector<PatchItem> &patchItem,
    Pistache::Http::ResponseWriter &response) {
  Logger::nrf_sbi().info(
      "Got a request to register an NF instance, Instance ID: %s",
      nfInstanceID.c_str());

  int http_code = 0;
  m_nrf_app->handle_update_nf_instance(nfInstanceID, patchItem, http_code, 1);

  nlohmann::json json_data = { };
  //to_json(json_data, nf_profile);
  response.send(Pistache::Http::Code::Ok, json_data.dump().c_str());
}

}
}
}

