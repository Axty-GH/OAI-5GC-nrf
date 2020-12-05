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
 * UdmInfo.h
 *
 * 
 */

#ifndef UdmInfo_H_
#define UdmInfo_H_


#include "IdentityRange.h"
#include "SupiRange.h"
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class  UdmInfo
{
public:
    UdmInfo();
    virtual ~UdmInfo();

    void validate();

    /////////////////////////////////////////////
    /// UdmInfo members

    /// <summary>
    /// 
    /// </summary>
    std::string getGroupId() const;
    void setGroupId(std::string const& value);
    bool groupIdIsSet() const;
    void unsetGroupId();
    /// <summary>
    /// 
    /// </summary>
    std::vector<SupiRange>& getSupiRanges();
    void setSupiRanges(std::vector<SupiRange> const& value);
    bool supiRangesIsSet() const;
    void unsetSupiRanges();
    /// <summary>
    /// 
    /// </summary>
    std::vector<IdentityRange>& getGpsiRanges();
    void setGpsiRanges(std::vector<IdentityRange> const& value);
    bool gpsiRangesIsSet() const;
    void unsetGpsiRanges();
    /// <summary>
    /// 
    /// </summary>
    std::vector<IdentityRange>& getExternalGroupIdentifiersRanges();
    void setExternalGroupIdentifiersRanges(std::vector<IdentityRange> const& value);
    bool externalGroupIdentifiersRangesIsSet() const;
    void unsetExternalGroupIdentifiersRanges();
    /// <summary>
    /// 
    /// </summary>
    std::vector<std::string>& getRoutingIndicators();
    void setRoutingIndicators(std::vector<std::string> const& value);
    bool routingIndicatorsIsSet() const;
    void unsetRoutingIndicators();

    friend void to_json(nlohmann::json& j, const UdmInfo& o);
    friend void from_json(const nlohmann::json& j, UdmInfo& o);
protected:
    std::string m_GroupId;
    bool m_GroupIdIsSet;
    std::vector<SupiRange> m_SupiRanges;
    bool m_SupiRangesIsSet;
    std::vector<IdentityRange> m_GpsiRanges;
    bool m_GpsiRangesIsSet;
    std::vector<IdentityRange> m_ExternalGroupIdentifiersRanges;
    bool m_ExternalGroupIdentifiersRangesIsSet;
    std::vector<std::string> m_RoutingIndicators;
    bool m_RoutingIndicatorsIsSet;
};

}
}
}

#endif /* UdmInfo_H_ */
