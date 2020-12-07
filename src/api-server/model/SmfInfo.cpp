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


#include "SmfInfo.h"

namespace oai {
namespace nrf {
namespace model {

SmfInfo::SmfInfo()
{
    m_TaiListIsSet = false;
    m_TaiRangeListIsSet = false;
    m_PgwFqdn = "";
    m_PgwFqdnIsSet = false;
    m_AccessTypeIsSet = false;
    
}

SmfInfo::~SmfInfo()
{
}

void SmfInfo::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const SmfInfo& o)
{
    j = nlohmann::json();
    j["sNssaiSmfInfoList"] = o.m_SNssaiSmfInfoList;
    if(o.taiListIsSet() || !o.m_TaiList.empty())
        j["taiList"] = o.m_TaiList;
    if(o.taiRangeListIsSet() || !o.m_TaiRangeList.empty())
        j["taiRangeList"] = o.m_TaiRangeList;
    if(o.pgwFqdnIsSet())
        j["pgwFqdn"] = o.m_PgwFqdn;
    if(o.accessTypeIsSet() || !o.m_AccessType.empty())
        j["accessType"] = o.m_AccessType;
}

void from_json(const nlohmann::json& j, SmfInfo& o)
{
    j.at("sNssaiSmfInfoList").get_to(o.m_SNssaiSmfInfoList);
    if(j.find("taiList") != j.end())
    {
        j.at("taiList").get_to(o.m_TaiList);
        o.m_TaiListIsSet = true;
    } 
    if(j.find("taiRangeList") != j.end())
    {
        j.at("taiRangeList").get_to(o.m_TaiRangeList);
        o.m_TaiRangeListIsSet = true;
    } 
    if(j.find("pgwFqdn") != j.end())
    {
        j.at("pgwFqdn").get_to(o.m_PgwFqdn);
        o.m_PgwFqdnIsSet = true;
    } 
    if(j.find("accessType") != j.end())
    {
        j.at("accessType").get_to(o.m_AccessType);
        o.m_AccessTypeIsSet = true;
    } 
}

std::vector<SnssaiSmfInfoItem>& SmfInfo::getSNssaiSmfInfoList()
{
    return m_SNssaiSmfInfoList;
}
void SmfInfo::setSNssaiSmfInfoList(std::vector<SnssaiSmfInfoItem> const& value)
{
    m_SNssaiSmfInfoList = value;
}
std::vector<Tai>& SmfInfo::getTaiList()
{
    return m_TaiList;
}
void SmfInfo::setTaiList(std::vector<Tai> const& value)
{
    m_TaiList = value;
    m_TaiListIsSet = true;
}
bool SmfInfo::taiListIsSet() const
{
    return m_TaiListIsSet;
}
void SmfInfo::unsetTaiList()
{
    m_TaiListIsSet = false;
}
std::vector<TaiRange>& SmfInfo::getTaiRangeList()
{
    return m_TaiRangeList;
}
void SmfInfo::setTaiRangeList(std::vector<TaiRange> const& value)
{
    m_TaiRangeList = value;
    m_TaiRangeListIsSet = true;
}
bool SmfInfo::taiRangeListIsSet() const
{
    return m_TaiRangeListIsSet;
}
void SmfInfo::unsetTaiRangeList()
{
    m_TaiRangeListIsSet = false;
}
std::string SmfInfo::getPgwFqdn() const
{
    return m_PgwFqdn;
}
void SmfInfo::setPgwFqdn(std::string const& value)
{
    m_PgwFqdn = value;
    m_PgwFqdnIsSet = true;
}
bool SmfInfo::pgwFqdnIsSet() const
{
    return m_PgwFqdnIsSet;
}
void SmfInfo::unsetPgwFqdn()
{
    m_PgwFqdnIsSet = false;
}
std::vector<AccessType>& SmfInfo::getAccessType()
{
    return m_AccessType;
}
void SmfInfo::setAccessType(std::vector<AccessType> const& value)
{
    m_AccessType = value;
    m_AccessTypeIsSet = true;
}
bool SmfInfo::accessTypeIsSet() const
{
    return m_AccessTypeIsSet;
}
void SmfInfo::unsetAccessType()
{
    m_AccessTypeIsSet = false;
}

}
}
}

