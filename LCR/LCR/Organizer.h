#pragma once
#include "Person.h"

class Organizer : public Person {
protected:
	static int counter;
	int Id;
public:
	Organizer(); // Default constructor
	~Organizer(); // Destructor

	virtual void Input(istream& in) override;
	virtual void Output(ostream& out) const override;
};