#include "servicelogger.h"

using namespace std;
using namespace restbed;

namespace BaseService
{

    void ServiceLogger::start(const shared_ptr< const Settings>&)
    {
        return;
    }

    void ServiceLogger::stop()
    {
        return;
    }

    void ServiceLogger::log(const Level, const char* format, ...)
    {
        va_list arguments;
        va_start( arguments, format );
        
        vfprintf( stderr, format, arguments );
        fprintf( stderr, "\n" );
        
        va_end( arguments );
    }

    void ServiceLogger::log_if(bool expression, const Level level, const char* format, ...)
    {
        if ( expression )
        {
            va_list arguments;
            va_start( arguments, format );
            log( level, format, arguments );
            va_end( arguments );
        }
    }
}