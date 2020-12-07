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
 * NwdafInfo.h
 *
 * 
 */

#ifndef NwdafInfo_H_
#define NwdafInfo_H_


#include "Tai.h"
#include "NwdafEvent.h"
#include "EventId.h"
#include "TaiRange.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class  NwdafInfo
{
public:
    NwdafInfo();
    virtual ~NwdafInfo();

    void validate();

    /////////////////////////////////////////////
    /// NwdafInfo members

    /// <summary>
    /// 
    /// </summary>
    std::vector<EventId>& getEventIds();
    void setEventIds(std::vector<EventId> const& value);
    bool eventIdsIsSet() const;
    void unsetEventIds();
    /// <summary>
    /// 
    /// </summary>
    std::vector<NwdafEvent>& getNwdafEvents();
    void setNwdafEvents(std::vector<NwdafEvent> const& value);
    bool nwdafEventsIsSet() const;
    void unsetNwdafEvents();
    /// <summary>
    /// 
    /// </summary>
    std::vector<Tai>& getTaiList();
    void setTaiList(std::vector<Tai> const& value);
    bool taiListIsSet() const;
    void unsetTaiList();
    /// <summary>
    /// 
    /// </summary>
    std::vector<TaiRange>& getTaiRangeList();
    void setTaiRangeList(std::vector<TaiRange> const& value);
    bool taiRangeListIsSet() const;
    void unsetTaiRangeList();

    friend void to_json(nlohmann::json& j, const NwdafInfo& o);
    friend void from_json(const nlohmann::json& j, NwdafInfo& o);
protected:
    std::vector<EventId> m_EventIds;
    bool m_EventIdsIsSet;
    std::vector<NwdafEvent> m_NwdafEvents;
    bool m_NwdafEventsIsSet;
    std::vector<Tai> m_TaiList;
    bool m_TaiListIsSet;
    std::vector<TaiRange> m_TaiRangeList;
    bool m_TaiRangeListIsSet;
};

}
}
}

#endif /* NwdafInfo_H_ */
