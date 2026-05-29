#include<iostream>
#include "Tool.h"

Tool::Tool(): Resource(), usage(nullptr) {}
Tool::Tool(const char* id, const char* name, int qty, const char* useDesc):
	Resource(id, name, qty) {
	this->usage = allocateAndCopy(useDesc);
}
Tool::~Tool() {
	if(usage != nullptr) {
		delete[] usage;
	}
}
Tool::Tool(const Tool& rhs) : Resource(rhs) {
	usage = OrganizationEntity::allocateAndCopy(rhs.usage);
}
Tool& Tool::operator= (const Tool& rhs) {
	if(this!= &rhs) {
		Resource::operator=(rhs);
		if (usage != nullptr) {
			delete[] usage;
		}
		usage = OrganizationEntity::allocateAndCopy(rhs.usage);
	}
	return *this;
}
void Tool::use(int qty) {
	if (qty > quantity) {
		std::cout << "Not enough quantity to use.\n";
		return;
	}
	quantity -= qty;
}
void Tool::displayInfo() const {
	std::cout << "Tool " << getName() << " Quantity: " << quantity
		<< " Usage: " << getUsage() << "\n";
}
const char* Tool::getUsage() const {
	return usage;
}
void Tool::setUsage(const char* usage) {
	if (this->usage == usage) return;
	if (this->usage != nullptr) {
		delete[] this->usage;
	}
	this->usage = OrganizationEntity::allocateAndCopy(usage);
}