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
 * CompleteStoredSearchDocumentApi.h
 *
 * 
 */

#ifndef CompleteStoredSearchDocumentApi_H_
#define CompleteStoredSearchDocumentApi_H_


#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>


#include "StoredSearchResult.h"
#include <string>

namespace oai {
namespace nrf {
namespace api {

using namespace oai::nrf::model;

class  CompleteStoredSearchDocumentApi {
public:
    CompleteStoredSearchDocumentApi(std::shared_ptr<Pistache::Rest::Router>);
    virtual ~CompleteStoredSearchDocumentApi() {}
    void init();

    const std::string base = "/nnrf-disc/v1";

private:
    void setupRoutes();

    void retrieve_complete_search_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void complete_stored_search_document_api_default_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);

    std::shared_ptr<Pistache::Rest::Router> router;

    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="searchId">Id of a stored search</param>
    virtual void retrieve_complete_search(const std::string &searchId, Pistache::Http::ResponseWriter &response) = 0;

};

}
}
}

#endif /* CompleteStoredSearchDocumentApi_H_ */

