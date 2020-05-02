#ifndef SERVICECONFIG_H
#define SERVICECONFIG_H

#include <string>

namespace BaseService
{
	class ServiceConfig
	{
	public:
		ServiceConfig();

	    auto StudentProfileServiceRootUrl() const -> const std::string& { return m_studentProfileServiceRootUrl; }

	private:
		std::string m_studentProfileServiceRootUrl;
	};
}

#endif
