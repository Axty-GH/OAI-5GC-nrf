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
 * ComplexQuery.h
 *
 * 
 */

#ifndef ComplexQuery_H_
#define ComplexQuery_H_


#include "CnfUnit.h"
#include "Dnf.h"
#include <vector>
#include "Cnf.h"
#include "DnfUnit.h"
#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class  ComplexQuery
{
public:
    ComplexQuery();
    virtual ~ComplexQuery();

    void validate();

    /////////////////////////////////////////////
    /// ComplexQuery members

    /// <summary>
    /// 
    /// </summary>
    std::vector<CnfUnit>& getCnfUnits();
    void setCnfUnits(std::vector<CnfUnit> const& value);
    /// <summary>
    /// 
    /// </summary>
    std::vector<DnfUnit>& getDnfUnits();
    void setDnfUnits(std::vector<DnfUnit> const& value);

    friend void to_json(nlohmann::json& j, const ComplexQuery& o);
    friend void from_json(const nlohmann::json& j, ComplexQuery& o);
protected:
    std::vector<CnfUnit> m_CnfUnits;

    std::vector<DnfUnit> m_DnfUnits;

};

}
}
}

#endif /* ComplexQuery_H_ */
