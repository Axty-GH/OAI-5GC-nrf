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


#include "DefaultNotificationSubscription.h"

namespace oai {
namespace nrf {
namespace model {

DefaultNotificationSubscription::DefaultNotificationSubscription()
{
    m_CallbackUri = "";
    m_N1MessageClassIsSet = false;
    m_N2InformationClassIsSet = false;
    
}

DefaultNotificationSubscription::~DefaultNotificationSubscription()
{
}

void DefaultNotificationSubscription::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const DefaultNotificationSubscription& o)
{
    j = nlohmann::json();
    j["notificationType"] = o.m_NotificationType;
    j["callbackUri"] = o.m_CallbackUri;
    if(o.n1MessageClassIsSet())
        j["n1MessageClass"] = o.m_N1MessageClass;
    if(o.n2InformationClassIsSet())
        j["n2InformationClass"] = o.m_N2InformationClass;
}

void from_json(const nlohmann::json& j, DefaultNotificationSubscription& o)
{
    j.at("notificationType").get_to(o.m_NotificationType);
    j.at("callbackUri").get_to(o.m_CallbackUri);
    if(j.find("n1MessageClass") != j.end())
    {
        j.at("n1MessageClass").get_to(o.m_N1MessageClass);
        o.m_N1MessageClassIsSet = true;
    } 
    if(j.find("n2InformationClass") != j.end())
    {
        j.at("n2InformationClass").get_to(o.m_N2InformationClass);
        o.m_N2InformationClassIsSet = true;
    } 
}

NotificationType DefaultNotificationSubscription::getNotificationType() const
{
    return m_NotificationType;
}
void DefaultNotificationSubscription::setNotificationType(NotificationType const& value)
{
    m_NotificationType = value;
}
std::string DefaultNotificationSubscription::getCallbackUri() const
{
    return m_CallbackUri;
}
void DefaultNotificationSubscription::setCallbackUri(std::string const& value)
{
    m_CallbackUri = value;
}
N1MessageClass DefaultNotificationSubscription::getN1MessageClass() const
{
    return m_N1MessageClass;
}
void DefaultNotificationSubscription::setN1MessageClass(N1MessageClass const& value)
{
    m_N1MessageClass = value;
    m_N1MessageClassIsSet = true;
}
bool DefaultNotificationSubscription::n1MessageClassIsSet() const
{
    return m_N1MessageClassIsSet;
}
void DefaultNotificationSubscription::unsetN1MessageClass()
{
    m_N1MessageClassIsSet = false;
}
N2InformationClass DefaultNotificationSubscription::getN2InformationClass() const
{
    return m_N2InformationClass;
}
void DefaultNotificationSubscription::setN2InformationClass(N2InformationClass const& value)
{
    m_N2InformationClass = value;
    m_N2InformationClassIsSet = true;
}
bool DefaultNotificationSubscription::n2InformationClassIsSet() const
{
    return m_N2InformationClassIsSet;
}
void DefaultNotificationSubscription::unsetN2InformationClass()
{
    m_N2InformationClassIsSet = false;
}

}
}
}

