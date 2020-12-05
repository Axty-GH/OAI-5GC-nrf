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


#include "SubscriptionData.h"

namespace oai {
namespace nrf {
namespace model {

SubscriptionData::SubscriptionData()
{
    m_NfStatusNotificationUri = "";
    m_ReqNfInstanceId = "";
    m_ReqNfInstanceIdIsSet = false;
    m_SubscrCondIsSet = false;
    m_SubscriptionId = "";
    m_ValidityTime = "";
    m_ValidityTimeIsSet = false;
    m_ReqNotifEventsIsSet = false;
    m_PlmnIdIsSet = false;
    m_NotifConditionIsSet = false;
    m_ReqNfTypeIsSet = false;
    m_ReqNfFqdn = "";
    m_ReqNfFqdnIsSet = false;
    m_ReqSnssaisIsSet = false;
    //m_SubscrCond;
    
}

SubscriptionData::~SubscriptionData()
{
}

void SubscriptionData::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const SubscriptionData& o)
{
    j = nlohmann::json();
    j["nfStatusNotificationUri"] = o.m_NfStatusNotificationUri;
    if(o.reqNfInstanceIdIsSet())
        j["reqNfInstanceId"] = o.m_ReqNfInstanceId;
/*    if(o.subscrCondIsSet())
        j["subscrCond"] = o.m_SubscrCond;
*/
    j["subscriptionId"] = o.m_SubscriptionId;
    if(o.validityTimeIsSet())
        j["validityTime"] = o.m_ValidityTime;
    if(o.reqNotifEventsIsSet() || !o.m_ReqNotifEvents.empty())
        j["reqNotifEvents"] = o.m_ReqNotifEvents;
    if(o.plmnIdIsSet())
        j["plmnId"] = o.m_PlmnId;
    if(o.notifConditionIsSet())
        j["notifCondition"] = o.m_NotifCondition;
    if(o.reqNfTypeIsSet())
        j["reqNfType"] = o.m_ReqNfType;
    if(o.reqNfFqdnIsSet())
        j["reqNfFqdn"] = o.m_ReqNfFqdn;
    if(o.reqSnssaisIsSet() || !o.m_ReqSnssais.empty())
        j["reqSnssais"] = o.m_ReqSnssais;
}

void from_json(const nlohmann::json& j, SubscriptionData& o)
{
    j.at("nfStatusNotificationUri").get_to(o.m_NfStatusNotificationUri);
    if(j.find("reqNfInstanceId") != j.end())
    {
        j.at("reqNfInstanceId").get_to(o.m_ReqNfInstanceId);
        o.m_ReqNfInstanceIdIsSet = true;
    } 
    /*
    if(j.find("subscrCond") != j.end())
    {
        j.at("subscrCond").get_to(o.m_SubscrCond);
        o.m_SubscrCondIsSet = true;
    } 
    */
    j.at("subscriptionId").get_to(o.m_SubscriptionId);
    if(j.find("validityTime") != j.end())
    {
        j.at("validityTime").get_to(o.m_ValidityTime);
        o.m_ValidityTimeIsSet = true;
    } 
    if(j.find("reqNotifEvents") != j.end())
    {
        j.at("reqNotifEvents").get_to(o.m_ReqNotifEvents);
        o.m_ReqNotifEventsIsSet = true;
    } 
    if(j.find("plmnId") != j.end())
    {
        j.at("plmnId").get_to(o.m_PlmnId);
        o.m_PlmnIdIsSet = true;
    } 
    if(j.find("notifCondition") != j.end())
    {
        j.at("notifCondition").get_to(o.m_NotifCondition);
        o.m_NotifConditionIsSet = true;
    } 
    if(j.find("reqNfType") != j.end())
    {
        j.at("reqNfType").get_to(o.m_ReqNfType);
        o.m_ReqNfTypeIsSet = true;
    } 
    if(j.find("reqNfFqdn") != j.end())
    {
        j.at("reqNfFqdn").get_to(o.m_ReqNfFqdn);
        o.m_ReqNfFqdnIsSet = true;
    } 
    if(j.find("reqSnssais") != j.end())
    {
        j.at("reqSnssais").get_to(o.m_ReqSnssais);
        o.m_ReqSnssaisIsSet = true;
    } 
}

std::string SubscriptionData::getNfStatusNotificationUri() const
{
    return m_NfStatusNotificationUri;
}
void SubscriptionData::setNfStatusNotificationUri(std::string const& value)
{
    m_NfStatusNotificationUri = value;
}
std::string SubscriptionData::getReqNfInstanceId() const
{
    return m_ReqNfInstanceId;
}
void SubscriptionData::setReqNfInstanceId(std::string const& value)
{
    m_ReqNfInstanceId = value;
    m_ReqNfInstanceIdIsSet = true;
}
bool SubscriptionData::reqNfInstanceIdIsSet() const
{
    return m_ReqNfInstanceIdIsSet;
}
void SubscriptionData::unsetReqNfInstanceId()
{
    m_ReqNfInstanceIdIsSet = false;
}
/*
m_SubscrCond SubscriptionData::getSubscrCond() const
{
    return m_SubscrCond;
}
*/
/*
void SubscriptionData::setSubscrCond(m_SubscrCond const& value)
{
    m_SubscrCond = value;
    m_SubscrCondIsSet = true;
}
*/

bool SubscriptionData::subscrCondIsSet() const
{
    return m_SubscrCondIsSet;
}
void SubscriptionData::unsetSubscrCond()
{
    m_SubscrCondIsSet = false;
}
std::string SubscriptionData::getSubscriptionId() const
{
    return m_SubscriptionId;
}
void SubscriptionData::setSubscriptionId(std::string const& value)
{
    m_SubscriptionId = value;
}
std::string SubscriptionData::getValidityTime() const
{
    return m_ValidityTime;
}
void SubscriptionData::setValidityTime(std::string const& value)
{
    m_ValidityTime = value;
    m_ValidityTimeIsSet = true;
}
bool SubscriptionData::validityTimeIsSet() const
{
    return m_ValidityTimeIsSet;
}
void SubscriptionData::unsetValidityTime()
{
    m_ValidityTimeIsSet = false;
}
std::vector<NotificationEventType>& SubscriptionData::getReqNotifEvents()
{
    return m_ReqNotifEvents;
}
void SubscriptionData::setReqNotifEvents(std::vector<NotificationEventType> const& value)
{
    m_ReqNotifEvents = value;
    m_ReqNotifEventsIsSet = true;
}
bool SubscriptionData::reqNotifEventsIsSet() const
{
    return m_ReqNotifEventsIsSet;
}
void SubscriptionData::unsetReqNotifEvents()
{
    m_ReqNotifEventsIsSet = false;
}
PlmnId SubscriptionData::getPlmnId() const
{
    return m_PlmnId;
}
void SubscriptionData::setPlmnId(PlmnId const& value)
{
    m_PlmnId = value;
    m_PlmnIdIsSet = true;
}
bool SubscriptionData::plmnIdIsSet() const
{
    return m_PlmnIdIsSet;
}
void SubscriptionData::unsetPlmnId()
{
    m_PlmnIdIsSet = false;
}
NotifCondition SubscriptionData::getNotifCondition() const
{
    return m_NotifCondition;
}
void SubscriptionData::setNotifCondition(NotifCondition const& value)
{
    m_NotifCondition = value;
    m_NotifConditionIsSet = true;
}
bool SubscriptionData::notifConditionIsSet() const
{
    return m_NotifConditionIsSet;
}
void SubscriptionData::unsetNotifCondition()
{
    m_NotifConditionIsSet = false;
}
std::string SubscriptionData::getReqNfType() const
{
    return m_ReqNfType;
}
void SubscriptionData::setReqNfType(std::string const& value)
{
    m_ReqNfType = value;
    m_ReqNfTypeIsSet = true;
}
bool SubscriptionData::reqNfTypeIsSet() const
{
    return m_ReqNfTypeIsSet;
}
void SubscriptionData::unsetReqNfType()
{
    m_ReqNfTypeIsSet = false;
}
std::string SubscriptionData::getReqNfFqdn() const
{
    return m_ReqNfFqdn;
}
void SubscriptionData::setReqNfFqdn(std::string const& value)
{
    m_ReqNfFqdn = value;
    m_ReqNfFqdnIsSet = true;
}
bool SubscriptionData::reqNfFqdnIsSet() const
{
    return m_ReqNfFqdnIsSet;
}
void SubscriptionData::unsetReqNfFqdn()
{
    m_ReqNfFqdnIsSet = false;
}
std::vector<Snssai>& SubscriptionData::getReqSnssais()
{
    return m_ReqSnssais;
}
void SubscriptionData::setReqSnssais(std::vector<Snssai> const& value)
{
    m_ReqSnssais = value;
    m_ReqSnssaisIsSet = true;
}
bool SubscriptionData::reqSnssaisIsSet() const
{
    return m_ReqSnssaisIsSet;
}
void SubscriptionData::unsetReqSnssais()
{
    m_ReqSnssaisIsSet = false;
}

}
}
}

