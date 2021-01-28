#include "traffic_light.h"
#include <iostream>
using std::cout;

void print(traffic_light x)
{
    switch(x) {
        case traffic_light::red: cout << "red"; break;
        case traffic_light::yellow: cout << "yellow"; break;
        case traffic_light::green: cout << "green"; break;
        default: cout << "???"; break;
    }
    cout << " light\n";
}
