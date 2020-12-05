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
 * SnssaiSmfInfoItem.h
 *
 * 
 */

#ifndef SnssaiSmfInfoItem_H_
#define SnssaiSmfInfoItem_H_


#include "DnnSmfInfoItem.h"
#include "Snssai.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class  SnssaiSmfInfoItem
{
public:
    SnssaiSmfInfoItem();
    virtual ~SnssaiSmfInfoItem();

    void validate();

    /////////////////////////////////////////////
    /// SnssaiSmfInfoItem members

    /// <summary>
    /// 
    /// </summary>
    Snssai getSNssai() const;
    void setSNssai(Snssai const& value);
    /// <summary>
    /// 
    /// </summary>
    std::vector<DnnSmfInfoItem>& getDnnSmfInfoList();
    void setDnnSmfInfoList(std::vector<DnnSmfInfoItem> const& value);

    friend void to_json(nlohmann::json& j, const SnssaiSmfInfoItem& o);
    friend void from_json(const nlohmann::json& j, SnssaiSmfInfoItem& o);
protected:
    Snssai m_SNssai;

    std::vector<DnnSmfInfoItem> m_DnnSmfInfoList;

};

}
}
}

#endif /* SnssaiSmfInfoItem_H_ */
