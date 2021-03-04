#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

#include <iostream>

class Circle : public Shape {
public:
	void print() const {
		std::cout << "I'm a Circle" << std::endl;
	}
};

#endif
