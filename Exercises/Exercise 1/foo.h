#include "bar.h"
#include <iostream>
using std::cout;
using std::endl;


class Foo{
public:
    Foo(const Bar& b, int x) :abar(b), val{x} {}
    void print() {cout << "Foo(" << val << ")\n"; abar.print();}
private:
    Bar abar;
    int val;
};
