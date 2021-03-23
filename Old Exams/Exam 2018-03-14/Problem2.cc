#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
//#include <cstring>
using std::cout;
using std::endl;

//Alternativ1: gör string istället
/*class Foo{
public:
    Foo() :Foo(-1, "Foo") {}
    Foo(int x, const char* cs) :v{x}, s{cs} {}
    ~Foo() = default;
    std::string get_s() const {return s;}
    int get_v() const {return v;}
private:
    int v;
    std::string s;
};*/

//Alternativ 2: lägg till en kopykonstruktor
class Foo{
public:
    Foo() :Foo(-1, "Foo") {}
    Foo(int x, const char* cs) :v{x},s{new char[std::strlen(cs)+1]} {std::strcpy(s,cs);}
    Foo(const Foo& other) :Foo(other.v, other.s) {}
    ~Foo() {delete[](s);}
    std::string get_s() const {return std::string(s);}
    int get_v() const {return v;}
private:
    int v;
    char* s;
};


int main(){
    std::vector<Foo> v;
    v.reserve(4);

    v.emplace_back(1, "Hello");
    v.emplace_back(2, "World");
    v.emplace_back(3, "Testing");
    v.emplace_back(5, "Testing"); 

    auto res = std::find_if(begin(v), end(v), [](Foo f){return f.get_v() == 2;});

    if(res != v.end()){
        cout << "found " << res->get_s() << endl;
    }    
    else {
        cout << "not found" << endl;
    }    
}