#ifndef SERVICEFACTORY_H
#define SERVICEFACTORY_H

#include <memory>

#include "jsonservice.h"

namespace BaseService
{
	class ServiceFactory
	{
	public:
		ServiceFactory() = delete;

        static std::unique_ptr<JsonService> MakeService(std::shared_ptr<ServiceConfig> serviceConfig, uint16_t port);

	};
}

#endif
