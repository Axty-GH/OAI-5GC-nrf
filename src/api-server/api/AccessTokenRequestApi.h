/**
 * NRF OAuth2
 * NRF OAuth2 Authorization. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.0.2
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
/*
 * AccessTokenRequestApi.h
 *
 *
 */

#ifndef AccessTokenRequestApi_H_
#define AccessTokenRequestApi_H_

#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>

#include "AccessTokenErr.h"
#include "AccessTokenRsp.h"
#include "NFType.h"
#include "PlmnId.h"
#include "ProblemDetails.h"
#include <string>

namespace oai {
namespace nrf {
namespace api {

using namespace oai::nrf::model;

class AccessTokenRequestApi {
 public:
  AccessTokenRequestApi(std::shared_ptr<Pistache::Rest::Router>);
  virtual ~AccessTokenRequestApi() {}
  void init();

  const std::string base = "";

 private:
  void setupRoutes();

  void access_token_request_handler(
      const Pistache::Rest::Request& request,
      Pistache::Http::ResponseWriter response);
  void access_token_request_api_default_handler(
      const Pistache::Rest::Request& request,
      Pistache::Http::ResponseWriter response);

  std::shared_ptr<Pistache::Rest::Router> router;

  /// <summary>
  /// Access Token Request
  /// </summary>
  /// <remarks>
  ///
  /// </remarks>
  virtual void access_token_request(
      const Pistache::Rest::Request& request,
      Pistache::Http::ResponseWriter& response) = 0;
};

}  // namespace api
}  // namespace nrf
}  // namespace oai

#endif /* AccessTokenRequestApi_H_ */
