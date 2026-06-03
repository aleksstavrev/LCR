#include "Road.h"

Road::Road() : Target(), LengthKm(0.0) {}

void Road::Input(istream& in) {
	Target::Input(in);
	cout << "Enter length in km: "; 
	in >> LengthKm;
}

void Road::Output(ostream& out) const {
	out << "[ROAD] Location: " << (Location ? Location : "")
		<< " | Length: " << LengthKm << " km | Info: " << (Description ? Description : "") << endl;
}