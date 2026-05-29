#include "Person.h"

Person::Person(): OrganizationEntity(), age(0) { }
Person::Person(const char* id, const char* name, int age): OrganizationEntity(id, name), age(age) { }
	
int Person::getAge() const {
	return age;
}
void Person::setAge(int age) {
	this->age = age;
}