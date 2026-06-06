#pragma once
#include "Volunteer.h"
#include "Resource.h"

template <typename T_Target>
class RestorationTask {
private:
    T_Target* target;
    Volunteer* volunteer;
    Resource* resource;
    int qty;
public:
    RestorationTask(T_Target* t, Volunteer* v, Resource* r, int q)
        : target(t), volunteer(v), resource(r), qty(q) {
    }

    void execute() {
        if (qty > resource->getQuantity()) {
            throw runtime_error("ERROR: Not enough resources to complete the task!");
        }
        resource->use(qty);
        volunteer->addPoints(50);
    }
};