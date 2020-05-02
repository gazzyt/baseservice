#ifndef JSONRESOURCE_H
#define JSONRESOURCE_H

#include <memory>

#include <restbed>
#include <nlohmann/json.hpp>

#include <serviceconfig.h>

namespace BaseService
{
	class JsonResource
	{
	protected:
		JsonResource() = delete;
    	JsonResource(std::shared_ptr<ServiceConfig> serviceConfig, const std::string& urlPath);

		void EnableHttpGet();
		void EnableHttpPost();

	public:
	    auto Resource() const -> const std::shared_ptr<const restbed::Resource> { return m_resource; }

	private:
		void PostHandler( const std::shared_ptr< restbed::Session > session );
		virtual int DoPost(const nlohmann::json& /*requestBody*/, nlohmann::json& /*responseBody*/) { return 405; }

		void GetHandler( const std::shared_ptr< restbed::Session > session );
		virtual int DoGet(nlohmann::json& /*responseBody*/) { return 405; }

		static void FetchRequestJson(const std::shared_ptr<restbed::Session> session, const std::function< void ( const std::shared_ptr< restbed::Session >, const nlohmann::json& ) >& callback );

		static void SendJsonResponse(const std::shared_ptr<restbed::Session> session, int status, nlohmann::json body);

	protected:
		std::shared_ptr<ServiceConfig> m_serviceConfig;
		std::shared_ptr<restbed::Resource> m_resource;
	};
}

#endif
