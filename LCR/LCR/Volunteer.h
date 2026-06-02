#pragma once
#include "Person.h"

class Volunteer : public Person {
protected:
	static int counter;
	int Id;
	double Donation;
public:
	Volunteer(); // Default constructor
	~Volunteer(); // Destructor

	void Input(istream& in) override;
	void Output(ostream& out) const override;

	void setDonation();

	void getDonation(ostream& out);
};