#include "Target.h"

Target::Target() : OrganizationEntity(), description(nullptr) {}
Target::Target(const char* id, const char* name, const char* description):
	OrganizationEntity(id, name) {
	this->description = OrganizationEntity::allocateAndCopy(description);
}
Target::~Target() {
	if (this->description != nullptr) {
		delete[] description;
	}
}
Target::Target(const Target& rhs) : OrganizationEntity(rhs) {
	
	this->description = OrganizationEntity::allocateAndCopy(rhs.description);
}
Target& Target::operator= (const Target& rhs) {
	if (this != &rhs) {
		OrganizationEntity::operator=(rhs);
		if(this -> description != nullptr)
			delete[] description;
		description = OrganizationEntity::allocateAndCopy(rhs.description);
	}
	return *this;
}

const char* Target::getDescription() const {
	return description;
}
void Target::setDescription(const char* desc) {
	if (this->description == desc) return;
	if (this->description != nullptr) {
		delete[] this->description;
	}
	this->description = OrganizationEntity::allocateAndCopy(desc);
}
