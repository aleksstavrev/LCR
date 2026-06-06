#include <iostream>
#include "Hygiene.h"

Hygiene::Hygiene() : Resource(), isSterile(false) {}
Hygiene::Hygiene(const char* id, const char* name, int qty, bool sterile) :
	Resource(id, name, qty), isSterile(sterile) { }

void Hygiene::use(int qty) {
	if (qty > quantity) {
		std::cout << "Not enough quantity to use.\n";
		return;
	}
	quantity -= qty;
}
void Hygiene::displayInfo() const {
	std::cout << "Higiene " << getName() << " Quantity: " << quantity
		<< " Sterile: " << (isSterile ? "Yes" : "No") << "\n";
}

bool Hygiene::getIsSterile() const {
	return isSterile;
}
void Hygiene::setIsSterile(bool sterile) {
	isSterile = sterile;
}