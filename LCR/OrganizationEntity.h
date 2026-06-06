#pragma once

class OrganizationEntity {
public:
	OrganizationEntity();
	OrganizationEntity(const char* id, const char* name);
	virtual ~OrganizationEntity();
	OrganizationEntity(const OrganizationEntity& rhs);
	OrganizationEntity& operator=(const OrganizationEntity& rhs);

	virtual void displayInfo() const = 0;

	const char* getId() const;
	void setId(const char* newId);

	const char* getName() const;
	void setName(const char* newName);

	static char* allocateAndCopy(const char* source);
protected:
	char* id;
	char* name;
	
};
