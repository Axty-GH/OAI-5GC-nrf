/**
 * NRF NFDiscovery Service
 * NRF NFDiscovery Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved. 
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 * 
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */
/*
 * NFInstancesStoreApi.h
 *
 * 
 */

#ifndef DiscNFInstancesStoreApi_H_
#define DiscNFInstancesStoreApi_H_

#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>

#include "AccessType.h"
#include "AtsssCapability.h"
#include "ComplexQuery.h"
#include "DataSetId.h"
#include "EventId.h"
#include "Guami.h"
#include "Ipv6Prefix.h"
#include "NFType.h"
#include "NwdafEvent.h"
#include "PduSessionType.h"
#include "PlmnId.h"
#include "PlmnSnssai.h"
#include "ProblemDetails.h"
#include "SearchResult.h"
#include "ServiceName.h"
#include "Snssai.h"
#include "Tai.h"
#include <string>
#include <set>

namespace oai {
namespace nrf {
namespace api {

using namespace oai::nrf::model;

class DiscNFInstancesStoreApi {
 public:
  DiscNFInstancesStoreApi (std::shared_ptr<Pistache::Rest::Router>);
  virtual ~DiscNFInstancesStoreApi() {
  }
  void init();

  const std::string base = "/nnrf-disc/";

 private:
  void setupRoutes();

  void search_nf_instances_handler(const Pistache::Rest::Request &request,
                                   Pistache::Http::ResponseWriter response);
  void nf_instances_store_api_default_handler(
      const Pistache::Rest::Request &request,
      Pistache::Http::ResponseWriter response);

  std::shared_ptr<Pistache::Rest::Router> router;

  /// <summary>
  /// Search a collection of NF Instances
  /// </summary>
  /// <remarks>
  /// 
  /// </remarks>
  /// <param name="targetNfType">Type of the target NF</param>
  /// <param name="requesterNfType">Type of the requester NF</param>
  /// <param name="requesterNfInstanceId">NfInstanceId of the requester NF (optional, default to &quot;&quot;)</param>
  /// <param name="serviceNames">Names of the services offered by the NF (optional, default to std::vector&lt;ServiceName&gt;())</param>
  /// <param name="requesterNfInstanceFqdn">FQDN of the requester NF (optional, default to &quot;&quot;)</param>
  /// <param name="targetPlmnList">Id of the PLMN of the target NF (optional, default to std::vector&lt;PlmnId&gt;())</param>
  /// <param name="requesterPlmnList">Id of the PLMN where the NF issuing the Discovery request is located (optional, default to std::vector&lt;PlmnId&gt;())</param>
  /// <param name="targetNfInstanceId">Identity of the NF instance being discovered (optional, default to &quot;&quot;)</param>
  /// <param name="targetNfFqdn">FQDN of the NF instance being discovered (optional, default to &quot;&quot;)</param>
  /// <param name="hnrfUri">Uri of the home NRF (optional, default to &quot;&quot;)</param>
  /// <param name="snssais">Slice info of the target NF (optional, default to std::vector&lt;Snssai&gt;())</param>
  /// <param name="requesterSnssais">Slice info of the requester NF (optional, default to std::vector&lt;Snssai&gt;())</param>
  /// <param name="plmnSpecificSnssaiList">PLMN specific Slice info of the target NF (optional, default to std::vector&lt;PlmnSnssai&gt;())</param>
  /// <param name="dnn">Dnn supported by the BSF, SMF or UPF (optional, default to &quot;&quot;)</param>
  /// <param name="nsiList">NSI IDs that are served by the services being discovered (optional, default to std::vector&lt;std::string&gt;())</param>
  /// <param name="smfServingArea"> (optional, default to &quot;&quot;)</param>
  /// <param name="tai">Tracking Area Identity (optional, default to Tai())</param>
  /// <param name="amfRegionId">AMF Region Identity (optional, default to &quot;&quot;)</param>
  /// <param name="amfSetId">AMF Set Identity (optional, default to &quot;&quot;)</param>
  /// <param name="guami">Guami used to search for an appropriate AMF (optional, default to Guami())</param>
  /// <param name="supi">SUPI of the user (optional, default to &quot;&quot;)</param>
  /// <param name="ueIpv4Address">IPv4 address of the UE (optional, default to &quot;&quot;)</param>
  /// <param name="ipDomain">IP domain of the UE, which supported by BSF (optional, default to &quot;&quot;)</param>
  /// <param name="ueIpv6Prefix">IPv6 prefix of the UE (optional, default to Ipv6Prefix())</param>
  /// <param name="pgwInd">Combined PGW-C and SMF or a standalone SMF (optional, default to false)</param>
  /// <param name="pgw">PGW FQDN of a combined PGW-C and SMF (optional, default to &quot;&quot;)</param>
  /// <param name="gpsi">GPSI of the user (optional, default to &quot;&quot;)</param>
  /// <param name="externalGroupIdentity">external group identifier of the user (optional, default to &quot;&quot;)</param>
  /// <param name="dataSet">data set supported by the NF (optional, default to DataSetId())</param>
  /// <param name="routingIndicator">routing indicator in SUCI (optional, default to &quot;&quot;)</param>
  /// <param name="groupIdList">Group IDs of the NFs being discovered (optional, default to std::vector&lt;std::string&gt;())</param>
  /// <param name="dnaiList">Data network access identifiers of the NFs being discovered (optional, default to std::vector&lt;std::string&gt;())</param>
  /// <param name="pduSessionTypes">list of PDU Session Type required to be supported by the target NF (optional, default to std::vector&lt;PduSessionType&gt;())</param>
  /// <param name="eventIdList">Analytics event(s) requested to be supported by the Nnwdaf_AnalyticsInfo service (optional, default to std::vector&lt;EventId&gt;())</param>
  /// <param name="nwdafEventList">Analytics event(s) requested to be supported by the Nnwdaf_EventsSubscription service. (optional, default to std::vector&lt;NwdafEvent&gt;())</param>
  /// <param name="supportedFeatures">Features required to be supported by the target NF (optional, default to &quot;&quot;)</param>
  /// <param name="upfIwkEpsInd">UPF supporting interworking with EPS or not (optional, default to false)</param>
  /// <param name="chfSupportedPlmn">PLMN ID supported by a CHF (optional, default to PlmnId())</param>
  /// <param name="preferredLocality">preferred target NF location (optional, default to &quot;&quot;)</param>
  /// <param name="accessType">AccessType supported by the target NF (optional, default to AccessType())</param>
  /// <param name="limit">Maximum number of NFProfiles to return in the response (optional, default to 0)</param>
  /// <param name="requiredFeatures">Features required to be supported by the target NF (optional, default to std::vector&lt;std::string&gt;())</param>
  /// <param name="complexQuery">the complex query condition expression (optional, default to ComplexQuery())</param>
  /// <param name="maxPayloadSize">Maximum payload size of the response expressed in kilo octets (optional, default to 0)</param>
  /// <param name="atsssCapability">ATSSS Capability (optional, default to AtsssCapability())</param>
  /// <param name="upfUeIpAddrInd">UPF supporting allocating UE IP addresses/prefixes (optional, default to false)</param>
  /// <param name="ifNoneMatch">Validator for conditional requests, as described in IETF RFC 7232, 3.2 (optional, default to &quot;&quot;)</param>
  virtual void search_nf_instances(
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
      Pistache::Http::ResponseWriter &response) = 0;

};

}
}
}

#endif /* NFInstancesStoreApi_H_ */

