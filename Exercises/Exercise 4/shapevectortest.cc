/*
 * shapevectortest.cc: check the identity of objects that are in 
 * a vector.
 */

#include "shape.h"
#include "square.h"
#include "circle.h"

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <memory>

using namespace std;

int main() {
	/*
	 * A vector of Shape objects
	 */
	vector<unique_ptr<Shape>> shapes;
	const size_t NBR_SHAPES = 10;
	
	/*
	 * Store 10 squares and circles in the vector.
	 */
	default_random_engine re(time(0));
	bernoulli_distribution bd;
	for (int i = 0; i != NBR_SHAPES; ++i) {
		if (bd(re)) {
			shapes.push_back(unique_ptr<Shape>(new Square()));
		} else {
			shapes.push_back(unique_ptr<Shape>(new Circle()));
		}
	}
	
	/*
	 * Print the shapes.
	 */
	for (const auto& s : shapes) {
		s->print();
	}

	/*
	for (Shape* s : shapes) {
		delete s;
	}
	shapes.clear();*/
}
