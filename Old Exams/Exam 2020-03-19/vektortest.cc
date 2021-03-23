#include <iostream>
#include <vector>
#include "vektor.h"

using std::cout;
using std::endl;

void test(){
    Vektor<int> a(10);
    auto c = Counter<int>(100,10);
    generate2(a, c);
    for(auto x : a) {
    cout << x << " ";
    }
    cout << endl;
}


void test2(){
    std::vector<int> a(10);
    auto c = Counter<int>(100,10);
    generate2(a, c);
    //print(a);
    for(auto& x : a){
        cout <<x  <<" ";
    }
    cout <<endl;
}

int main(){
    test();
    cout << endl;
    test2();
}
