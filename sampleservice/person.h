#ifndef PERSON_H
#define PERSON_H

#include <string>

#include <nlohmann/json.hpp>

class Person
{
public:
	Person() = default;
	Person(unsigned id, std::string&& firstName, std::string&& familyName);
	Person(const Person& rhs) = default;

	void Validate();

	//auto x()       -> X&       { return x_; }
auto Id() const -> unsigned { return m_id; }
auto Id(unsigned id) -> void { m_id = id; }
auto FirstName() const -> const std::string& { return m_firstName; }
auto FirstName() -> std::string& { return m_firstName; }
auto FamilyName() const -> const std::string& { return m_familyName; }
auto FamilyName() -> std::string& { return m_familyName; }

private:
	unsigned m_id;
	std::string m_firstName;
	std::string m_familyName;

};

void to_json(nlohmann::json& j, const Person& p);
void from_json(const nlohmann::json& j, Person& p);

#endif
