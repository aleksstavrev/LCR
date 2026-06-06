#pragma once
#include "Person.h"

class Organizer : public Person {
protected:
	static int counter;
	int Id;
public:
	Organizer();
	~Organizer() override = default;

	void Input(istream& in) override;
	void Output(ostream& out) const override;
};