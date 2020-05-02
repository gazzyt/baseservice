#ifndef EXTERNALSERVICEEXCEPTION_H
#define EXTERNALSERVICEEXCEPTION_H

#include <string>
#include <exception/serviceexception.h>

namespace BaseService
{
	class ExternalServiceException : public ServiceException
	{
	public:
		ExternalServiceException(const char* what_arg)
		:	ServiceException(what_arg)
		{}

		static ExternalServiceException Create(const std::string& method, const std::string& url, int status)
		{
			std::string msg = method + " " + url + " returned " + std::to_string(status);
			return ExternalServiceException(msg.c_str());
		}
	};
}

#endif
