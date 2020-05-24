#include "person.h"
#include "exception/validationexception.h"

using namespace std;
using namespace BaseService;
using json = nlohmann::json;

Person::Person(unsigned id, std::string&& firstName, std::string&& familyName)
: m_id(id), m_firstName(firstName), m_familyName(familyName)
{}

void Person::Validate()
{
    if (m_firstName.empty())
    {
        throw ValidationException::Create("person", "firstName", "must not be empty");
    }

    if (m_familyName.empty())
    {
        throw ValidationException::Create("person", "familyName", "must not be empty");
    }
}

void to_json(json& j, const Person& p) {
    j = json{
        {"id", p.Id()}, 
        {"firstName", p.FirstName()}, 
        {"familyName", p.FamilyName()}};
}

void from_json(const json& j, Person& p) {
    for (json::const_iterator it = j.begin(); it != j.end(); ++it) {
        if (it.key().compare("id") == 0)
        {
            p.Id(it.value().get<unsigned>());
        }
        else if (it.key().compare("firstName") == 0)
        {
            it.value().get_to(p.FirstName());
        }
        else if (it.key().compare("familyName") == 0)
        {
            it.value().get_to(p.FamilyName());
        }
    }
}
