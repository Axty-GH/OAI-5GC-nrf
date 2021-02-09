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

#include "ChfServiceInfo.h"

namespace oai {
namespace nrf {
namespace model {

ChfServiceInfo::ChfServiceInfo() {
  m_PrimaryChfServiceInstance = "";
  m_PrimaryChfServiceInstanceIsSet = false;
  m_SecondaryChfServiceInstance = "";
  m_SecondaryChfServiceInstanceIsSet = false;

}

ChfServiceInfo::~ChfServiceInfo() {
}

void ChfServiceInfo::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json &j, const ChfServiceInfo &o) {
  j = nlohmann::json();
  if (o.primaryChfServiceInstanceIsSet())
    j["primaryChfServiceInstance"] = o.m_PrimaryChfServiceInstance;
  if (o.secondaryChfServiceInstanceIsSet())
    j["secondaryChfServiceInstance"] = o.m_SecondaryChfServiceInstance;
}

void from_json(const nlohmann::json &j, ChfServiceInfo &o) {
  if (j.find("primaryChfServiceInstance") != j.end()) {
    j.at("primaryChfServiceInstance").get_to(o.m_PrimaryChfServiceInstance);
    o.m_PrimaryChfServiceInstanceIsSet = true;
  }
  if (j.find("secondaryChfServiceInstance") != j.end()) {
    j.at("secondaryChfServiceInstance").get_to(o.m_SecondaryChfServiceInstance);
    o.m_SecondaryChfServiceInstanceIsSet = true;
  }
}

std::string ChfServiceInfo::getPrimaryChfServiceInstance() const {
  return m_PrimaryChfServiceInstance;
}
void ChfServiceInfo::setPrimaryChfServiceInstance(std::string const &value) {
  m_PrimaryChfServiceInstance = value;
  m_PrimaryChfServiceInstanceIsSet = true;
}
bool ChfServiceInfo::primaryChfServiceInstanceIsSet() const {
  return m_PrimaryChfServiceInstanceIsSet;
}
void ChfServiceInfo::unsetPrimaryChfServiceInstance() {
  m_PrimaryChfServiceInstanceIsSet = false;
}
std::string ChfServiceInfo::getSecondaryChfServiceInstance() const {
  return m_SecondaryChfServiceInstance;
}
void ChfServiceInfo::setSecondaryChfServiceInstance(std::string const &value) {
  m_SecondaryChfServiceInstance = value;
  m_SecondaryChfServiceInstanceIsSet = true;
}
bool ChfServiceInfo::secondaryChfServiceInstanceIsSet() const {
  return m_SecondaryChfServiceInstanceIsSet;
}
void ChfServiceInfo::unsetSecondaryChfServiceInstance() {
  m_SecondaryChfServiceInstanceIsSet = false;
}

}
}
}

