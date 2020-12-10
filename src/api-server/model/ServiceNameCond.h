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
 * ServiceNameCond.h
 *
 * 
 */

#ifndef ServiceNameCond_H_
#define ServiceNameCond_H_

#include "ServiceName.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class ServiceNameCond {
 public:
  ServiceNameCond();
  virtual ~ServiceNameCond();

  void validate();

  /////////////////////////////////////////////
  /// ServiceNameCond members

  /// <summary>
  /// 
  /// </summary>
  ServiceName getServiceName() const;
  void setServiceName(ServiceName const &value);

  friend void to_json(nlohmann::json &j, const ServiceNameCond &o);
  friend void from_json(const nlohmann::json &j, ServiceNameCond &o);
 protected:
  ServiceName m_ServiceName;

};

}
}
}

#endif /* ServiceNameCond_H_ */
