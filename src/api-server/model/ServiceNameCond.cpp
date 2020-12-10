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

#include "ServiceNameCond.h"

namespace oai {
namespace nrf {
namespace model {

ServiceNameCond::ServiceNameCond() {

}

ServiceNameCond::~ServiceNameCond() {
}

void ServiceNameCond::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json &j, const ServiceNameCond &o) {
  j = nlohmann::json();
  j["serviceName"] = o.m_ServiceName;
}

void from_json(const nlohmann::json &j, ServiceNameCond &o) {
  j.at("serviceName").get_to(o.m_ServiceName);
}

ServiceName ServiceNameCond::getServiceName() const {
  return m_ServiceName;
}
void ServiceNameCond::setServiceName(ServiceName const &value) {
  m_ServiceName = value;
}

}
}
}

