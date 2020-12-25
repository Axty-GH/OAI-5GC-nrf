/**
 * NRF NFDiscovery Service
 * NRF NFDiscovery Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "DiscNFInstancesStoreApiImpl.h"
#include <set>
#include "3gpp_29.500.h"
#include "logger.hpp"

namespace oai {
namespace nrf {
namespace api {

using namespace oai::nrf::model;
using namespace oai::nrf::app;

DiscNFInstancesStoreApiImpl::DiscNFInstancesStoreApiImpl(
    std::shared_ptr<Pistache::Rest::Router> rtr, nrf_app *nrf_app_inst,
    std::string address)
    : DiscNFInstancesStoreApi(rtr),
      m_nrf_app(nrf_app_inst),
      m_address(address) {}

void DiscNFInstancesStoreApiImpl::search_nf_instances(
    const Pistache::Optional<std::string> &targetNfType,
    const Pistache::Optional<std::string> &requesterNfType,
    const Pistache::Optional<std::string> &requesterNfInstanceId,
    const Pistache::Optional<std::vector<ServiceName>> &serviceNames,
    const Pistache::Optional<std::string> &requesterNfInstanceFqdn,
    const Pistache::Optional<std::vector<PlmnId>> &targetPlmnList,
    const Pistache::Optional<std::vector<PlmnId>> &requesterPlmnList,
    const Pistache::Optional<std::string> &targetNfInstanceId,
    const Pistache::Optional<std::string> &targetNfFqdn,
    const Pistache::Optional<std::string> &hnrfUri,
    const Pistache::Optional<std::vector<Snssai>> &snssais,
    const Pistache::Optional<std::vector<Snssai>> &requesterSnssais,
    const Pistache::Optional<std::vector<PlmnSnssai>> &plmnSpecificSnssaiList,
    const Pistache::Optional<std::string> &dnn,
    const Pistache::Optional<std::vector<std::string>> &nsiList,
    const Pistache::Optional<std::string> &smfServingArea,
    const Pistache::Optional<Tai> &tai,
    const Pistache::Optional<std::string> &amfRegionId,
    const Pistache::Optional<std::string> &amfSetId,
    const Pistache::Optional<Guami> &guami,
    const Pistache::Optional<std::string> &supi,
    const Pistache::Optional<std::string> &ueIpv4Address,
    const Pistache::Optional<std::string> &ipDomain,
    const Pistache::Optional<Ipv6Prefix> &ueIpv6Prefix,
    const Pistache::Optional<bool> &pgwInd,
    const Pistache::Optional<std::string> &pgw,
    const Pistache::Optional<std::string> &gpsi,
    const Pistache::Optional<std::string> &externalGroupIdentity,
    const Pistache::Optional<DataSetId> &dataSet,
    const Pistache::Optional<std::string> &routingIndicator,
    const Pistache::Optional<std::vector<std::string>> &groupIdList,
    const Pistache::Optional<std::vector<std::string>> &dnaiList,
    const Pistache::Optional<std::vector<PduSessionType>> &pduSessionTypes,
    const Pistache::Optional<std::vector<EventId>> &eventIdList,
    const Pistache::Optional<std::vector<NwdafEvent>> &nwdafEventList,
    const Pistache::Optional<std::string> &supportedFeatures,
    const Pistache::Optional<bool> &upfIwkEpsInd,
    const Pistache::Optional<PlmnId> &chfSupportedPlmn,
    const Pistache::Optional<std::string> &preferredLocality,
    const Pistache::Optional<AccessType> &accessType,
    const Pistache::Optional<int32_t> &limit,
    const Pistache::Optional<std::vector<std::string>> &requiredFeatures,
    const Pistache::Optional<ComplexQuery> &complexQuery,
    const Pistache::Optional<int32_t> &maxPayloadSize,
    const Pistache::Optional<AtsssCapability> &atsssCapability,
    const Pistache::Optional<bool> &upfUeIpAddrInd,
    const Pistache::Optional<Pistache::Http::Header::Raw> &ifNoneMatch,
    Pistache::Http::ResponseWriter &response) {
  Logger::nrf_sbi().info(
      "Got a request to discover the set of NF instances that satisfies a "
      "number of input query parameters");

  std::string target_nf_type = {};
  if (!targetNfType.isEmpty()) {
    target_nf_type = targetNfType.get();
    Logger::nrf_sbi().debug("\tTarget NF type:  %s", target_nf_type.c_str());
  }

  std::string requester_nf_type = {};
  if (!requesterNfType.isEmpty()) {
    requester_nf_type = requesterNfType.get();
    Logger::nrf_sbi().debug("\tRequested NF type:  %s",
                            requester_nf_type.c_str());
  }

  std::string requester_nf_instance_id = {};
  if (!requesterNfInstanceId.isEmpty()) {
    requester_nf_instance_id = requesterNfInstanceId.get();
    Logger::nrf_sbi().debug("\tRequested NF instance id:  %s",
                            requester_nf_instance_id.c_str());
  }

  uint32_t limit_nfs  = 0;
  if (!limit.isEmpty()) {
    limit_nfs = limit.get();
    Logger::nrf_sbi().debug("\tMaximum number of NFProfiles to be returned in the response: %d",
                            limit_nfs);
  }


  // TODO: other query parameters

  int http_code = 0;
  ProblemDetails problem_details = {};
  std::string search_id = {};
  m_nrf_app->handle_search_nf_instances(target_nf_type, requester_nf_type,
                                        requester_nf_instance_id, limit_nfs, search_id,
                                        http_code, 1, problem_details);

  nlohmann::json json_data = {};
  std::string content_type = "application/json";

  std::shared_ptr<nrf_search_result> search_result = {};
  m_nrf_app->find_search_result(search_id, search_result);

  if (http_code != HTTP_STATUS_CODE_200_OK) {
    to_json(json_data, problem_details);
    content_type = "application/problem+json";
  } else {
    // convert the profile to Json
    if (search_result != nullptr) search_result.get()->to_json(json_data, limit_nfs);
  }

  //TODO: applying client restrictions in terms of the number of
  //instances to be returned (i.e. "limit" or "max-
  //payload-size" query parameters) .

  Logger::nrf_sbi().debug("Json data: %s", json_data.dump().c_str());

  // content type
  response.headers().add<Pistache::Http::Header::ContentType>(
      Pistache::Http::Mime::MediaType(content_type));
  //TODO: add headers:  Cache-Control, ETag

  response.send(Pistache::Http::Code(http_code), json_data.dump().c_str());
}

}  // namespace api
}  // namespace nrf
}  // namespace oai
