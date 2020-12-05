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
 * Ipv6Addr.h
 *
 * 
 */

#ifndef Ipv6Addr_H_
#define Ipv6Addr_H_


#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class  Ipv6Addr
{
public:
    Ipv6Addr();
    virtual ~Ipv6Addr();

    void validate();

    /////////////////////////////////////////////
    /// Ipv6Addr members


    friend void to_json(nlohmann::json& j, const Ipv6Addr& o);
    friend void from_json(const nlohmann::json& j, Ipv6Addr& o);
protected:
};

}
}
}

#endif /* Ipv6Addr_H_ */
