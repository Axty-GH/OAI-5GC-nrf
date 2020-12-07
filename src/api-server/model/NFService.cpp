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


#include "NFService.h"

namespace oai {
namespace nrf {
namespace model {

NFService::NFService()
{
    m_ServiceInstanceId = "";
    m_Fqdn = "";
    m_FqdnIsSet = false;
    m_InterPlmnFqdn = "";
    m_InterPlmnFqdnIsSet = false;
    m_IpEndPointsIsSet = false;
    m_ApiPrefix = "";
    m_ApiPrefixIsSet = false;
    m_DefaultNotificationSubscriptionsIsSet = false;
    m_AllowedPlmnsIsSet = false;
    m_AllowedNfTypesIsSet = false;
    m_AllowedNfDomainsIsSet = false;
    m_AllowedNssaisIsSet = false;
    m_Priority = 0;
    m_PriorityIsSet = false;
    m_Capacity = 0;
    m_CapacityIsSet = false;
    m_Load = 0;
    m_LoadIsSet = false;
    m_Priority = 0;
    m_PriorityIsSet = false;
    m_RecoveryTime = "";
    m_RecoveryTimeIsSet = false;
    m_ChfServiceInfoIsSet = false;
    m_SupportedFeatures = "";
    m_SupportedFeaturesIsSet = false;
    
}

NFService::~NFService()
{
}

void NFService::validate()
{
    // TODO: implement validation
}

void to_json(nlohmann::json& j, const NFService& o)
{
    j = nlohmann::json();
    j["serviceInstanceId"] = o.m_ServiceInstanceId;
    j["serviceName"] = o.m_ServiceName;
    j["versions"] = o.m_Versions;
    j["scheme"] = o.m_Scheme;
    j["nfServiceStatus"] = o.m_NfServiceStatus;
    if(o.fqdnIsSet())
        j["fqdn"] = o.m_Fqdn;
    if(o.interPlmnFqdnIsSet())
        j["interPlmnFqdn"] = o.m_InterPlmnFqdn;
    if(o.ipEndPointsIsSet() || !o.m_IpEndPoints.empty())
        j["ipEndPoints"] = o.m_IpEndPoints;
    if(o.apiPrefixIsSet())
        j["apiPrefix"] = o.m_ApiPrefix;
    if(o.defaultNotificationSubscriptionsIsSet() || !o.m_DefaultNotificationSubscriptions.empty())
        j["defaultNotificationSubscriptions"] = o.m_DefaultNotificationSubscriptions;
    if(o.allowedPlmnsIsSet() || !o.m_AllowedPlmns.empty())
        j["allowedPlmns"] = o.m_AllowedPlmns;
    if(o.allowedNfTypesIsSet() || !o.m_AllowedNfTypes.empty())
        j["allowedNfTypes"] = o.m_AllowedNfTypes;
    if(o.allowedNfDomainsIsSet() || !o.m_AllowedNfDomains.empty())
        j["allowedNfDomains"] = o.m_AllowedNfDomains;
    if(o.allowedNssaisIsSet() || !o.m_AllowedNssais.empty())
        j["allowedNssais"] = o.m_AllowedNssais;
    if(o.priorityIsSet())
        j["priority"] = o.m_Priority;
    if(o.capacityIsSet())
        j["capacity"] = o.m_Capacity;
    if(o.loadIsSet())
        j["load"] = o.m_Load;
    if(o.priorityIsSet())
        j["priority"] = o.m_Priority;
    if(o.recoveryTimeIsSet())
        j["recoveryTime"] = o.m_RecoveryTime;
    if(o.chfServiceInfoIsSet())
        j["chfServiceInfo"] = o.m_ChfServiceInfo;
    if(o.supportedFeaturesIsSet())
        j["supportedFeatures"] = o.m_SupportedFeatures;
}

void from_json(const nlohmann::json& j, NFService& o)
{
    j.at("serviceInstanceId").get_to(o.m_ServiceInstanceId);
    j.at("serviceName").get_to(o.m_ServiceName);
    j.at("versions").get_to(o.m_Versions);
    j.at("scheme").get_to(o.m_Scheme);
    j.at("nfServiceStatus").get_to(o.m_NfServiceStatus);
    if(j.find("fqdn") != j.end())
    {
        j.at("fqdn").get_to(o.m_Fqdn);
        o.m_FqdnIsSet = true;
    } 
    if(j.find("interPlmnFqdn") != j.end())
    {
        j.at("interPlmnFqdn").get_to(o.m_InterPlmnFqdn);
        o.m_InterPlmnFqdnIsSet = true;
    } 
    if(j.find("ipEndPoints") != j.end())
    {
        j.at("ipEndPoints").get_to(o.m_IpEndPoints);
        o.m_IpEndPointsIsSet = true;
    } 
    if(j.find("apiPrefix") != j.end())
    {
        j.at("apiPrefix").get_to(o.m_ApiPrefix);
        o.m_ApiPrefixIsSet = true;
    } 
    if(j.find("defaultNotificationSubscriptions") != j.end())
    {
        j.at("defaultNotificationSubscriptions").get_to(o.m_DefaultNotificationSubscriptions);
        o.m_DefaultNotificationSubscriptionsIsSet = true;
    } 
    if(j.find("allowedPlmns") != j.end())
    {
        j.at("allowedPlmns").get_to(o.m_AllowedPlmns);
        o.m_AllowedPlmnsIsSet = true;
    } 
    if(j.find("allowedNfTypes") != j.end())
    {
        j.at("allowedNfTypes").get_to(o.m_AllowedNfTypes);
        o.m_AllowedNfTypesIsSet = true;
    } 
    if(j.find("allowedNfDomains") != j.end())
    {
        j.at("allowedNfDomains").get_to(o.m_AllowedNfDomains);
        o.m_AllowedNfDomainsIsSet = true;
    } 
    if(j.find("allowedNssais") != j.end())
    {
        j.at("allowedNssais").get_to(o.m_AllowedNssais);
        o.m_AllowedNssaisIsSet = true;
    } 
    if(j.find("priority") != j.end())
    {
        j.at("priority").get_to(o.m_Priority);
        o.m_PriorityIsSet = true;
    } 
    if(j.find("capacity") != j.end())
    {
        j.at("capacity").get_to(o.m_Capacity);
        o.m_CapacityIsSet = true;
    } 
    if(j.find("load") != j.end())
    {
        j.at("load").get_to(o.m_Load);
        o.m_LoadIsSet = true;
    } 
    if(j.find("priority") != j.end())
    {
        j.at("priority").get_to(o.m_Priority);
        o.m_PriorityIsSet = true;
    } 
    if(j.find("recoveryTime") != j.end())
    {
        j.at("recoveryTime").get_to(o.m_RecoveryTime);
        o.m_RecoveryTimeIsSet = true;
    } 
    if(j.find("chfServiceInfo") != j.end())
    {
        j.at("chfServiceInfo").get_to(o.m_ChfServiceInfo);
        o.m_ChfServiceInfoIsSet = true;
    } 
    if(j.find("supportedFeatures") != j.end())
    {
        j.at("supportedFeatures").get_to(o.m_SupportedFeatures);
        o.m_SupportedFeaturesIsSet = true;
    } 
}

std::string NFService::getServiceInstanceId() const
{
    return m_ServiceInstanceId;
}
void NFService::setServiceInstanceId(std::string const& value)
{
    m_ServiceInstanceId = value;
}
ServiceName NFService::getServiceName() const
{
    return m_ServiceName;
}
void NFService::setServiceName(ServiceName const& value)
{
    m_ServiceName = value;
}
std::vector<NFServiceVersion>& NFService::getVersions()
{
    return m_Versions;
}
void NFService::setVersions(std::vector<NFServiceVersion> const& value)
{
    m_Versions = value;
}
UriScheme NFService::getScheme() const
{
    return m_Scheme;
}
void NFService::setScheme(UriScheme const& value)
{
    m_Scheme = value;
}
NFServiceStatus NFService::getNfServiceStatus() const
{
    return m_NfServiceStatus;
}
void NFService::setNfServiceStatus(NFServiceStatus const& value)
{
    m_NfServiceStatus = value;
}
std::string NFService::getFqdn() const
{
    return m_Fqdn;
}
void NFService::setFqdn(std::string const& value)
{
    m_Fqdn = value;
    m_FqdnIsSet = true;
}
bool NFService::fqdnIsSet() const
{
    return m_FqdnIsSet;
}
void NFService::unsetFqdn()
{
    m_FqdnIsSet = false;
}
std::string NFService::getInterPlmnFqdn() const
{
    return m_InterPlmnFqdn;
}
void NFService::setInterPlmnFqdn(std::string const& value)
{
    m_InterPlmnFqdn = value;
    m_InterPlmnFqdnIsSet = true;
}
bool NFService::interPlmnFqdnIsSet() const
{
    return m_InterPlmnFqdnIsSet;
}
void NFService::unsetInterPlmnFqdn()
{
    m_InterPlmnFqdnIsSet = false;
}
std::vector<IpEndPoint>& NFService::getIpEndPoints()
{
    return m_IpEndPoints;
}
void NFService::setIpEndPoints(std::vector<IpEndPoint> const& value)
{
    m_IpEndPoints = value;
    m_IpEndPointsIsSet = true;
}
bool NFService::ipEndPointsIsSet() const
{
    return m_IpEndPointsIsSet;
}
void NFService::unsetIpEndPoints()
{
    m_IpEndPointsIsSet = false;
}
std::string NFService::getApiPrefix() const
{
    return m_ApiPrefix;
}
void NFService::setApiPrefix(std::string const& value)
{
    m_ApiPrefix = value;
    m_ApiPrefixIsSet = true;
}
bool NFService::apiPrefixIsSet() const
{
    return m_ApiPrefixIsSet;
}
void NFService::unsetApiPrefix()
{
    m_ApiPrefixIsSet = false;
}
std::vector<DefaultNotificationSubscription>& NFService::getDefaultNotificationSubscriptions()
{
    return m_DefaultNotificationSubscriptions;
}
void NFService::setDefaultNotificationSubscriptions(std::vector<DefaultNotificationSubscription> const& value)
{
    m_DefaultNotificationSubscriptions = value;
    m_DefaultNotificationSubscriptionsIsSet = true;
}
bool NFService::defaultNotificationSubscriptionsIsSet() const
{
    return m_DefaultNotificationSubscriptionsIsSet;
}
void NFService::unsetDefaultNotificationSubscriptions()
{
    m_DefaultNotificationSubscriptionsIsSet = false;
}
std::vector<PlmnId>& NFService::getAllowedPlmns()
{
    return m_AllowedPlmns;
}
void NFService::setAllowedPlmns(std::vector<PlmnId> const& value)
{
    m_AllowedPlmns = value;
    m_AllowedPlmnsIsSet = true;
}
bool NFService::allowedPlmnsIsSet() const
{
    return m_AllowedPlmnsIsSet;
}
void NFService::unsetAllowedPlmns()
{
    m_AllowedPlmnsIsSet = false;
}
std::vector<std::string>& NFService::getAllowedNfTypes()
{
    return m_AllowedNfTypes;
}
void NFService::setAllowedNfTypes(std::vector<std::string> const& value)
{
    m_AllowedNfTypes = value;
    m_AllowedNfTypesIsSet = true;
}
bool NFService::allowedNfTypesIsSet() const
{
    return m_AllowedNfTypesIsSet;
}
void NFService::unsetAllowedNfTypes()
{
    m_AllowedNfTypesIsSet = false;
}
std::vector<std::string>& NFService::getAllowedNfDomains()
{
    return m_AllowedNfDomains;
}
void NFService::setAllowedNfDomains(std::vector<std::string> const& value)
{
    m_AllowedNfDomains = value;
    m_AllowedNfDomainsIsSet = true;
}
bool NFService::allowedNfDomainsIsSet() const
{
    return m_AllowedNfDomainsIsSet;
}
void NFService::unsetAllowedNfDomains()
{
    m_AllowedNfDomainsIsSet = false;
}
std::vector<Snssai>& NFService::getAllowedNssais()
{
    return m_AllowedNssais;
}
void NFService::setAllowedNssais(std::vector<Snssai> const& value)
{
    m_AllowedNssais = value;
    m_AllowedNssaisIsSet = true;
}
bool NFService::allowedNssaisIsSet() const
{
    return m_AllowedNssaisIsSet;
}
void NFService::unsetAllowedNssais()
{
    m_AllowedNssaisIsSet = false;
}
int32_t NFService::getPriority() const
{
    return m_Priority;
}
void NFService::setPriority(int32_t const value)
{
    m_Priority = value;
    m_PriorityIsSet = true;
}
bool NFService::priorityIsSet() const
{
    return m_PriorityIsSet;
}
void NFService::unsetPriority()
{
    m_PriorityIsSet = false;
}
int32_t NFService::getCapacity() const
{
    return m_Capacity;
}
void NFService::setCapacity(int32_t const value)
{
    m_Capacity = value;
    m_CapacityIsSet = true;
}
bool NFService::capacityIsSet() const
{
    return m_CapacityIsSet;
}
void NFService::unsetCapacity()
{
    m_CapacityIsSet = false;
}
int32_t NFService::getLoad() const
{
    return m_Load;
}
void NFService::setLoad(int32_t const value)
{
    m_Load = value;
    m_LoadIsSet = true;
}
bool NFService::loadIsSet() const
{
    return m_LoadIsSet;
}
void NFService::unsetLoad()
{
    m_LoadIsSet = false;
}

std::string NFService::getRecoveryTime() const
{
    return m_RecoveryTime;
}
void NFService::setRecoveryTime(std::string const& value)
{
    m_RecoveryTime = value;
    m_RecoveryTimeIsSet = true;
}
bool NFService::recoveryTimeIsSet() const
{
    return m_RecoveryTimeIsSet;
}
void NFService::unsetRecoveryTime()
{
    m_RecoveryTimeIsSet = false;
}
ChfServiceInfo NFService::getChfServiceInfo() const
{
    return m_ChfServiceInfo;
}
void NFService::setChfServiceInfo(ChfServiceInfo const& value)
{
    m_ChfServiceInfo = value;
    m_ChfServiceInfoIsSet = true;
}
bool NFService::chfServiceInfoIsSet() const
{
    return m_ChfServiceInfoIsSet;
}
void NFService::unsetChfServiceInfo()
{
    m_ChfServiceInfoIsSet = false;
}
std::string NFService::getSupportedFeatures() const
{
    return m_SupportedFeatures;
}
void NFService::setSupportedFeatures(std::string const& value)
{
    m_SupportedFeatures = value;
    m_SupportedFeaturesIsSet = true;
}
bool NFService::supportedFeaturesIsSet() const
{
    return m_SupportedFeaturesIsSet;
}
void NFService::unsetSupportedFeatures()
{
    m_SupportedFeaturesIsSet = false;
}

}
}
}

