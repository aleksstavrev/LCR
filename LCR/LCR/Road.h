#pragma once
#include "Target.h"

class Road : public Target {
private:
	double LengthKm;
public:
	Road();
	~Road() override = default;

	void Input(istream& in) override;
	void Output(ostream& out) const override;
};