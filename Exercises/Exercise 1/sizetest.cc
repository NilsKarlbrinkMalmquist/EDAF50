/*
 * Explain the output of the following program.
 */

#include "point.h"

#include <iostream>

using std::cout;
using std::endl;
int main() {
	Point p(1, 2);
	cout << "sizeof(p)      = " << sizeof(p) << '\n';
	
	Point* pp = new Point(1, 2);
	cout << "sizeof(pp)     = " << sizeof(pp) << '\n';
	cout << "sizeof(*pp)    = " << sizeof(*pp) << endl;
	
	delete pp;
}
