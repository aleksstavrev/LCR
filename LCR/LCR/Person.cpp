#include "Person.h"

Person::Person() {} // Default constructor
Person::~Person() {} // Destructor

void Person::Input(istream& in) { // Function for properties input
	cout << "Enter first name: ";
	in >> FirstName;

	cout << "Enter last name: ";
	in >> LastName;

	cout << "Enter age: ";
	in >> Age;
}

void Person::Output(ostream& out) const{ // Function for properties output
	out << "First name: " << FirstName << endl;
	out << "Last name: " << LastName << endl;
	out << "Age: " << Age << endl;
}