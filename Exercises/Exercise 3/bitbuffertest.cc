#include "bitbuffer.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main() {
	BitBuffer buf(cout);
	int n;
	while (cin >> n) {
		buf.put(n != 0);
	}
	cout << endl;
}
