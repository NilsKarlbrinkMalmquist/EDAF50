#include <iostream>
using std::cout;

struct B{
     void f(int x) {cout << "B::f(" << x << ")\n";}
};

struct D :public B {
    void f() {cout << "D::f()\n";}
};

void example1()
{
    B b;
    D d;

    b.f(5);
    d.f();
    d.f(17);
}

void example2()
{
    B& r = d;
    r.f();
}

int main()
{
    example1();
    example2();
}
