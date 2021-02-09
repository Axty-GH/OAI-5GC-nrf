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
 * DnnSmfInfoItem.h
 *
 * 
 */

#ifndef DnnSmfInfoItem_H_
#define DnnSmfInfoItem_H_

#include <string>
#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class DnnSmfInfoItem {
 public:
  DnnSmfInfoItem();
  virtual ~DnnSmfInfoItem();

  void validate();

  /////////////////////////////////////////////
  /// DnnSmfInfoItem members

  /// <summary>
  /// 
  /// </summary>
  std::string getDnn() const;
  void setDnn(std::string const &value);

  friend void to_json(nlohmann::json &j, const DnnSmfInfoItem &o);
  friend void from_json(const nlohmann::json &j, DnnSmfInfoItem &o);
 protected:
  std::string m_Dnn;

};

}
}
}

#endif /* DnnSmfInfoItem_H_ */
