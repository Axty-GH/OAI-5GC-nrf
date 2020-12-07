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
/*
 * Ipv4AddressRange.h
 *
 * 
 */

#ifndef Ipv4AddressRange_H_
#define Ipv4AddressRange_H_


#include <string>
#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class  Ipv4AddressRange
{
public:
    Ipv4AddressRange();
    virtual ~Ipv4AddressRange();

    void validate();

    /////////////////////////////////////////////
    /// Ipv4AddressRange members

    /// <summary>
    /// 
    /// </summary>
    std::string getStart() const;
    void setStart(std::string const& value);
    bool startIsSet() const;
    void unsetStart();
    /// <summary>
    /// 
    /// </summary>
    std::string getEnd() const;
    void setEnd(std::string const& value);
    bool endIsSet() const;
    void unsetEnd();

    friend void to_json(nlohmann::json& j, const Ipv4AddressRange& o);
    friend void from_json(const nlohmann::json& j, Ipv4AddressRange& o);
protected:
    std::string m_Start;
    bool m_StartIsSet;
    std::string m_End;
    bool m_EndIsSet;
};

}
}
}

#endif /* Ipv4AddressRange_H_ */
