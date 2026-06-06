#include <iostream>
#include "Building.h"

Building::Building() : Target(), buildingType(nullptr) {}
Building::Building(const char* id, const char* name, const char* description, const char* type):
	Target(id, name, description) {
	this->buildingType = OrganizationEntity::allocateAndCopy(type);
}
Building::~Building() {
	if (this->buildingType != nullptr) {
		delete[] this->buildingType;
	}
}

Building::Building(const Building& rhs) : Target(rhs) {
	buildingType = OrganizationEntity::allocateAndCopy(rhs.buildingType);
}
Building& Building::operator= (const Building& rhs) {
	if (this != &rhs) {
		Target::operator=(rhs);
		if (buildingType != nullptr) {
			delete[] buildingType;
		}
		buildingType = OrganizationEntity::allocateAndCopy(rhs.buildingType);
	}
	return *this;
}

void Building::displayInfo() const {
	std::cout << "Building ID " << getId() << " Name/Location: " << getName()
		<< " Description: " << getDescription() << " Type: " << getBuildingType() << "\n";
}
const char* Building::getBuildingType() const {
	return buildingType;
}
void Building::setBuildingType(const char* type) {
	if (this->buildingType == type) return;
	if (this->buildingType != nullptr) {
		delete[] this->buildingType;
	}
	this->buildingType = OrganizationEntity::allocateAndCopy(type);
}