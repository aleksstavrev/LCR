#pragma once
#include <vector>
#include "OrganizationEntity.h"

class Organization {
public:
	Organization();
	Organization(const char* name);
	~Organization();
	Organization(const Organization& rhs);
	Organization& operator=(const Organization& rhs);

	void addEntity(OrganizationEntity* entity);
	void showAllEntities() const;

	const char* getOrgName() const;
	void setOrgName(const char* name);
private:
	char* orgName;
	std::vector<OrganizationEntity*> entities;
	void clearEntities();
};