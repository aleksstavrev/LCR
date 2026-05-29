#pragma once
#include "Target.h"

class Building : public Target {
	public:
	Building();
	Building(const char* id, const char* name, const char* description, const char* type);
	~Building() override;
	Building(const Building& rhs);
	Building& operator= (const Building& rhs);

	void displayInfo() const override;
	const char* getBuildingType() const;
	void setBuildingType(const char* type);
private:
	char* buildingType;
};