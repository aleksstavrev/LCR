#include "Organizer.h"

int Organizer::counter = 1;

Organizer::Organizer() : Person() {
	Id = counter++;
}

void Organizer::Input(istream& in) {
	Person::Input(in);
}

void Organizer::Output(ostream& out) const {
	out << "Id: " << Id << endl;
	Person::Output(out);
}