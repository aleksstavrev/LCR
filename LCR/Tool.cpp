#include "Tool.h"

Tool::Tool() : Resource(), Usage(nullptr) {}

Tool::~Tool() {
    delete[] Usage;
}

Tool::Tool(const Tool& rhs) : Resource(rhs) {
    Usage = OrganizationEntity::allocateAndCopy(rhs.Usage);
}

Tool& Tool::operator=(const Tool& rhs) {
    if (this != &rhs) {
        Resource::operator=(rhs);
        delete[] Usage;
        Usage = OrganizationEntity::allocateAndCopy(rhs.Usage);
    }
    return *this;
}

void Tool::Input(istream& in) {
    Resource::Input(in);
    char buffer[200];
    cout << "Enter tool usage description: ";
    in >> buffer;
    delete[] Usage;
    Usage = OrganizationEntity::allocateAndCopy(buffer);
}

void Tool::Output(ostream& out) const {
    out << "[TOOL] Name: " << getName()
        << " | Qty: " << getQuantity()
        << " | Usage: " << (Usage ? Usage : "") << endl;
}