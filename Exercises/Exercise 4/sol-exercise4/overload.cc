#include <iostream>
using std::cout;


// #define USING

struct B{
     void f(int x) {cout << "B::f(" << x << ")\n";}
};

struct D :public B {
#ifdef USING
    // You can make the functions f from B visible in D, and thereby
    // enabling overload resolution to find both f(int) and f()
    using B::f;
#endif
    void f() {cout << "D::f()\n";}
};

void example1()
{
    B b;
    D d;

    b.f(5);
    d.f();
#ifdef USING
    // and with f(int) visible in D, this call works
    d.f(17);
#else
    // or you can explicitly call B::f(int) on a D instance
    d.B::f(42);
#endif
}

// void example2()
// {
//     B& r = d;
//     r.f(); // This does not work, as the static type of r is B&, 
//            // and there is no B::f(). The fact that r references
//            // a D object does not affect this, as name resolution
//            // is done on the static type of a variable.
//            // Making f(int) virtual would not help as f(int) and
//            // f() are two different functions.
// }


int main()
{
    example1();
}
