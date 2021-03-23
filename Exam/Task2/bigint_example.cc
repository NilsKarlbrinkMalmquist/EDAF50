//Nils Karlbrink Malmquist, 19971017-2959, ni4838ma-s
#include <iostream>
#include <sstream>
#include <string>
#include "bigint.h"

using std::cout;

BigInteger prompt(const std::string& msg)
{
    cout << msg << "\n";
    BigInteger res;
    std::cin >> res;
    return res;
}

int main()
{
    auto x = prompt("enter a number:");
    auto y = prompt("enter a number:");
    cout << x << " + " << y << " = " << x + y << "\n";
}
