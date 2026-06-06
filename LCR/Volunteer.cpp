#include <iostream>
#include "Volunteer.h"

Volunteer::Volunteer() : Person(), points(0) { }
Volunteer::Volunteer(const char* id, const char* name, int age):
 Person(id, name, age) ,points(0){ }

void Volunteer::displayInfo() const {
	std::cout << "Volunteer ID " << getId() << " Name: " << getName()
		<< " Age:" << getAge() << " Points: " << getPoints() << "\n";
}
int Volunteer::getPoints() const {
	return points;
}
void Volunteer::setPoints(int pts) {
	points = pts;
}
void Volunteer::addPoints(int pts) {
	points += pts;
}