#include "serviceconfig.h"
#include "servicefactory.h"
#include "versionresource.h"
#include "studentofferresource.h"

using namespace std;
using namespace restbed;

namespace BaseService
{

    unique_ptr<JsonService> ServiceFactory::MakeService(shared_ptr<ServiceConfig> serviceConfig, uint16_t port)
    {
        auto settings = make_shared< Settings >( );
        settings->set_port( port );
        settings->set_default_header( "Connection", "close" );

        auto service = make_unique<JsonService>(settings);
        service->Publish(make_shared<VersionResource>(serviceConfig));
        service->Publish(make_shared<StudentOfferResource>(serviceConfig));
        return service;
    }

}