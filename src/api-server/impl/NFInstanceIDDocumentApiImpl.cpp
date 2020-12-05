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

namespace oai {
namespace nrf {
namespace api {

using namespace oai::nrf::model;

NFInstanceIDDocumentApiImpl::NFInstanceIDDocumentApiImpl(std::shared_ptr<Pistache::Rest::Router> rtr,
                                                         oai::nrf::nrf_app *nrf_app_inst,
                                                             std::string address)
    : NFInstanceIDDocumentApi(rtr), m_nrf_app(nrf_app_inst),
      m_address(address)
    { }

void NFInstanceIDDocumentApiImpl::deregister_nf_instance(const std::string &nfInstanceID, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void NFInstanceIDDocumentApiImpl::get_nf_instance(const std::string &nfInstanceID, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void NFInstanceIDDocumentApiImpl::register_nf_instance(const std::string &nfInstanceID, const NFProfile &nFProfile, const Pistache::Optional<Pistache::Http::Header::Raw> &contentEncoding, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}
void NFInstanceIDDocumentApiImpl::update_nf_instance(const std::string &nfInstanceID, const std::vector<PatchItem> &patchItem, Pistache::Http::ResponseWriter &response) {
    response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}

}
}
}

