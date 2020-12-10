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
/*
 * NFInstancesStoreApi.h
 *
 * 
 */

#ifndef NFInstancesStoreApi_H_
#define NFInstancesStoreApi_H_


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
//#include "NFType.h"
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

class  NFInstancesStoreApi {
public:
    NFInstancesStoreApi(std::shared_ptr<Pistache::Rest::Router>);
    virtual ~NFInstancesStoreApi() {}
    void init();

    const std::string base = "/nnrf-nfm/";

private:
    void setupRoutes();

    void get_nf_instances_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void options_nf_instances_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void nf_instances_store_api_default_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);

    std::shared_ptr<Pistache::Rest::Router> router;

    /// <summary>
    /// Retrieves a collection of NF Instances
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="nfType">Type of NF (optional, default to NFType())</param>
    /// <param name="limit">How many items to return at one time (optional, default to 0)</param>
    virtual void get_nf_instances(const Pistache::Optional<std::string> &nfType, const Pistache::Optional<int32_t> &limit, Pistache::Http::ResponseWriter &response) = 0;

    /// <summary>
    /// Discover communication options supported by NRF for NF Instances
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    virtual void options_nf_instances(Pistache::Http::ResponseWriter &response) = 0;

};

}
}
}

#endif /* NFInstancesStoreApi_H_ */

