#pragma once
#include "Target.h"

class Building : public Target {
private:
	char* BuildingType;
public:
	Building();
	~Building() override;

	Building(const Building& rhs);
	Building& operator=(const Building& rhs);

	void Input(istream& in) override;
	void Output(ostream& out) const override;
};