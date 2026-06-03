#include "Hygiene.h"

Hygiene::Hygiene() : Resource(), IsSterile(false) {}

void Hygiene::Input(istream& in) {
    Resource::Input(in);
    cout << "Is it sterile? (1 for Yes / 0 for No): ";
    in >> IsSterile;
}

void Hygiene::Output(ostream& out) const {
    out << "[HYGIENE] Name: " << getName()
        << " | Qty: " << getQuantity()
        << " | Sterile: " << (IsSterile ? "Yes" : "No") << endl;
}