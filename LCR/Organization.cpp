#include "Organization.h"
#include <iostream>
#include <cstring>

void Organization::clearEntities() {
	for (std::size_t i = 0; i < entities.size(); i++) {
		if (entities[i] != nullptr) {
			delete entities[i];
		}
	}
	entities.clear();
}
	Organization::Organization() : orgName(nullptr){ }
	Organization::Organization(const char* name) {
		this->orgName = OrganizationEntity::allocateAndCopy(name);
	}
	Organization::~Organization() {
		if(this->orgName != nullptr) {
			delete[] this->orgName;
		}
		clearEntities();
	}
	Organization::Organization(const Organization& rhs) {
		orgName = OrganizationEntity::allocateAndCopy(rhs.orgName);
	}
	Organization& Organization::operator=(const Organization& rhs) {
		if (this != &rhs) {
			if (orgName != nullptr) {
				delete[] orgName;
			}
			clearEntities();
			orgName = OrganizationEntity::allocateAndCopy(rhs.orgName);
		}
		return *this;
	}

	void Organization::addEntity(OrganizationEntity* entity) {
		if (entity != nullptr) {
			entities.push_back(entity);
		}
	}
	void Organization::showAllEntities() const {
		std::cout << "Organization: " << getOrgName() << "\n";
		for (std::size_t i = 0; i < entities.size(); i++) {
			entities[i]->displayInfo();
		}
		std::cout << "\n";
	}

	const char* Organization::getOrgName() const {
		return orgName;
	}
	void Organization::setOrgName(const char* name) {
		if (orgName == name) return;	
		if (orgName != nullptr) {
			delete[] orgName;
		}
		orgName = OrganizationEntity::allocateAndCopy(name);
	}


