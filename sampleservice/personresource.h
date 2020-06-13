#ifndef PERSONRESOURCE_H
#define PERSONRESOURCE_H

#include <restbed>

#include "jsonresource.h"
#include "person.h"

class PersonResource : public BaseService::JsonResource<Person>
{
public:
	PersonResource();

private:
	virtual int DoGet(const std::shared_ptr<const restbed::Request> request, nlohmann::json& responseBody);
	virtual int DoPost(const std::shared_ptr<const restbed::Request> request, const Person& requestBody, nlohmann::json& responseBody);
	virtual int DoDelete(const std::shared_ptr<const restbed::Request> request, nlohmann::json& responseBody);

};

#endif
