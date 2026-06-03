#include "Person.h"

Person::Person() : FirstName(nullptr), LastName(nullptr), Age(0) {}

Person::~Person() {
	delete[] FirstName;
	delete[] LastName;
}

Person::Person(const Person& rhs) {
	FirstName = OrganizationEntity::allocateAndCopy(rhs.FirstName);
	LastName = OrganizationEntity::allocateAndCopy(rhs.LastName);
	Age = rhs.Age;
}

Person& Person::operator=(const Person& rhs) {
	if (this != &rhs) {
		delete[] FirstName;
		delete[] LastName;
		FirstName = OrganizationEntity::allocateAndCopy(rhs.FirstName);
		LastName = OrganizationEntity::allocateAndCopy(rhs.LastName);
		Age = rhs.Age;
	}
	return *this;
}

void Person::Input(istream& in) {
	char buffer[200];
	cout << "Enter first name: ";
	in >> buffer;
	delete[] FirstName;
	FirstName = OrganizationEntity::allocateAndCopy(buffer);

	cout << "Enter last name: ";
	in >> buffer;
	delete[] LastName;
	LastName = OrganizationEntity::allocateAndCopy(buffer);

	cout << "Enter age: ";
	in >> Age;
}

void Person::Output(ostream& out) const {
	out << "First name: " << (FirstName ? FirstName : "") << endl;
	out << "Last name: " << (LastName ? LastName : "") << endl;
	out << "Age: " << Age << endl;
}