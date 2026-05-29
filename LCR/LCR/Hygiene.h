#pragma once

#include "Resource.h"

class Hygiene : public Resource {
public:
	Hygiene();
	Hygiene(const char* id, const char* name, int qty, bool sterile);
	~Hygiene() override = default;

	Hygiene(const Hygiene& rhs) = default;
	Hygiene& operator= (const Hygiene& rhs) = default;

	void use(int qty) override;
	void displayInfo() const override;

	bool getIsSterile() const;
	void setIsSterile(bool sterile);
private:
	bool isSterile;
};