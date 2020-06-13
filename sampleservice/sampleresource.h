#ifndef SAMPLERESOURCE_H
#define SAMPLERESOURCE_H

#include <restbed>

#include "basicjsonresource.h"

class SampleResource : public BaseService::BasicJsonResource
{
public:
	SampleResource();

private:
	virtual int DoGet(const std::shared_ptr<const restbed::Request> request, nlohmann::json& responseBody);
	virtual int DoPost(const std::shared_ptr<const restbed::Request> request, const nlohmann::json& requestBody, nlohmann::json& responseBody);
	virtual int DoDelete(const std::shared_ptr<const restbed::Request> request, nlohmann::json& responseBody);

};

#endif
