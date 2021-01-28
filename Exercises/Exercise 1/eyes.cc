#include "eyes.h"
#include <iostream>
using std::cout;

void print(eye_colour x)
{
    switch(x) {
        case eye_colour::brown: cout << "brown"; break;
        case eye_colour::blue: cout << "blue"; break;
        case eye_colour::green: cout << "green"; break;
        default: cout << "???"; break;
    }
    cout << " eyes\n";
}
