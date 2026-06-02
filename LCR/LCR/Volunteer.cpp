#include "Volunteer.h"

Volunteer::Volunteer() {
	Id = counter++;
}

Volunteer::~Volunteer() {}; // Destructor

int Volunteer::counter = 1;

void Volunteer::Input(istream& in) {
	Person::Input(in);
}

void Volunteer::Output(ostream& out) const {
	out << "Id: " << Id << endl;

	Person::Output(out);
}

void Volunteer::setDonation() {
	double donation;
	cin >> donation;
	Donation = donation;
}

void Volunteer::getDonation(ostream& out) {
	out << "Donation: " << Donation << endl;
}