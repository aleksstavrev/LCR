#pragma once
#include "OrganizationEntity.h"

class Target : public OrganizationEntity {
protected:
	char* Location;
	char* Description;
public:
	Target();
	virtual ~Target() override;

	Target(const Target& rhs);
	Target& operator=(const Target& rhs);

	void Input(istream& in) override;
	void Output(ostream& out) const override = 0;
};