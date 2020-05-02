#ifndef SERVICELOGGER_H
#define SERVICELOGGER_H

#include <restbed>

namespace BaseService
{
	class ServiceLogger : public restbed::Logger
	{
	public:
		ServiceLogger() = default;
		ServiceLogger(const ServiceLogger& rhs) = delete;
		ServiceLogger(ServiceLogger&& rhs) = delete;

		ServiceLogger& operator=(const ServiceLogger& rhs) = delete;
		ServiceLogger& operator=(ServiceLogger&& rhs) = delete;

		void start(const std::shared_ptr< const restbed::Settings>& settings);
        void stop();

		void log(const Level level, const char* format, ...);
		void log_if(bool expression, const Level, const char* format, ...);

	};
}

#endif
