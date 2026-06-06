#include <iostream>
#include "Road.h"

Road::Road() : Target(), lengthKm(0.0) { }
Road::Road(const char* id, const char* name, const char* description, double lengthKm) :
	Target(id, name, description), lengthKm(lengthKm) { }

void Road::displayInfo() const {
	std::cout << "Road ID " << getId() << " Name/Location: " << getName()
		<< " Description: " << getDescription() << " Length: " << lengthKm << " km\n";
}
double Road::getLengthKm() const {
	return lengthKm;
}
void Road::setLengthKm(double length) {
	lengthKm = length;
}