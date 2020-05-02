#ifndef REQUESTEXCEPTION_H
#define REQUESTEXCEPTION_H

#include <exception/serviceexception.h>

namespace BaseService
{
	class RequestException : public ServiceException
	{
	public:
		RequestException(const char* what_arg)
		:	ServiceException(what_arg)
		{}
	};
}

#endif
