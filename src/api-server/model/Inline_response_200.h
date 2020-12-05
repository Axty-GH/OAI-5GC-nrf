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
 * Inline_response_200.h
 *
 * 
 */

#ifndef Inline_response_200_H_
#define Inline_response_200_H_


#include "LinksValueSchema.h"
#include <map>
#include <vector>
#include <nlohmann/json.hpp>

namespace oai {
namespace nrf {
namespace model {

/// <summary>
/// 
/// </summary>
class  Inline_response_200
{
public:
    Inline_response_200();
    virtual ~Inline_response_200();

    void validate();

    /////////////////////////////////////////////
    /// Inline_response_200 members

    /// <summary>
    /// List of the URI of NF instances. It has two members whose names are item and self. The item one contains an array of URIs.
    /// </summary>
    std::map<std::string, LinksValueSchema>& getLinks();
    void setLinks(std::map<std::string, LinksValueSchema> const& value);
    bool linksIsSet() const;
    void unset_links();

    friend void to_json(nlohmann::json& j, const Inline_response_200& o);
    friend void from_json(const nlohmann::json& j, Inline_response_200& o);
protected:
    std::map<std::string, LinksValueSchema> m__links;
    bool m__linksIsSet;
};

}
}
}

#endif /* Inline_response_200_H_ */
