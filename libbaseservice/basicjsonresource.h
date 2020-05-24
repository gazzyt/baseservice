#ifndef BASICJSONRESOURCE_H
#define BASICJSONRESOURCE_H

#include <memory>
#include <set>

#include <restbed>
#include <nlohmann/json.hpp>

namespace BaseService
{
	class BasicJsonResource
	{
	protected:
		BasicJsonResource() = delete;
    	BasicJsonResource(const std::set<std::string>& urlPaths);
		virtual ~BasicJsonResource();

		void EnableHttpGet();
		void EnableHttpPost();

		int Error(int status, std::string&& message, nlohmann::json& responseBody);

	public:
	    auto Resource() const -> const std::shared_ptr<const restbed::Resource> { return m_resource; }

	private:
		void PostHandler( const std::shared_ptr< restbed::Session > session );
		virtual int DoPost(const std::shared_ptr<const restbed::Request> /*request*/, const nlohmann::json& /*requestBody*/, nlohmann::json& /*responseBody*/) { return 405; }

		void GetHandler( const std::shared_ptr< restbed::Session > session );
		virtual int DoGet(const std::shared_ptr<const restbed::Request> /*request*/, nlohmann::json& /*responseBody*/) { return 405; }

		static void FetchRequestJson(const std::shared_ptr<restbed::Session> session, const std::function< void ( const std::shared_ptr< restbed::Session >, const nlohmann::json& ) >& callback );

		static void SendJsonResponse(const std::shared_ptr<restbed::Session> session, int status, nlohmann::json body);

	protected:
		std::shared_ptr<restbed::Resource> m_resource;
	};
}

#endif
