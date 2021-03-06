#ifndef MyController_hpp
#define MyController_hpp

#include "dto/ConfigDTO.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- Begin Codegen

/**
 * Sample Api Controller.
 */
class MyController : public oatpp::web::server::api::ApiController {
public:
  /**
   * Constructor with object mapper.
   * @param objectMapper - default object mapper used to serialize/deserialize DTOs.
   */
  MyController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
public:

  ENDPOINT("GET", "/", root) {
    auto dto = ConfigDto::createShared();
    dto->statusCode = 200;
    dto->message = "Hello World!";
    return createDtoResponse(Status::CODE_200, dto);
  }

  ENDPOINT("GET", "/login", loginGet) {
    auto dto = ConfigDto::createShared();
    dto->statusCode = 200;
    dto->message = "hhhh";

    return createDtoResponse(Status::CODE_200, dto);
  }

  // ENDPOINT("GET", "/login", loginGet, BODY_STRING(String, info)) {
  //   auto dto = ConfigDto::createShared();
  //   dto->statusCode = 200;
  //   dto->message = info;

  //   return createDtoResponse(Status::CODE_200, dto);
  // }
  
  ENDPOINT("POST", "/regist", registPost, BODY_STRING(String, info)) {
    auto dto = ConfigDto::createShared();
    dto->statusCode = 200;
    dto->message = info;

    return createDtoResponse(Status::CODE_200, dto);
  }
  
};

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- End Codegen

#endif /* MyController_hpp */
