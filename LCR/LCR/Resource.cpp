#include "Resource.h"

Resource::Resource() : Name(nullptr), Quantity(0) {}

Resource::~Resource() {
	delete[] Name;
}

Resource::Resource(const Resource& rhs) {
	Name = OrganizationEntity::allocateAndCopy(rhs.Name);
	Quantity = rhs.Quantity;
}

Resource& Resource::operator=(const Resource& rhs) {
	if (this != &rhs) {
		delete[] Name;
		Name = OrganizationEntity::allocateAndCopy(rhs.Name);
		Quantity = rhs.Quantity;
	}
	return *this;
}
void Resource::Input(istream& in) {
	char buffer[200];
	cout << "Enter resource name: "; in >> buffer;
	delete[] Name;
	Name = OrganizationEntity::allocateAndCopy(buffer);

	cout << "Enter quantity: ";      in >> Quantity;
}

void Resource::Output(ostream& out) const {
	out << "Resource: " << (Name ? Name : "") << " | Qty: " << Quantity << endl;
}