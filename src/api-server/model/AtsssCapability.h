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
 * AtsssCapability.h
 *
 * 
 */

#ifndef AtsssCapability_H_
#define AtsssCapability_H_

#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class AtsssCapability {
 public:
  AtsssCapability();
  virtual ~AtsssCapability();

  void validate();

  /////////////////////////////////////////////
  /// AtsssCapability members

  /// <summary>
  /// 
  /// </summary>
  bool isAtsssLL() const;
  void setAtsssLL(bool const value);
  bool atsssLLIsSet() const;
  void unsetAtsssLL();
  /// <summary>
  /// 
  /// </summary>
  bool isMptcp() const;
  void setMptcp(bool const value);
  bool mptcpIsSet() const;
  void unsetMptcp();

  friend void to_json(nlohmann::json &j, const AtsssCapability &o);
  friend void from_json(const nlohmann::json &j, AtsssCapability &o);
 protected:
  bool m_AtsssLL;
  bool m_AtsssLLIsSet;
  bool m_Mptcp;
  bool m_MptcpIsSet;
};

}
}
}

#endif /* AtsssCapability_H_ */
