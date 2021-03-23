//Nils Karlbrink Malmquist, 19971017-2959, ni4838ma-s
#include <iostream>
#include <sstream>
#include <string>
#include "bigint.h"

using std::cout;

bool check(const BigInteger& actual, const BigInteger& expected)
{
    std::stringstream sum;
    sum << actual;

    std::stringstream exp;
    exp << expected;

    auto fail = sum.str() != exp.str();
    if (fail)
        cout << "Fail: " << sum.str() << " != " << exp.str() << "\n";
    else
        cout << "OK\n";

    if (actual != expected) {
        cout << "Fail: " << actual << " != " << expected
             << " is true (should be false)\n";
        fail = true;
    }

    if (!(actual == expected)) {
        cout << "Fail: " << actual << " == " << expected
             << " is false (should be true)\n";
        fail = true;
    }

    return !fail;
}

bool test_ctors_and_trim()
{
    bool pass{true};

    BigInteger a{"1000"};
    BigInteger b{"01000"};
    BigInteger c{"00001000"};

    pass &= check(a, b);
    pass &= check(b, c);
    pass &= check(a, c);

    BigInteger d(1000);
    pass &= check(a, d);
    pass &= check(b, d);
    pass &= check(c, d);

    return pass;
}

template <typename S, typename T>
bool do_test_add(const S& as, const T& bs, std::string rs)
{
    bool pass{true};
    BigInteger a(as);
    BigInteger b(bs);
    BigInteger r(rs);
    //BigInteger s = a + b;
    //pass &= check(s, r);
    pass &= check(a, {as});
    pass &= check(b, {bs});
    return pass;
}

bool test_addition()
{
    cout << "test_addition:\n";
    bool pass{true};
    pass &= do_test_add(std::string("111"), std::string("222"), "333");
    pass &= do_test_add(111, std::string("222"), "333");
    pass &= do_test_add(std::string("111"), 222, "333");
    pass &= do_test_add(std::string("100000000001"),
                        std::string("900000000009"), "1000000000010");
    pass &= do_test_add(std::string("1000"), std::string("10000"), "11000");
    pass &= do_test_add(1000, 90000, "91000");
    pass &= do_test_add(std::string("101"), std::string("9999"), "10100");
    pass &= do_test_add(
        std::string{"111111111111111111111111111111111111111111111111111"},
        std::string{"111111111111111111111111111111111111111111111111111"},
        "222222222222222222222222222222222222222222222222222");

    return pass;
}

bool test_compound_assignment()
{
    cout << "test_compound_assignment:\n";
    bool pass{true};

    BigInteger f("421000");
    BigInteger g("9876");
    f += g;
    pass &= check(f, BigInteger("430876"));
    pass &= check(g, BigInteger("9876"));

    BigInteger j("000001");
    BigInteger k(9999999);
    pass &= check(j += k, BigInteger(10000000));
    pass &= check(j, BigInteger(10000000));
    pass &= check(k, BigInteger(9999999));

    return pass;
}
int main()
{
    bool pass{true};

    pass &= test_ctors_and_trim();
    pass &= test_addition();
    pass &= test_compound_assignment();

    cout << "All tests " << (pass ? "passed\n" : "not passed\n");
}

