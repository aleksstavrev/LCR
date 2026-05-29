#include "Resource.h"

Resource::Resource():OrganizationEntity(), quantity(0) { }

Resource::Resource(const char* id, const char* name, int qty) : OrganizationEntity(id, name), quantity(qty) { }

int Resource::getQuantity() const {
	return quantity;
}
void Resource::setQuantity(int qty) {
	quantity = qty;
}