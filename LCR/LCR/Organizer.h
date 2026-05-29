#pragma once
#include "Person.h"

class Organizer : public Person {
private: 
	char* position;
public:
	Organizer();
	Organizer(const char* id, const char* name, int age, const char* pos);
	//~Organizer() override = default;
	//Organizer(const Organizer& rhs) = default;
	//Organizer& operator= (const Organizer& rhs) = default;

	void displayInfo() const override;

	const char* getPosition() const;
	void setPosition(const char* pos);
};