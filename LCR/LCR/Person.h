#pragma once
#include "Libraries.h"

class Person {
protected:
	char FirstName[20];
	char LastName[20];
	int Age;
public:
	Person(); // Default constructor
	~Person(); // Destructor

	virtual void Input(istream& in); // Funciton for properties input
	virtual void Output(ostream& out) const; // Function for properties output
};