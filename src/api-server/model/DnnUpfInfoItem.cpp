/**
 * NRF NFManagement Service
 * NRF NFManagement Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "DnnUpfInfoItem.h"

namespace oai {
namespace nrf {
namespace model {

DnnUpfInfoItem::DnnUpfInfoItem() {
  m_Dnn                  = "";
  m_DnaiListIsSet        = false;
  m_PduSessionTypesIsSet = false;
}

DnnUpfInfoItem::~DnnUpfInfoItem() {}

void DnnUpfInfoItem::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const DnnUpfInfoItem& o) {
  j        = nlohmann::json();
  j["dnn"] = o.m_Dnn;
  if (o.dnaiListIsSet() || !o.m_DnaiList.empty()) j["dnaiList"] = o.m_DnaiList;
  if (o.pduSessionTypesIsSet() || !o.m_PduSessionTypes.empty())
    j["pduSessionTypes"] = o.m_PduSessionTypes;
  if (o.dnaiNwInstanceListIsSet() || !o.m_DnaiNwInstanceList.empty())
    j["dnaiNwInstanceList"] = o.m_DnaiNwInstanceList;
}

void from_json(const nlohmann::json& j, DnnUpfInfoItem& o) {
  j.at("dnn").get_to(o.m_Dnn);
  if (j.find("dnaiList") != j.end()) {
    j.at("dnaiList").get_to(o.m_DnaiList);
    o.m_DnaiListIsSet = true;
  }
  if (j.find("pduSessionTypes") != j.end()) {
    j.at("pduSessionTypes").get_to(o.m_PduSessionTypes);
    o.m_PduSessionTypesIsSet = true;
  }
  if (j.find("dnaiNwInstanceList") != j.end()) {
    j.at("dnaiNwInstanceList").get_to(o.m_DnaiNwInstanceList);
    o.m_DnaiNwInstanceListIsSet = true;
  }
}

std::string DnnUpfInfoItem::getDnn() const {
  return m_Dnn;
}
void DnnUpfInfoItem::setDnn(std::string const& value) {
  m_Dnn = value;
}
std::vector<std::string>& DnnUpfInfoItem::getDnaiList() {
  return m_DnaiList;
}
void DnnUpfInfoItem::setDnaiList(std::vector<std::string> const& value) {
  m_DnaiList      = value;
  m_DnaiListIsSet = true;
}
bool DnnUpfInfoItem::dnaiListIsSet() const {
  return m_DnaiListIsSet;
}
void DnnUpfInfoItem::unsetDnaiList() {
  m_DnaiListIsSet = false;
}
std::vector<PduSessionType>& DnnUpfInfoItem::getPduSessionTypes() {
  return m_PduSessionTypes;
}
void DnnUpfInfoItem::setPduSessionTypes(
    std::vector<PduSessionType> const& value) {
  m_PduSessionTypes      = value;
  m_PduSessionTypesIsSet = true;
}
bool DnnUpfInfoItem::pduSessionTypesIsSet() const {
  return m_PduSessionTypesIsSet;
}
void DnnUpfInfoItem::unsetPduSessionTypes() {
  m_PduSessionTypesIsSet = false;
}

std::map<std::string, std::string>& DnnUpfInfoItem::getDnaiNwInstanceList() {
  return m_DnaiNwInstanceList;
}
void DnnUpfInfoItem::setDnaiNwInstanceList(
    std::map<std::string, std::string> const& value) {
  m_DnaiNwInstanceList      = value;
  m_DnaiNwInstanceListIsSet = true;
}
bool DnnUpfInfoItem::dnaiNwInstanceListIsSet() const {
  return m_DnaiNwInstanceListIsSet;
}
void DnnUpfInfoItem::unserDnaiNwInstanceList() {
  m_DnaiNwInstanceListIsSet = false;
}

}  // namespace model
}  // namespace nrf
}  // namespace oai
