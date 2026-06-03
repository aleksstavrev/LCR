#pragma once
#include "Resource.h"

class Tool : public Resource {
private:
    char* Usage;
public:
    Tool();
    ~Tool() override;

    Tool(const Tool& rhs);
    Tool& operator=(const Tool& rhs);

    void Input(istream& in) override;
    void Output(ostream& out) const override;
};