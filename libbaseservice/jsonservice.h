#ifndef JSONSERVICE_H
#define JSONSERVICE_H

#include <memory>

#include <restbed>

#include <jsonresource.h>

namespace BaseService
{
	class JsonService
	{
	public:
		JsonService() = delete;
    	JsonService(std::shared_ptr<restbed::Settings> settings);

		void Publish(std::shared_ptr<JsonResource> resource);
		void Start();

	private:
		std::vector<std::shared_ptr<JsonResource> > m_resources;
		std::shared_ptr<restbed::Settings> m_settings;
		std::unique_ptr<restbed::Service> m_service;
	};
}

#endif
