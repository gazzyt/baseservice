#include "serviceconfig.h"
#include "servicefactory.h"

using namespace std;
using namespace restbed;

namespace BaseService
{

    unique_ptr<JsonService> ServiceFactory::MakeService(uint16_t port)
    {
        auto settings = make_shared< Settings >( );
        settings->set_port( port );
        settings->set_default_header( "Connection", "close" );

        auto service = make_unique<JsonService>(settings);
        return service;
    }

}