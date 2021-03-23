/*#include <iomanip>
#include <iostream>

using std::cout;

class Foo {
public:
    bool b;
    Foo(bool x) :b(x)
    {
        cout << "Foo(" << std::boolalpha << b << ")\n";
    }
};

int main()
{
    //Foo* f = new Foo(0);
    Foo f(0);
    cout << "f.b is " << std::boolalpha << f.b << std::endl;

    return 0;
}*/

#include <iostream>
#include <string>
using std::cout;

/*std::string& concatenate(const char* c, int i)
{
    std::string res(c);
    return (res.append(std::to_string(i)));
}

bool test()
{
    const auto& res = concatenate("Hello",17);
    std::string exp = "Hello";
    if(res != exp){
        cout << "expected " << exp << ", got " << res << '\n';
        return false;
    }
    return true;
}

int main()
{
    if(test()) cout << "success\n";
}*/
#include <iostream>
using std::cout;

class Base {
public :
    Base (int i=0) : x { i } {}
    virtual void print() const { cout << " Base : " << x << '\n' ;}
protected :
    int x;
};

class Derived : public Base {
public:
    // ADD SOMETHING HERE 
    Derived(int i=0) :Base(i) {}
    virtual void print() const {cout << "Derived : " << x << '\n';}
};

int main ()
{
    Derived b ;
    b.print ();
    Derived b2 (5); 
    b2.print ();
}