#pragma once
#include "Person.h"

class Volunteer : public Person {
protected:
	static int counter;
	int Id;
	double Donation;
	int Points;
public:
	Volunteer();
	~Volunteer() override = default;

	void Input(istream& in) override;
	void Output(ostream& out) const override;

	void setDonation();
	void getDonation(ostream& out) const;

	void addPoints(int pts) { Points += pts; }
	int getPoints() const { return Points; }
};