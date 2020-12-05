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


#include "BsfInfo.h"

namespace oai {
namespace nrf {
namespace model {

BsfInfo::BsfInfo()
{
    m_DnnListIsSet = false;
    m_IpDomainListIsSet = false;
    m_Ipv4AddressRangesIsSet = false;
    m_Ipv6PrefixRangesIsSet = false;
    
}

BsfInfo::~BsfInfo()
{
}

void BsfInfo::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const BsfInfo& o)
{
    j = nlohmann::json();
    if(o.dnnListIsSet() || !o.m_DnnList.empty())
        j["dnnList"] = o.m_DnnList;
    if(o.ipDomainListIsSet() || !o.m_IpDomainList.empty())
        j["ipDomainList"] = o.m_IpDomainList;
    if(o.ipv4AddressRangesIsSet() || !o.m_Ipv4AddressRanges.empty())
        j["ipv4AddressRanges"] = o.m_Ipv4AddressRanges;
    if(o.ipv6PrefixRangesIsSet() || !o.m_Ipv6PrefixRanges.empty())
        j["ipv6PrefixRanges"] = o.m_Ipv6PrefixRanges;
}

void from_json(const nlohmann::json& j, BsfInfo& o)
{
    if(j.find("dnnList") != j.end())
    {
        j.at("dnnList").get_to(o.m_DnnList);
        o.m_DnnListIsSet = true;
    } 
    if(j.find("ipDomainList") != j.end())
    {
        j.at("ipDomainList").get_to(o.m_IpDomainList);
        o.m_IpDomainListIsSet = true;
    } 
    if(j.find("ipv4AddressRanges") != j.end())
    {
        j.at("ipv4AddressRanges").get_to(o.m_Ipv4AddressRanges);
        o.m_Ipv4AddressRangesIsSet = true;
    } 
    if(j.find("ipv6PrefixRanges") != j.end())
    {
        j.at("ipv6PrefixRanges").get_to(o.m_Ipv6PrefixRanges);
        o.m_Ipv6PrefixRangesIsSet = true;
    } 
}

std::vector<std::string>& BsfInfo::getDnnList()
{
    return m_DnnList;
}
void BsfInfo::setDnnList(std::vector<std::string> const& value)
{
    m_DnnList = value;
    m_DnnListIsSet = true;
}
bool BsfInfo::dnnListIsSet() const
{
    return m_DnnListIsSet;
}
void BsfInfo::unsetDnnList()
{
    m_DnnListIsSet = false;
}
std::vector<std::string>& BsfInfo::getIpDomainList()
{
    return m_IpDomainList;
}
void BsfInfo::setIpDomainList(std::vector<std::string> const& value)
{
    m_IpDomainList = value;
    m_IpDomainListIsSet = true;
}
bool BsfInfo::ipDomainListIsSet() const
{
    return m_IpDomainListIsSet;
}
void BsfInfo::unsetIpDomainList()
{
    m_IpDomainListIsSet = false;
}
std::vector<Ipv4AddressRange>& BsfInfo::getIpv4AddressRanges()
{
    return m_Ipv4AddressRanges;
}
void BsfInfo::setIpv4AddressRanges(std::vector<Ipv4AddressRange> const& value)
{
    m_Ipv4AddressRanges = value;
    m_Ipv4AddressRangesIsSet = true;
}
bool BsfInfo::ipv4AddressRangesIsSet() const
{
    return m_Ipv4AddressRangesIsSet;
}
void BsfInfo::unsetIpv4AddressRanges()
{
    m_Ipv4AddressRangesIsSet = false;
}
std::vector<Ipv6PrefixRange>& BsfInfo::getIpv6PrefixRanges()
{
    return m_Ipv6PrefixRanges;
}
void BsfInfo::setIpv6PrefixRanges(std::vector<Ipv6PrefixRange> const& value)
{
    m_Ipv6PrefixRanges = value;
    m_Ipv6PrefixRangesIsSet = true;
}
bool BsfInfo::ipv6PrefixRangesIsSet() const
{
    return m_Ipv6PrefixRangesIsSet;
}
void BsfInfo::unsetIpv6PrefixRanges()
{
    m_Ipv6PrefixRangesIsSet = false;
}

}
}
}

