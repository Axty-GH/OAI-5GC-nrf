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
 * DnnUpfInfoItem.h
 *
 * 
 */

#ifndef DnnUpfInfoItem_H_
#define DnnUpfInfoItem_H_


#include <string>
#include "PduSessionType.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class  DnnUpfInfoItem
{
public:
    DnnUpfInfoItem();
    virtual ~DnnUpfInfoItem();

    void validate();

    /////////////////////////////////////////////
    /// DnnUpfInfoItem members

    /// <summary>
    /// 
    /// </summary>
    std::string getDnn() const;
    void setDnn(std::string const& value);
    /// <summary>
    /// 
    /// </summary>
    std::vector<std::string>& getDnaiList();
    void setDnaiList(std::vector<std::string> const& value);
    bool dnaiListIsSet() const;
    void unsetDnaiList();
    /// <summary>
    /// 
    /// </summary>
    std::vector<PduSessionType>& getPduSessionTypes();
    void setPduSessionTypes(std::vector<PduSessionType> const& value);
    bool pduSessionTypesIsSet() const;
    void unsetPduSessionTypes();

    friend void to_json(nlohmann::json& j, const DnnUpfInfoItem& o);
    friend void from_json(const nlohmann::json& j, DnnUpfInfoItem& o);
protected:
    std::string m_Dnn;

    std::vector<std::string> m_DnaiList;
    bool m_DnaiListIsSet;
    std::vector<PduSessionType> m_PduSessionTypes;
    bool m_PduSessionTypesIsSet;
};

}
}
}

#endif /* DnnUpfInfoItem_H_ */
