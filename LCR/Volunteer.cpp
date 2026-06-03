#include "Volunteer.h"

int Volunteer::counter = 1;

Volunteer::Volunteer() : Person(), Donation(0.0), Points(0) {
	Id = counter++;
}

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

void Volunteer::getDonation(ostream& out) const {
	out << "Donation: " << Donation << endl;
}