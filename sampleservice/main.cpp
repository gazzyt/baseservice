#include "servicefactory.h"
#include "sampleresource.h"
#include "personresource.h"

using namespace std;
using namespace restbed;
using namespace BaseService;

int main(int /*argc*/, char **/*argv*/) {

    auto service = ServiceFactory::MakeService(1999);

    service->Publish(make_shared<SampleResource>());
    service->Publish(make_shared<PersonResource>());
    service->Start();
    
    return 0;
}