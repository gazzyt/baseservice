#include <memory>
#include <string>
#include <nlohmann/json.hpp>
#include "sampleresource.h"

using namespace std;
using namespace restbed;
using json = nlohmann::json;

SampleResource::SampleResource()
:   JsonResource({ "/sample/{id: .*}", "/sample" })
{
    EnableHttpGet();
    EnableHttpPost();
}

int SampleResource::DoGet(const std::shared_ptr<const restbed::Request> request, nlohmann::json& responseBody)
{
    auto id = request->get_path_parameter("id");

    if (id.empty())
    {
        return BAD_REQUEST;
    }

    responseBody["name"] = "Rod";
    return OK;
}

int SampleResource::DoPost(const std::shared_ptr<const restbed::Request> request, const nlohmann::json& requestBody, nlohmann::json& responseBody)
{
    return CREATED;
}
