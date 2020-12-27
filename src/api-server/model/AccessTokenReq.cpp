/**
* NRF OAuth2
* NRF OAuth2 Authorization. © 2019, 3GPP Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved. 
*
* The version of the OpenAPI document: 1.0.2
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/


#include "AccessTokenReq.h"

namespace oai {
namespace nrf {
namespace model {

AccessTokenReq::AccessTokenReq()
{
    m_Grant_type = "";
    m_NfInstanceId = "";
    m_NfTypeIsSet = false;
    m_TargetNfTypeIsSet = false;
    m_Scope = "";
    m_TargetNfInstanceId = "";
    m_TargetNfInstanceIdIsSet = false;
    m_RequesterPlmnIsSet = false;
    m_TargetPlmnIsSet = false;
    
}

AccessTokenReq::~AccessTokenReq()
{
}

void AccessTokenReq::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const AccessTokenReq& o)
{
    j = nlohmann::json();
    j["grant_type"] = o.m_Grant_type;
    j["nfInstanceId"] = o.m_NfInstanceId;
    if(o.nfTypeIsSet())
        j["nfType"] = o.m_NfType;
    if(o.targetNfTypeIsSet())
        j["targetNfType"] = o.m_TargetNfType;
    j["scope"] = o.m_Scope;
    if(o.targetNfInstanceIdIsSet())
        j["targetNfInstanceId"] = o.m_TargetNfInstanceId;
    if(o.requesterPlmnIsSet())
        j["requesterPlmn"] = o.m_RequesterPlmn;
    if(o.targetPlmnIsSet())
        j["targetPlmn"] = o.m_TargetPlmn;
}

void from_json(const nlohmann::json& j, AccessTokenReq& o)
{
    j.at("grant_type").get_to(o.m_Grant_type);
    j.at("nfInstanceId").get_to(o.m_NfInstanceId);
    if(j.find("nfType") != j.end())
    {
        j.at("nfType").get_to(o.m_NfType);
        o.m_NfTypeIsSet = true;
    } 
    if(j.find("targetNfType") != j.end())
    {
        j.at("targetNfType").get_to(o.m_TargetNfType);
        o.m_TargetNfTypeIsSet = true;
    } 
    j.at("scope").get_to(o.m_Scope);
    if(j.find("targetNfInstanceId") != j.end())
    {
        j.at("targetNfInstanceId").get_to(o.m_TargetNfInstanceId);
        o.m_TargetNfInstanceIdIsSet = true;
    } 
    if(j.find("requesterPlmn") != j.end())
    {
        j.at("requesterPlmn").get_to(o.m_RequesterPlmn);
        o.m_RequesterPlmnIsSet = true;
    } 
    if(j.find("targetPlmn") != j.end())
    {
        j.at("targetPlmn").get_to(o.m_TargetPlmn);
        o.m_TargetPlmnIsSet = true;
    } 
}

std::string AccessTokenReq::getGrantType() const
{
    return m_Grant_type;
}
void AccessTokenReq::setGrantType(std::string const& value)
{
    m_Grant_type = value;
}
std::string AccessTokenReq::getNfInstanceId() const
{
    return m_NfInstanceId;
}
void AccessTokenReq::setNfInstanceId(std::string const& value)
{
    m_NfInstanceId = value;
}
NFType AccessTokenReq::getNfType() const
{
    return m_NfType;
}
void AccessTokenReq::setNfType(NFType const& value)
{
    m_NfType = value;
    m_NfTypeIsSet = true;
}
bool AccessTokenReq::nfTypeIsSet() const
{
    return m_NfTypeIsSet;
}
void AccessTokenReq::unsetNfType()
{
    m_NfTypeIsSet = false;
}
NFType AccessTokenReq::getTargetNfType() const
{
    return m_TargetNfType;
}
void AccessTokenReq::setTargetNfType(NFType const& value)
{
    m_TargetNfType = value;
    m_TargetNfTypeIsSet = true;
}
bool AccessTokenReq::targetNfTypeIsSet() const
{
    return m_TargetNfTypeIsSet;
}
void AccessTokenReq::unsetTargetNfType()
{
    m_TargetNfTypeIsSet = false;
}
std::string AccessTokenReq::getScope() const
{
    return m_Scope;
}
void AccessTokenReq::setScope(std::string const& value)
{
    m_Scope = value;
}
std::string AccessTokenReq::getTargetNfInstanceId() const
{
    return m_TargetNfInstanceId;
}
void AccessTokenReq::setTargetNfInstanceId(std::string const& value)
{
    m_TargetNfInstanceId = value;
    m_TargetNfInstanceIdIsSet = true;
}
bool AccessTokenReq::targetNfInstanceIdIsSet() const
{
    return m_TargetNfInstanceIdIsSet;
}
void AccessTokenReq::unsetTargetNfInstanceId()
{
    m_TargetNfInstanceIdIsSet = false;
}
PlmnId AccessTokenReq::getRequesterPlmn() const
{
    return m_RequesterPlmn;
}
void AccessTokenReq::setRequesterPlmn(PlmnId const& value)
{
    m_RequesterPlmn = value;
    m_RequesterPlmnIsSet = true;
}
bool AccessTokenReq::requesterPlmnIsSet() const
{
    return m_RequesterPlmnIsSet;
}
void AccessTokenReq::unsetRequesterPlmn()
{
    m_RequesterPlmnIsSet = false;
}
PlmnId AccessTokenReq::getTargetPlmn() const
{
    return m_TargetPlmn;
}
void AccessTokenReq::setTargetPlmn(PlmnId const& value)
{
    m_TargetPlmn = value;
    m_TargetPlmnIsSet = true;
}
bool AccessTokenReq::targetPlmnIsSet() const
{
    return m_TargetPlmnIsSet;
}
void AccessTokenReq::unsetTargetPlmn()
{
    m_TargetPlmnIsSet = false;
}

}
}
}

