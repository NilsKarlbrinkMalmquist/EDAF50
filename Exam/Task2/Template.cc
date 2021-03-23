//Nils Karlbrink Malmquist, 19971017-2959, ni4838ma-s

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>
#include <fstream>
#include <cassert>
#include <sstream>
#include <memory>
#include <functional>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::map;
using std::endl;
using std::pair;

class A{
public:
    A();
    void inserEachDigit(int x){
        if(x >= 10){
            inserEachDigit(x / 10);
        }
        int digit = x % 10;
        bigIntVec.push_back(digit);
        cout <<digit <<" ";
    }
private:
    vector<int> bigIntVec;
};



int main(){
    A a;
    a.inserEachDigit(123);

    return 0;
}