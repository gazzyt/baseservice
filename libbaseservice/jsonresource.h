#ifndef JSONRESOURCE_H
#define JSONRESOURCE_H

#include <memory>
#include <set>

#include <restbed>
#include <nlohmann/json.hpp>

#include "basicjsonresource.h"
#include "exception/validationexception.h"

namespace BaseService
{
	template <typename T> class JsonResource : public BasicJsonResource
	{
	protected:
		JsonResource() = delete;
    	JsonResource(const std::set<std::string>& urlPaths)
		:	BasicJsonResource(urlPaths)
		{}

	private:
		virtual int DoPost(const std::shared_ptr<const restbed::Request> request, const nlohmann::json& requestBody, nlohmann::json& responseBody)
		{
			auto requestEntity = requestBody.get<T>();

			try
			{
				requestEntity.Validate();
			}
			catch(const ValidationException& e)
			{
				return Error(restbed::BAD_REQUEST, e.what(), responseBody);
			}
			
			return DoPost(request, requestEntity, responseBody);
		}

	protected:
		virtual int DoPost(const std::shared_ptr<const restbed::Request> /*request*/, const T& /*requestBody*/, nlohmann::json& /*responseBody*/) { return 405; }

	};
}

#endif
