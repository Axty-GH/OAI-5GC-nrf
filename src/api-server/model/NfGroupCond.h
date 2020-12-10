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
 * NfGroupCond.h
 *
 * 
 */

#ifndef NfGroupCond_H_
#define NfGroupCond_H_

#include <string>
#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class NfGroupCond {
 public:
  NfGroupCond();
  virtual ~NfGroupCond();

  void validate();

  /////////////////////////////////////////////
  /// NfGroupCond members

  /// <summary>
  /// 
  /// </summary>
  std::string getNfType() const;
  void setNfType(std::string const &value);
  /// <summary>
  /// 
  /// </summary>
  std::string getNfGroupId() const;
  void setNfGroupId(std::string const &value);

  friend void to_json(nlohmann::json &j, const NfGroupCond &o);
  friend void from_json(const nlohmann::json &j, NfGroupCond &o);
 protected:
  std::string m_NfType;

  std::string m_NfGroupId;

};

}
}
}

#endif /* NfGroupCond_H_ */
