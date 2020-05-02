#ifndef SERVICEEXCEPTION_H
#define SERVICEEXCEPTION_H

#include <stdexcept>

namespace BaseService
{
	class ServiceException : public std::exception
	{
	public:
		const char* what() const noexcept override
		{
			return m_messageStorage.what();
		}

	protected:
		ServiceException(const char* what_arg)
		:	m_messageStorage(what_arg)
		{}

	private:
		// use a runtime_error object to store the error message
		std::runtime_error m_messageStorage;
	};
}

#endif
