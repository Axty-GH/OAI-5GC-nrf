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


#include "PcfInfo.h"

namespace oai {
namespace nrf {
namespace model {

PcfInfo::PcfInfo()
{
    m_GroupId = "";
    m_GroupIdIsSet = false;
    m_DnnListIsSet = false;
    m_SupiRangesIsSet = false;
    m_GpsiRangesIsSet = false;
    m_RxDiamHost = "";
    m_RxDiamHostIsSet = false;
    m_RxDiamRealm = "";
    m_RxDiamRealmIsSet = false;
    
}

PcfInfo::~PcfInfo()
{
}

void PcfInfo::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const PcfInfo& o)
{
    j = nlohmann::json();
    if(o.groupIdIsSet())
        j["groupId"] = o.m_GroupId;
    if(o.dnnListIsSet() || !o.m_DnnList.empty())
        j["dnnList"] = o.m_DnnList;
    if(o.supiRangesIsSet() || !o.m_SupiRanges.empty())
        j["supiRanges"] = o.m_SupiRanges;
    if(o.gpsiRangesIsSet() || !o.m_GpsiRanges.empty())
        j["gpsiRanges"] = o.m_GpsiRanges;
    if(o.rxDiamHostIsSet())
        j["rxDiamHost"] = o.m_RxDiamHost;
    if(o.rxDiamRealmIsSet())
        j["rxDiamRealm"] = o.m_RxDiamRealm;
}

void from_json(const nlohmann::json& j, PcfInfo& o)
{
    if(j.find("groupId") != j.end())
    {
        j.at("groupId").get_to(o.m_GroupId);
        o.m_GroupIdIsSet = true;
    } 
    if(j.find("dnnList") != j.end())
    {
        j.at("dnnList").get_to(o.m_DnnList);
        o.m_DnnListIsSet = true;
    } 
    if(j.find("supiRanges") != j.end())
    {
        j.at("supiRanges").get_to(o.m_SupiRanges);
        o.m_SupiRangesIsSet = true;
    } 
    if(j.find("gpsiRanges") != j.end())
    {
        j.at("gpsiRanges").get_to(o.m_GpsiRanges);
        o.m_GpsiRangesIsSet = true;
    } 
    if(j.find("rxDiamHost") != j.end())
    {
        j.at("rxDiamHost").get_to(o.m_RxDiamHost);
        o.m_RxDiamHostIsSet = true;
    } 
    if(j.find("rxDiamRealm") != j.end())
    {
        j.at("rxDiamRealm").get_to(o.m_RxDiamRealm);
        o.m_RxDiamRealmIsSet = true;
    } 
}

std::string PcfInfo::getGroupId() const
{
    return m_GroupId;
}
void PcfInfo::setGroupId(std::string const& value)
{
    m_GroupId = value;
    m_GroupIdIsSet = true;
}
bool PcfInfo::groupIdIsSet() const
{
    return m_GroupIdIsSet;
}
void PcfInfo::unsetGroupId()
{
    m_GroupIdIsSet = false;
}
std::vector<std::string>& PcfInfo::getDnnList()
{
    return m_DnnList;
}
void PcfInfo::setDnnList(std::vector<std::string> const& value)
{
    m_DnnList = value;
    m_DnnListIsSet = true;
}
bool PcfInfo::dnnListIsSet() const
{
    return m_DnnListIsSet;
}
void PcfInfo::unsetDnnList()
{
    m_DnnListIsSet = false;
}
std::vector<SupiRange>& PcfInfo::getSupiRanges()
{
    return m_SupiRanges;
}
void PcfInfo::setSupiRanges(std::vector<SupiRange> const& value)
{
    m_SupiRanges = value;
    m_SupiRangesIsSet = true;
}
bool PcfInfo::supiRangesIsSet() const
{
    return m_SupiRangesIsSet;
}
void PcfInfo::unsetSupiRanges()
{
    m_SupiRangesIsSet = false;
}
std::vector<IdentityRange>& PcfInfo::getGpsiRanges()
{
    return m_GpsiRanges;
}
void PcfInfo::setGpsiRanges(std::vector<IdentityRange> const& value)
{
    m_GpsiRanges = value;
    m_GpsiRangesIsSet = true;
}
bool PcfInfo::gpsiRangesIsSet() const
{
    return m_GpsiRangesIsSet;
}
void PcfInfo::unsetGpsiRanges()
{
    m_GpsiRangesIsSet = false;
}
std::string PcfInfo::getRxDiamHost() const
{
    return m_RxDiamHost;
}
void PcfInfo::setRxDiamHost(std::string const& value)
{
    m_RxDiamHost = value;
    m_RxDiamHostIsSet = true;
}
bool PcfInfo::rxDiamHostIsSet() const
{
    return m_RxDiamHostIsSet;
}
void PcfInfo::unsetRxDiamHost()
{
    m_RxDiamHostIsSet = false;
}
std::string PcfInfo::getRxDiamRealm() const
{
    return m_RxDiamRealm;
}
void PcfInfo::setRxDiamRealm(std::string const& value)
{
    m_RxDiamRealm = value;
    m_RxDiamRealmIsSet = true;
}
bool PcfInfo::rxDiamRealmIsSet() const
{
    return m_RxDiamRealmIsSet;
}
void PcfInfo::unsetRxDiamRealm()
{
    m_RxDiamRealmIsSet = false;
}

}
}
}

