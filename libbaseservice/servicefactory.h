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

        static std::unique_ptr<JsonService> MakeService(uint16_t port);

	};
}

#endif
