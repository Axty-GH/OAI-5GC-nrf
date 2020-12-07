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
 * SubscriptionIDDocumentApi.h
 *
 * 
 */

#ifndef SubscriptionIDDocumentApi_H_
#define SubscriptionIDDocumentApi_H_


#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>


#include "PatchItem.h"
#include "ProblemDetails.h"
#include "SubscriptionData.h"
#include <string>
#include <vector>

namespace oai {
namespace nrf {
namespace api {

using namespace oai::nrf::model;

class  SubscriptionIDDocumentApi {
public:
    SubscriptionIDDocumentApi(std::shared_ptr<Pistache::Rest::Router>);
    virtual ~SubscriptionIDDocumentApi() {}
    void init();

    const std::string base = "/nnrf-nfm/";

private:
    void setupRoutes();

    void remove_subscription_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void update_subscription_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void subscription_id_document_api_default_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);

    std::shared_ptr<Pistache::Rest::Router> router;

    /// <summary>
    /// Deletes a subscription
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="subscriptionID">Unique ID of the subscription to remove</param>
    virtual void remove_subscription(const std::string &subscriptionID, Pistache::Http::ResponseWriter &response) = 0;

    /// <summary>
    /// Updates a subscription
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="subscriptionID">Unique ID of the subscription to update</param>
    /// <param name="patchItem"></param>
    virtual void update_subscription(const std::string &subscriptionID, const std::vector<PatchItem> &patchItem, Pistache::Http::ResponseWriter &response) = 0;

};

}
}
}

#endif /* SubscriptionIDDocumentApi_H_ */

