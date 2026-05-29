#pragma once
#include "OrganizationEntity.h"

class Person : public OrganizationEntity {
public:
	Person();
	Person(const char* id, const char* name, int age);
	virtual ~Person() = default;
	Person(const Person& rhs) = default;
	Person& operator= (const Person& rhs) = default;
	
	int getAge() const;
	void setAge(int age);
protected:
	int age;
};