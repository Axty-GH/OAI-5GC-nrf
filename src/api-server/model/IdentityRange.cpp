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

#include "IdentityRange.h"

namespace oai {
namespace nrf {
namespace model {

IdentityRange::IdentityRange() {
  m_Start = "";
  m_StartIsSet = false;
  m_End = "";
  m_EndIsSet = false;
  m_Pattern = "";
  m_PatternIsSet = false;

}

IdentityRange::~IdentityRange() {
}

void IdentityRange::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json &j, const IdentityRange &o) {
  j = nlohmann::json();
  if (o.startIsSet())
    j["start"] = o.m_Start;
  if (o.endIsSet())
    j["end"] = o.m_End;
  if (o.patternIsSet())
    j["pattern"] = o.m_Pattern;
}

void from_json(const nlohmann::json &j, IdentityRange &o) {
  if (j.find("start") != j.end()) {
    j.at("start").get_to(o.m_Start);
    o.m_StartIsSet = true;
  }
  if (j.find("end") != j.end()) {
    j.at("end").get_to(o.m_End);
    o.m_EndIsSet = true;
  }
  if (j.find("pattern") != j.end()) {
    j.at("pattern").get_to(o.m_Pattern);
    o.m_PatternIsSet = true;
  }
}

std::string IdentityRange::getStart() const {
  return m_Start;
}
void IdentityRange::setStart(std::string const &value) {
  m_Start = value;
  m_StartIsSet = true;
}
bool IdentityRange::startIsSet() const {
  return m_StartIsSet;
}
void IdentityRange::unsetStart() {
  m_StartIsSet = false;
}
std::string IdentityRange::getEnd() const {
  return m_End;
}
void IdentityRange::setEnd(std::string const &value) {
  m_End = value;
  m_EndIsSet = true;
}
bool IdentityRange::endIsSet() const {
  return m_EndIsSet;
}
void IdentityRange::unsetEnd() {
  m_EndIsSet = false;
}
std::string IdentityRange::getPattern() const {
  return m_Pattern;
}
void IdentityRange::setPattern(std::string const &value) {
  m_Pattern = value;
  m_PatternIsSet = true;
}
bool IdentityRange::patternIsSet() const {
  return m_PatternIsSet;
}
void IdentityRange::unsetPattern() {
  m_PatternIsSet = false;
}

}
}
}

