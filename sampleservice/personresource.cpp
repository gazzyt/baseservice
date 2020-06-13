#include <memory>
#include <string>
#include <nlohmann/json.hpp>
#include "personresource.h"

using namespace std;
using namespace restbed;
using json = nlohmann::json;

PersonResource::PersonResource()
:   JsonResource({ "/person/{id: .*}", "/person" })
{
    EnableHttpGet();
    EnableHttpPost();
    EnableHttpDelete();
}

int PersonResource::DoGet(const std::shared_ptr<const restbed::Request> request, nlohmann::json& responseBody)
{
    auto id = request->get_path_parameter("id");

    if (id.empty())
    {
        return Error(BAD_REQUEST, "Parameter {id} must be provided", responseBody);
    }

    responseBody["name"] = "Rod";
    return OK;
}

int PersonResource::DoPost(const std::shared_ptr<const restbed::Request> /*request*/, const Person& /*requestBody*/, nlohmann::json& /*responseBody*/)
{
    return CREATED;
}

int PersonResource::DoDelete(const std::shared_ptr<const restbed::Request> request, nlohmann::json& responseBody)
{
    auto id = request->get_path_parameter("id");

    if (id.empty())
    {
        return Error(BAD_REQUEST, "Parameter {id} must be provided", responseBody);
    }

    return NO_CONTENT;
}
