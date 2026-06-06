#pragma once
#include "OrganizationEntity.h"

class Resource :public OrganizationEntity {
public:
	Resource();
	Resource(const char* id, const char* name, int qty);
	virtual ~Resource() = default;
	Resource(const Resource& rhs) = default;
	Resource& operator= (const Resource& rhs) = default;

	int getQuantity() const;
	void setQuantity(int);
	
	virtual void use(int) = 0;

protected:
	int quantity;
};