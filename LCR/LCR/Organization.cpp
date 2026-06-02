#include "Organization.h"

Organization::Organization() {} // Default constructor
Organization::~Organization() {} // Destructor

void Organization::Input(istream& in) {
	Organizer::Input(in);
}

void Organization::Output(ostream& out) const{
	Organizer::Output(out);
}

void Organization::setAddress() {
	char address[100];
	cin >> address;
	strcpy_s(Address, address);
}

void Organization::setMoney() {
	double money;
	cin >> money;
	Money = money;
}

void Organization::getAddress(ostream& out) {
	out << "Address: " << Address << endl;
}

void Organization::getMoney(ostream& out) {
	out << "Money: " << Money << endl;
}