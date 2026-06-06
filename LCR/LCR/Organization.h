#pragma once
#include "Organizer.h"

class Organization : public Organizer {
private:
	char* Address;
	double Money;
public:
	Organization();
	~Organization() override;

	Organization(const Organization& rhs);
	Organization& operator=(const Organization& rhs);

	void Input(istream& in) override;
	void Output(ostream& out) const override;

	void setAddress();
	void setMoney();

	void getAddress(ostream& out) const;
	void getMoney(ostream& out) const;
};