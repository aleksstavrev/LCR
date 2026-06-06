#pragma once
#include "Person.h"

class Volunteer : public Person {
public:
	Volunteer();
	Volunteer(const char* id, const char* name, int age);
	~Volunteer() override = default;
	Volunteer(const Volunteer& rhs) = default;
	Volunteer& operator= (const Volunteer& rhs) = default;

	void displayInfo() const override;
	int getPoints() const;
	void setPoints(int pts);
	void addPoints(int pts);
private:
	int points;
};