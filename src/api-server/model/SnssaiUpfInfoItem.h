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
 * SnssaiUpfInfoItem.h
 *
 * 
 */

#ifndef SnssaiUpfInfoItem_H_
#define SnssaiUpfInfoItem_H_


#include "DnnUpfInfoItem.h"
#include "Snssai.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class  SnssaiUpfInfoItem
{
public:
    SnssaiUpfInfoItem();
    virtual ~SnssaiUpfInfoItem();

    void validate();

    /////////////////////////////////////////////
    /// SnssaiUpfInfoItem members

    /// <summary>
    /// 
    /// </summary>
    Snssai getSNssai() const;
    void setSNssai(Snssai const& value);
    /// <summary>
    /// 
    /// </summary>
    std::vector<DnnUpfInfoItem>& getDnnUpfInfoList();
    void setDnnUpfInfoList(std::vector<DnnUpfInfoItem> const& value);

    friend void to_json(nlohmann::json& j, const SnssaiUpfInfoItem& o);
    friend void from_json(const nlohmann::json& j, SnssaiUpfInfoItem& o);
protected:
    Snssai m_SNssai;

    std::vector<DnnUpfInfoItem> m_DnnUpfInfoList;

};

}
}
}

#endif /* SnssaiUpfInfoItem_H_ */
