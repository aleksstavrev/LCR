#pragma once
#include "Organizer.h"

class Organization : public Organizer {
private:
	char Address[100];
	double Money;
public:
	Organization(); // Default constructor
	~Organization(); // Destructor

	void Input(istream& in) override;
	void Output(ostream& out) const override;

	void setAddress();
	void setMoney();

	void getAddress(ostream& out);
	void getMoney(ostream& out);
};