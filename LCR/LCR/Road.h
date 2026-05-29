#pragma once
#include "Target.h"

class Road : public Target {
public:
	Road();
	Road(const char* id, const char* name, const char* description, double lengthKm);
	~Road() override = default;
	Road(const Road& rhs) = default;
	Road& operator= (const Road& rhs) = default;

	void displayInfo() const override;
	double getLengthKm() const;
	void setLengthKm(double length);
private:
	double lengthKm;
};
