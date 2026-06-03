#pragma once
#include "OrganizationEntity.h"

class Resource : public OrganizationEntity {
protected:
	char* Name;
	int Quantity;
public:
	Resource();
	virtual ~Resource() override;

	Resource(const Resource& rhs);
	Resource& operator=(const Resource& rhs);

	void Input(istream& in) override;
	void Output(ostream& out) const override;

	int getQuantity() const { return Quantity; }
	void use(int qty) { Quantity -= qty; }
	const char* getName() const { return Name ? Name : ""; }
};