#pragma once
#include "Resource.h"

class Hygiene : public Resource {
private:
    bool IsSterile;
public:
    Hygiene();
    ~Hygiene() override = default;

    void Input(istream& in) override;
    void Output(ostream& out) const override;
};