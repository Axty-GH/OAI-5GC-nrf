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


#include "AccessTokenErr.h"

namespace oai {
namespace nrf {
namespace model {

AccessTokenErr::AccessTokenErr()
{
    m_Error = "";
    m_Error_description = "";
    m_Error_descriptionIsSet = false;
    m_Error_uri = "";
    m_Error_uriIsSet = false;
    
}

AccessTokenErr::~AccessTokenErr()
{
}

void AccessTokenErr::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const AccessTokenErr& o)
{
    j = nlohmann::json();
    j["error"] = o.m_Error;
    if(o.errorDescriptionIsSet())
        j["error_description"] = o.m_Error_description;
    if(o.errorUriIsSet())
        j["error_uri"] = o.m_Error_uri;
}

void from_json(const nlohmann::json& j, AccessTokenErr& o)
{
    j.at("error").get_to(o.m_Error);
    if(j.find("error_description") != j.end())
    {
        j.at("error_description").get_to(o.m_Error_description);
        o.m_Error_descriptionIsSet = true;
    } 
    if(j.find("error_uri") != j.end())
    {
        j.at("error_uri").get_to(o.m_Error_uri);
        o.m_Error_uriIsSet = true;
    } 
}

std::string AccessTokenErr::getError() const
{
    return m_Error;
}
void AccessTokenErr::setError(std::string const& value)
{
    m_Error = value;
}
std::string AccessTokenErr::getErrorDescription() const
{
    return m_Error_description;
}
void AccessTokenErr::setErrorDescription(std::string const& value)
{
    m_Error_description = value;
    m_Error_descriptionIsSet = true;
}
bool AccessTokenErr::errorDescriptionIsSet() const
{
    return m_Error_descriptionIsSet;
}
void AccessTokenErr::unsetError_description()
{
    m_Error_descriptionIsSet = false;
}
std::string AccessTokenErr::getErrorUri() const
{
    return m_Error_uri;
}
void AccessTokenErr::setErrorUri(std::string const& value)
{
    m_Error_uri = value;
    m_Error_uriIsSet = true;
}
bool AccessTokenErr::errorUriIsSet() const
{
    return m_Error_uriIsSet;
}
void AccessTokenErr::unsetError_uri()
{
    m_Error_uriIsSet = false;
}

}
}
}

