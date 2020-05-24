#include "jsonresource.h"
#include "exception/requestexception.h"

using namespace std;
using namespace restbed;
using json = nlohmann::json;

namespace BaseService
{
    JsonResource::JsonResource(const std::set<std::string>& urlPaths)
    :   m_resource{make_shared< restbed::Resource >()}
    {
        m_resource->set_paths(urlPaths);
    }

    JsonResource::~JsonResource()
    {}

	void JsonResource::EnableHttpGet()
    {
        m_resource->set_method_handler("GET", [this](const std::shared_ptr< restbed::Session > session){GetHandler(session);});
    }

	void JsonResource::EnableHttpPost()
    {
        m_resource->set_method_handler("POST", [this](const std::shared_ptr< restbed::Session > session){PostHandler(session);});
    }

	int JsonResource::Error(int status, std::string&& message, nlohmann::json& responseBody)
    {
        responseBody["status"] = status;
        responseBody["message"] = message;
        return status;
    }


	void JsonResource::GetHandler( const std::shared_ptr< restbed::Session > session )
    {
		FetchRequestJson(session, [this](const std::shared_ptr<Session> session, const json& /*requestBody*/)
        {
            json responseBody;

            int status = DoGet(session->get_request(), responseBody);

            SendJsonResponse(session, status, responseBody);
        });
    }

	void JsonResource::PostHandler( const std::shared_ptr< restbed::Session > session )
    {
		FetchRequestJson(session, [this](const std::shared_ptr<Session> session, const json& requestBody)
        {
            json responseBody;

            int status = DoPost(session->get_request(), requestBody, responseBody);

            SendJsonResponse(session, status, responseBody);
        });
    }

	void JsonResource::FetchRequestJson(const std::shared_ptr<restbed::Session> session, 
        const std::function<void (const std::shared_ptr<restbed::Session>, const nlohmann::json&) >& callback)
    {
        const auto request = session->get_request( );

        size_t content_length = request->get_header( "Content-Length", 0 );

        session->fetch(content_length, [ callback ]( const shared_ptr<Session> session, const Bytes & body)
        {
            json bodyJson;
            if (!body.empty())
            {
                string bodyText = String::to_string(body);
                bodyJson = json::parse(bodyText);
            }

            callback(session, bodyJson);
        } );

    }

	void JsonResource::SendJsonResponse(const shared_ptr<restbed::Session> session, int status, json body)
    {
        auto bodyText = body.dump();
        session->close( status, bodyText, { { "Content-Length", to_string(bodyText.length()) } } );
    }

}