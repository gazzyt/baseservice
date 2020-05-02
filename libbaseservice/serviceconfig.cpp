#include <cstdlib>

#include "serviceconfig.h"

using namespace std;

namespace BaseService
{

    ServiceConfig::ServiceConfig()
    :   m_studentProfileServiceRootUrl()
    {
        // STUDENT_PROFILE_URL
        auto studentProfileUrl = getenv("STUDENT_PROFILE_URL");
        m_studentProfileServiceRootUrl = (studentProfileUrl == nullptr) ? "http://localhost:1985/" : studentProfileUrl;
    }
}