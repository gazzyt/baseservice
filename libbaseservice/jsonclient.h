#ifndef JSONCLIENT_H
#define JSONCLIENT_H

#include <restbed>
#include <nlohmann/json.hpp>

namespace BaseService
{
	class JsonClient
	{
	public:
		JsonClient() = delete;

        static nlohmann::json Get( const std::string& url );

	};
}

#endif
