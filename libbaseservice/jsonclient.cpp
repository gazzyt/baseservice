#include <memory>
#include <sstream>
#include <restbed>

#include "jsonclient.h"
#include "exception/externalserviceexception.h"

using namespace std;
using namespace restbed;
using json = nlohmann::json;

namespace BaseService
{

    json JsonClient::Get( const std::string& url )
    {
        auto request = make_shared< Request >( Uri( url ) );
        request->set_header( "Accept", "*/*" );

        ostringstream hostHeaderStream;
        hostHeaderStream << request->get_host() << ':' << request->get_port();
        request->set_header( "Host", hostHeaderStream.str() );

        auto response = Http::sync( request );
        auto status = response->get_status_code();
        if (status == OK)
        {
            auto length = response->get_header( "Content-Length", 0 );

            Http::fetch( length, response );
            string bodyText;
            response->get_body(bodyText);
            fprintf( stdout, "Got body %s\n", bodyText.c_str() );
            return json::parse(bodyText);
        }
        else
        {
            throw ExternalServiceException::Create(request->get_method(), url, status);
        }
        
    }

}