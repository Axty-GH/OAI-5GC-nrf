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
 * NFStatus.h
 *
 * 
 */

#ifndef NFStatus_H_
#define NFStatus_H_


#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class  NFStatus
{
public:
    NFStatus();
    virtual ~NFStatus();

    void validate();

    /////////////////////////////////////////////
    /// NFStatus members


    friend void to_json(nlohmann::json& j, const NFStatus& o);
    friend void from_json(const nlohmann::json& j, NFStatus& o);
protected:
};

}
}
}

#endif /* NFStatus_H_ */
