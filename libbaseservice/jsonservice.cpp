#include "jsonservice.h"
#include "servicelogger.h"
#include "exception/requestexception.h"

using namespace std;
using namespace restbed;

namespace BaseService
{
    JsonService::JsonService(std::shared_ptr<Settings> settings)
    :   m_resources{},
        m_settings{settings},
        m_service{make_unique<Service>()}
    {
        m_service->set_logger(make_shared< ServiceLogger>());
    }

    void JsonService::Publish(std::shared_ptr<JsonResource> resource)
    {
        m_resources.push_back(resource);
        m_service->publish(resource->Resource());
    }

    void JsonService::Start()
    {
        m_service->start(m_settings);
    }

}