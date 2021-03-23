//Nils Karlbrink Malmquist, 19971017-2959, ni4838ma-s
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "bigint.h"

using std::cout;

bool test_ctor_failure()
{
    cout << "test_ctor_failure:\n";
    // The constructor should throw if it fails to establish invariant
    try {
        BigInteger e("123kalle");
        cout << "Fail: " << e << "\n";
        return false;
    } catch (std::invalid_argument& e) {
        cout << "OK: " << e.what() << "\n";
        return true;
    }
}

bool test_input_failure()
{
    cout << "test_input_failure:\n";
    // The input operator should detect wrong input

    std::istringstream s("foo");
    BigInteger f;
    s >> f;
    if (s.fail()) {
        cout << "OK\n";
        return true;
    } else {
        cout << "Fail!: read foo as number " << f << "\n";
        return false;
    }
}

bool test_input_failure2()
{
    cout << "test_input_failure2:\n";
    // The input operator should detect wrong input
    // but not read too much from the stream before
    // doing so.
    // Here, it is OK if the input operator reads
    // the entire string donald before signalling
    // the failure.

    std::string test{"donald duck"};
    std::istringstream s(test);
    BigInteger f;
    s >> f;
    if (s.fail()) {
        if (s.eof()) {
            cout << "Fail: read too much from stream\n";
            return false;
        } else {
            s.clear();
            std::string x;
            getline(s, x);
            if (x == "donald duck" || x == "onald duck" || x == " duck" || x == "duck") {
                cout << "OK\n";
                return true;
            } else {
                cout << "Fail!: read too much from stream. remainder = " << x
                     << "\n";
                return false;
            }
        }
    } else {
        cout << "Fail!: read " << test << " as number " << f << "\n";
        return false;
    }
}

void test_bigint_errors()
{
    bool pass{true};

    pass &= test_ctor_failure();
    pass &= test_input_failure();
    pass &= test_input_failure2();

    cout << "All tests " << (pass ? "passed\n" : "not passed\n");
}

int main() { test_bigint_errors(); }
