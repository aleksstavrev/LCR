#include "Target.h"

Target::Target() : Location(nullptr), Description(nullptr) {}

Target::~Target() {
	delete[] Location;
	delete[] Description;
}

Target::Target(const Target& rhs) {
	Location = OrganizationEntity::allocateAndCopy(rhs.Location);
	Description = OrganizationEntity::allocateAndCopy(rhs.Description);
}

Target& Target::operator=(const Target& rhs) {
	if (this != &rhs) {
		delete[] Location;
		delete[] Description;
		Location = OrganizationEntity::allocateAndCopy(rhs.Location);
		Description = OrganizationEntity::allocateAndCopy(rhs.Description);
	}
	return *this;
}

void Target::Input(istream& in) {
	char buffer[200];
	cout << "Enter location: ";    in >> buffer;
	delete[] Location;
	Location = OrganizationEntity::allocateAndCopy(buffer);

	cout << "Enter description: "; in >> buffer;
	delete[] Description;
	Description = OrganizationEntity::allocateAndCopy(buffer);
}