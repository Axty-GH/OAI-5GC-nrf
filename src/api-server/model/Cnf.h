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
/*
 * Cnf.h
 *
 * 
 */

#ifndef Cnf_H_
#define Cnf_H_


#include "CnfUnit.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class  Cnf
{
public:
    Cnf();
    virtual ~Cnf();

    void validate();

    /////////////////////////////////////////////
    /// Cnf members

    /// <summary>
    /// 
    /// </summary>
    std::vector<CnfUnit>& getCnfUnits();
    void setCnfUnits(std::vector<CnfUnit> const& value);

    friend void to_json(nlohmann::json& j, const Cnf& o);
    friend void from_json(const nlohmann::json& j, Cnf& o);
protected:
    std::vector<CnfUnit> m_CnfUnits;

};

}
}
}

#endif /* Cnf_H_ */
