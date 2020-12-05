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


#include "NotifCondition.h"

namespace oai {
namespace nrf {
namespace model {

NotifCondition::NotifCondition()
{
    m_MonitoredAttributesIsSet = false;
    m_UnmonitoredAttributesIsSet = false;
    
}

NotifCondition::~NotifCondition()
{
}

void NotifCondition::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const NotifCondition& o)
{
    j = nlohmann::json();
    if(o.monitoredAttributesIsSet() || !o.m_MonitoredAttributes.empty())
        j["monitoredAttributes"] = o.m_MonitoredAttributes;
    if(o.unmonitoredAttributesIsSet() || !o.m_UnmonitoredAttributes.empty())
        j["unmonitoredAttributes"] = o.m_UnmonitoredAttributes;
}

void from_json(const nlohmann::json& j, NotifCondition& o)
{
    if(j.find("monitoredAttributes") != j.end())
    {
        j.at("monitoredAttributes").get_to(o.m_MonitoredAttributes);
        o.m_MonitoredAttributesIsSet = true;
    } 
    if(j.find("unmonitoredAttributes") != j.end())
    {
        j.at("unmonitoredAttributes").get_to(o.m_UnmonitoredAttributes);
        o.m_UnmonitoredAttributesIsSet = true;
    } 
}

std::vector<std::string>& NotifCondition::getMonitoredAttributes()
{
    return m_MonitoredAttributes;
}
void NotifCondition::setMonitoredAttributes(std::vector<std::string> const& value)
{
    m_MonitoredAttributes = value;
    m_MonitoredAttributesIsSet = true;
}
bool NotifCondition::monitoredAttributesIsSet() const
{
    return m_MonitoredAttributesIsSet;
}
void NotifCondition::unsetMonitoredAttributes()
{
    m_MonitoredAttributesIsSet = false;
}
std::vector<std::string>& NotifCondition::getUnmonitoredAttributes()
{
    return m_UnmonitoredAttributes;
}
void NotifCondition::setUnmonitoredAttributes(std::vector<std::string> const& value)
{
    m_UnmonitoredAttributes = value;
    m_UnmonitoredAttributesIsSet = true;
}
bool NotifCondition::unmonitoredAttributesIsSet() const
{
    return m_UnmonitoredAttributesIsSet;
}
void NotifCondition::unsetUnmonitoredAttributes()
{
    m_UnmonitoredAttributesIsSet = false;
}

}
}
}

