#include <cassert>
#include <iostream>
#include "p3.h"

template <typename T>
void test_assign(Vector<T>& v, const T& val1, const T& val2)
{
assert(v.size() >= 2);
assert(val1 != val2); // test sanity checks
v[0] = val1;
assert(v[0] == val1);
v[1] = val2;
assert(v[1] == val2);
assert(v[0] != v[1]);
}

template <typename T>
void test_read(const Vector<T>& v, const T& val1, const T& val2){
    assert(v.size() >= 2);
    assert(v[0] == val1);
    assert(v[1] == val2);
}

void test_create(){
    Vector<int> v1(5);
    assert(v1.size() == 5);
    for(int i=0; i< v1.size(); ++i){
        v1[i]=i;
    }
    Vector<int> v2{0,1,2,3,4};
    assert(v2.size() == v1.size());
    assert(v1 == v2);
}

int main(){
    Vector<int> v(2);
    auto val1 = 17;
    auto val2 = 42;
    test_assign(v, val1, val2);
    test_read(v, val1, val2);
    test_create();
    std::cout << "Tests passed."<<std::endl;
}

