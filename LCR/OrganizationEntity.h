#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Libraries.h"

class OrganizationEntity {
public:
    OrganizationEntity() = default;
    virtual ~OrganizationEntity() = default;

    static char* allocateAndCopy(const char* source) {
        if (!source) return nullptr;
        char* destination = new char[strlen(source) + 1];
        strcpy_s(destination, strlen(source) + 1, source);
        return destination;
    }

    virtual void Input(istream& in) = 0;
    virtual void Output(ostream& out) const = 0;
};