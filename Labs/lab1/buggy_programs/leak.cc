#include <iostream>
using std::cout;

struct Foo{
    Foo(int s) :p{new int[s]} {}
    int* p;
};

void example1()
{
    Foo f(10);
    {
        cout << "entering inner block\n";
        Foo g(20);
        cout << "leaving inner block\n";
    }
}

int main()
{
    example1();
}
