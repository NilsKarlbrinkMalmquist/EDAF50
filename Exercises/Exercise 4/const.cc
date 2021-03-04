#include <iostream>
using std::cout;
using std::endl;


class Foo{
public:
    Foo(const std::string& s = "I am uninitialized") :msg{s} {}
    void print(std::ostream& os) const {os << msg << '\n';}
    void operator()(std::ostream& os) {os << "Non-const operator(): "; print(os);}
    void operator()(std::ostream& os) const {os << "Const operator(): "; print(os);}
private:
    std::string msg;
};


void foo(const Foo& f)
{
    cout << "\nIn foo(const Foo&):\n";
    f.print(cout);
    f(cout);
}

void bar(Foo& f)
{
    cout << "\nIn bar(Foo&):\n";
    f.print(cout);
    f(cout);
}

void qux(Foo& f)
{
    cout << "\nIn qux(Foo&):\n";
    f.print(cout);
    f(cout);
}

void qux(const Foo& f)
{
    cout << "\nIn qux(const Foo&):\n";
    f.print(cout);
    f(cout);
}

void example()
{
    Foo ncf("I am not const");

    foo(ncf);
    bar(ncf);

    const Foo cf("I am const");

    foo(cf);
    // uncomment the below line and make sure you understand the error message
    // bar(cf);

    qux(ncf);
    qux(cf);
}

int main()
{
    example();
}
