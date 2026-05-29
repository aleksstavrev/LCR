#pragma once
#include "Resource.h"

class Tool : public Resource {
public:
	Tool();
	Tool(const char* id, const char* name, int qty, const char* useDesc);
	~Tool() override;
	Tool(const Tool& rhs);
	Tool& operator= (const Tool& rhs);
	void use(int qty) override;
	void displayInfo() const override;
	const char* getUsage() const;
	void setUsage(const char* usage);
private:
	char* usage;
};