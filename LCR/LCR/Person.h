#pragma once
#include "OrganizationEntity.h"

class Person : public OrganizationEntity {
protected:
	char* FirstName;
	char* LastName;
	int Age;
public:
	Person();
	virtual ~Person() override;

	Person(const Person& rhs);
	Person& operator=(const Person& rhs);

	void Input(istream& in) override;
	void Output(ostream& out) const override;
};