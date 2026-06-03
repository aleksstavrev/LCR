#include "Organization.h"

Organization::Organization() : Organizer(), Address(nullptr), Money(0.0) {}

Organization::~Organization() {
	delete[] Address;
}

Organization::Organization(const Organization& rhs) : Organizer(rhs) {
	Address = OrganizationEntity::allocateAndCopy(rhs.Address);
	Money = rhs.Money;
}

Organization& Organization::operator=(const Organization& rhs) {
	if (this != &rhs) {
		Organizer::operator=(rhs);
		delete[] Address;
		Address = OrganizationEntity::allocateAndCopy(rhs.Address);
		Money = rhs.Money;
	}
	return *this;
}

void Organization::Input(istream& in) {
	Organizer::Input(in);
}

void Organization::Output(ostream& out) const {
	Organizer::Output(out);
}

void Organization::setAddress() {
	char buffer[200];
	cin >> buffer;
	delete[] Address;
	Address = OrganizationEntity::allocateAndCopy(buffer);
}

void Organization::setMoney() {
	double money;
	cin >> money;
	Money = money;
}

void Organization::getAddress(ostream& out) const {
	out << "Address: " << (Address ? Address : "") << endl;
}

void Organization::getMoney(ostream& out) const {
	out << "Money: " << Money << endl;
}