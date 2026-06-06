#pragma once
#include <iostream>
#include <stdexcept>
#include "Volunteer.h"
#include "Resource.h"

template <typename T>
class RestorationTask {
public:
	RestorationTast(T * t, Volunteer* v, Resource* r, int q):
		target(t), volunteer(v), resource(r), qty(q) { }
	void execute() {
		std::cout << "Start of the volunteer's task" << std::endl;
		std::cout << "\n";

		if (qty > resource->getQuality()) {
			throw std::runtime_error("Error: The dask is not done. Not enough quantity.");
		}

		target->displayInfo();
		volunteer->displayInfo();
		resource->use(qty);

		volunteer->addPoint(50);

		std::cout << "Ready! The task is done." << std::endl;
		std::cout << "\n";
	}
private:
	T* target;
	Volunteer* volunteer;
	Resource* resource;
	int qty;
};