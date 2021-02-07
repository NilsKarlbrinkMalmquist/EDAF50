#include <iostream>
using std::cout;
using std::endl;


class Foo {
private:
    static int created;
    static int alive;
public:
    Foo() {++created; ++alive;}
    ~Foo() {--alive;}

    static void print_count();
};

int Foo::created{0};
int Foo::alive{0};

void Foo::print_count(){
  cout <<"Alive foo objects: " <<alive <<" / " <<created << " created" <<endl;
}

void example()
{
    {
        Foo a;
        a.print_count();

        Foo b;
        b.print_count();
    }

    {
        Foo c;
        Foo::print_count();
    }
    Foo::print_count();
}

int main()
{
    example();
}
