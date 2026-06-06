#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "OrganizationEntity.h"

char* OrganizationEntity::allocateAndCopy(const char* source) {
	if (!source) return nullptr;
	char* destination = new char[strlen(source) + 1];
	strcpy(destination, source);
	return destination;
}
OrganizationEntity::OrganizationEntity() : id(nullptr), name(nullptr) {}
OrganizationEntity::OrganizationEntity(const char* id, const char* name) {
	this->id = allocateAndCopy(id);
	this->name = allocateAndCopy(name);
}
OrganizationEntity::~OrganizationEntity() {
	if (id != nullptr && name != nullptr) {
		delete[] id;
		delete[] name;
	}
}
OrganizationEntity::OrganizationEntity(const OrganizationEntity& rhs) {
	id = allocateAndCopy(rhs.id);
	name = allocateAndCopy(rhs.name);
}
OrganizationEntity& OrganizationEntity::operator=(const OrganizationEntity& rhs) {
	if (this != &rhs) {
		//delete[] id; - pogledni
		//delete[] name; - pogledni
		id = allocateAndCopy(rhs.id);
		name = allocateAndCopy(rhs.name);
	}
	return *this;
}

const char* OrganizationEntity::getId() const {
	return id;
}
void OrganizationEntity::setId(const char* newId) {
	if (this->id == newId) return;
	if (this->id != nullptr) delete[] this->id;
	this->id = allocateAndCopy(newId);
}

const char* OrganizationEntity::getName() const {
	return name;
}
void OrganizationEntity::setName(const char* newName) {
	if (this->name == newName) return;
	if (this->name != nullptr) delete[] this-> name;
	this->name = allocateAndCopy(newName);
}