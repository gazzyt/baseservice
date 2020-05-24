#ifndef VALIDATIONEXCEPTION_H
#define VALIDATIONEXCEPTION_H

#include <string>
#include <exception/serviceexception.h>

namespace BaseService
{
	class ValidationException : public ServiceException
	{
	private:
		ValidationException(const char* what_arg)
		:	ServiceException(what_arg)
		{}

	public:
		static ValidationException Create(const std::string& entity, const std::string& field, const std::string& reason)
		{
			std::string msg = "Validation error on " + entity + '.' + field + ": " + reason;
			return ValidationException(msg.c_str());
		}
	};
}

#endif
