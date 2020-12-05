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


#include "N2InterfaceAmfInfo.h"

namespace oai {
namespace nrf {
namespace model {

N2InterfaceAmfInfo::N2InterfaceAmfInfo()
{
    m_Ipv4EndpointAddressIsSet = false;
    m_Ipv6EndpointAddressIsSet = false;
    m_AmfName = "";
    m_AmfNameIsSet = false;
    
}

N2InterfaceAmfInfo::~N2InterfaceAmfInfo()
{
}

void N2InterfaceAmfInfo::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const N2InterfaceAmfInfo& o)
{
    j = nlohmann::json();
    if(o.ipv4EndpointAddressIsSet() || !o.m_Ipv4EndpointAddress.empty())
        j["ipv4EndpointAddress"] = o.m_Ipv4EndpointAddress;
    if(o.ipv6EndpointAddressIsSet() || !o.m_Ipv6EndpointAddress.empty())
        j["ipv6EndpointAddress"] = o.m_Ipv6EndpointAddress;
    if(o.amfNameIsSet())
        j["amfName"] = o.m_AmfName;
}

void from_json(const nlohmann::json& j, N2InterfaceAmfInfo& o)
{
    if(j.find("ipv4EndpointAddress") != j.end())
    {
        j.at("ipv4EndpointAddress").get_to(o.m_Ipv4EndpointAddress);
        o.m_Ipv4EndpointAddressIsSet = true;
    } 
    if(j.find("ipv6EndpointAddress") != j.end())
    {
        j.at("ipv6EndpointAddress").get_to(o.m_Ipv6EndpointAddress);
        o.m_Ipv6EndpointAddressIsSet = true;
    } 
    if(j.find("amfName") != j.end())
    {
        j.at("amfName").get_to(o.m_AmfName);
        o.m_AmfNameIsSet = true;
    } 
}

std::vector<std::string>& N2InterfaceAmfInfo::getIpv4EndpointAddress()
{
    return m_Ipv4EndpointAddress;
}
void N2InterfaceAmfInfo::setIpv4EndpointAddress(std::vector<std::string> const& value)
{
    m_Ipv4EndpointAddress = value;
    m_Ipv4EndpointAddressIsSet = true;
}
bool N2InterfaceAmfInfo::ipv4EndpointAddressIsSet() const
{
    return m_Ipv4EndpointAddressIsSet;
}
void N2InterfaceAmfInfo::unsetIpv4EndpointAddress()
{
    m_Ipv4EndpointAddressIsSet = false;
}
std::vector<Ipv6Addr>& N2InterfaceAmfInfo::getIpv6EndpointAddress()
{
    return m_Ipv6EndpointAddress;
}
void N2InterfaceAmfInfo::setIpv6EndpointAddress(std::vector<Ipv6Addr> const& value)
{
    m_Ipv6EndpointAddress = value;
    m_Ipv6EndpointAddressIsSet = true;
}
bool N2InterfaceAmfInfo::ipv6EndpointAddressIsSet() const
{
    return m_Ipv6EndpointAddressIsSet;
}
void N2InterfaceAmfInfo::unsetIpv6EndpointAddress()
{
    m_Ipv6EndpointAddressIsSet = false;
}
std::string N2InterfaceAmfInfo::getAmfName() const
{
    return m_AmfName;
}
void N2InterfaceAmfInfo::setAmfName(std::string const& value)
{
    m_AmfName = value;
    m_AmfNameIsSet = true;
}
bool N2InterfaceAmfInfo::amfNameIsSet() const
{
    return m_AmfNameIsSet;
}
void N2InterfaceAmfInfo::unsetAmfName()
{
    m_AmfNameIsSet = false;
}

}
}
}

