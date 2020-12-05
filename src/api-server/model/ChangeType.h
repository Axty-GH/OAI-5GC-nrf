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
 * ChangeType.h
 *
 * 
 */

#ifndef ChangeType_H_
#define ChangeType_H_


#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class  ChangeType
{
public:
    ChangeType();
    virtual ~ChangeType();

    void validate();

    /////////////////////////////////////////////
    /// ChangeType members


    friend void to_json(nlohmann::json& j, const ChangeType& o);
    friend void from_json(const nlohmann::json& j, ChangeType& o);
protected:
};

}
}
}

#endif /* ChangeType_H_ */
