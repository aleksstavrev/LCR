#include <iostream>
#include "Organizer.h"

Organizer::Organizer() : Person(), position(nullptr) { }
Organizer::Organizer(const char* id, const char* name, int age, const char* pos) 
	:Person(id, name, age) {
	this->position = OrganizationEntity::allocateAndCopy(pos);
}
/*Organizer::~Organizer() {
	if(this->position != nullptr) {
			delete[] this->position;
	}
}
Organizer::Organizer(const Organizer& rhs) : Person(rhs) {
	position = OrganizationEntity::allocateAndCopy(rhs.position);
}
Organizer& Organizer::operator= (const Organizer& rhs) {
	if (this != &rhs) {
		Person::operator=(rhs);
		if(this->position != nullptr) {
				delete[] this->position;
		}
		position = OrganizationEntity::allocateAndCopy(rhs.position);
	}
	return *this;
}
*/
void Organizer::displayInfo() const{
	std::cout << "Organizer ID " << getId() << " Name: " << getName()
		<< " Age:" << getAge() << " Position: " << getPosition() << "\n";
}

const char* Organizer::getPosition() const {
	return position;
}
void Organizer::setPosition(const char* pos) {
	if(this->position != nullptr) {
		if (this->position == pos) return;
		delete[] this->position;
	}
	this->position = OrganizationEntity::allocateAndCopy(position);
}