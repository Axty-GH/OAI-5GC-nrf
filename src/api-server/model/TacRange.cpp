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


#include "TacRange.h"

namespace oai {
namespace nrf {
namespace model {

TacRange::TacRange()
{
    m_Start = "";
    m_StartIsSet = false;
    m_End = "";
    m_EndIsSet = false;
    m_Pattern = "";
    m_PatternIsSet = false;
    
}

TacRange::~TacRange()
{
}

void TacRange::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const TacRange& o)
{
    j = nlohmann::json();
    if(o.startIsSet())
        j["start"] = o.m_Start;
    if(o.endIsSet())
        j["end"] = o.m_End;
    if(o.patternIsSet())
        j["pattern"] = o.m_Pattern;
}

void from_json(const nlohmann::json& j, TacRange& o)
{
    if(j.find("start") != j.end())
    {
        j.at("start").get_to(o.m_Start);
        o.m_StartIsSet = true;
    } 
    if(j.find("end") != j.end())
    {
        j.at("end").get_to(o.m_End);
        o.m_EndIsSet = true;
    } 
    if(j.find("pattern") != j.end())
    {
        j.at("pattern").get_to(o.m_Pattern);
        o.m_PatternIsSet = true;
    } 
}

std::string TacRange::getStart() const
{
    return m_Start;
}
void TacRange::setStart(std::string const& value)
{
    m_Start = value;
    m_StartIsSet = true;
}
bool TacRange::startIsSet() const
{
    return m_StartIsSet;
}
void TacRange::unsetStart()
{
    m_StartIsSet = false;
}
std::string TacRange::getEnd() const
{
    return m_End;
}
void TacRange::setEnd(std::string const& value)
{
    m_End = value;
    m_EndIsSet = true;
}
bool TacRange::endIsSet() const
{
    return m_EndIsSet;
}
void TacRange::unsetEnd()
{
    m_EndIsSet = false;
}
std::string TacRange::getPattern() const
{
    return m_Pattern;
}
void TacRange::setPattern(std::string const& value)
{
    m_Pattern = value;
    m_PatternIsSet = true;
}
bool TacRange::patternIsSet() const
{
    return m_PatternIsSet;
}
void TacRange::unsetPattern()
{
    m_PatternIsSet = false;
}

}
}
}

