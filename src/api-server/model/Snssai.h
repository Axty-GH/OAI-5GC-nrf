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
 * Snssai.h
 *
 * 
 */

#ifndef Snssai_H_
#define Snssai_H_


#include <string>
#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class  Snssai
{
public:
    Snssai();
    virtual ~Snssai();

    void validate();

    /////////////////////////////////////////////
    /// Snssai members

    /// <summary>
    /// 
    /// </summary>
    int32_t getSst() const;
    void setSst(int32_t const value);
    /// <summary>
    /// 
    /// </summary>
    std::string getSd() const;
    void setSd(std::string const& value);
    bool sdIsSet() const;
    void unsetSd();

    friend void to_json(nlohmann::json& j, const Snssai& o);
    friend void from_json(const nlohmann::json& j, Snssai& o);
protected:
    int32_t m_Sst;

    std::string m_Sd;
    bool m_SdIsSet;
};

}
}
}

#endif /* Snssai_H_ */
