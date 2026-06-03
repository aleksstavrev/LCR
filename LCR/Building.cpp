#include "Building.h"

Building::Building() : Target(), BuildingType(nullptr) {}

Building::~Building() {
	delete[] BuildingType;
}

Building::Building(const Building& rhs) : Target(rhs) {
	BuildingType = OrganizationEntity::allocateAndCopy(rhs.BuildingType);
}

Building& Building::operator=(const Building& rhs) {
	if (this != &rhs) {
		Target::operator=(rhs);
		delete[] BuildingType;
		BuildingType = OrganizationEntity::allocateAndCopy(rhs.BuildingType);
	}
	return *this;
}

void Building::Input(istream& in) {
	Target::Input(in);
	char buffer[200];
	cout << "Enter building type: "; in >> buffer;
	delete[] BuildingType;
	BuildingType = OrganizationEntity::allocateAndCopy(buffer);
}

void Building::Output(ostream& out) const {
	out << "[BUILDING] Location: " << (Location ? Location : "")
		<< " | Type: " << (BuildingType ? BuildingType : "")
		<< " | Info: " << (Description ? Description : "") << endl;
}