#pragma once
#include "OrganizationEntity.h"

class Target : public OrganizationEntity {
public:
	Target();
	Target(const char* id, const char* name, const char* description);
	~Target() override;
	Target(const Target& rhs);
	Target& operator= (const Target& rhs);

	void displayInfo() const override = 0;
	const char* getDescription() const;
	void setDescription(const char* desc);

	private:
		char* description;
};
