//Nils Karlbrink Malmquist, 19971017-2959, ni4838ma-s
#include <algorithm>
#include <iostream>
#include <vector>
#include "fib.h"

using std::cout;

const std::vector<int> fs{0,  1,  1,   2,   3,   5,   8,   13,   21,   34,
                          55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181};

template <typename C1, typename C2>
void check_equal(const C1& v, const C2& exp)
{
    if (v.size() != exp.size()) { // sanity check
        cout << "Mismatch: different sizes\n";
    } else {
        auto res = std::mismatch(begin(v), end(v), std::begin(exp));
        while (res.first != end(v)) {
            cout << "Mismatch: expected " << *res.second << " got "
                 << *res.first << "\n";
            res = std::mismatch(++res.first, end(v), ++res.second);
        }
    }
}

template <typename C1>
void print_and_check(const C1& v)
{
    for (auto x : v) {
        cout << x << " ";
    }
    cout << "\n";

    check_equal(v, fs);
    cout << "Test done\n";
}

template <typename T>
bool check(const T& v, const T& exp)
{
    auto res = v != exp;
    if (res)
        cout << "*** expected " << exp << ", got " << v << "\n";
    return res;
}

bool test_iterator_basic()
{
    FibonacciIterator fi{};
    auto fail = check(*fi, 0);
    fail |= check(*fi, 0);
    ++fi;
    fail |= check(*fi, 1);
    fail |= check(*fi, 1);
    ++fi;
    fail |= check(*fi, 1);
    ++fi;
    fail |= check(*fi, 2);
    fail |= check(*fi, 2);
    auto tmp = fi++;
    fail |= check(tmp == fi, false);
    fail |= check(*tmp, 2);
    fail |= check(*fi, 3);
    fail |= check(*++tmp, 3);
    fail |= check(*fi, 3);
    fail |= check(tmp == fi, true);

    return fail;
}

bool test_iterator_equality()
{
    FibonacciIterator fi1{};
    FibonacciIterator fi2 = fi1;

    auto fail = check(fi1 == fi2, true);

    constexpr int n = 5;
    for(int i=0; i<n; ++i) ++fi1;

    fail |= check(fi1 == fi2, false);
    fail |= check(fi1 != fi2, true);

    int dist = std::distance(fi2, fi1);
    fail |= check(dist, n);

    return fail;
}

void test_iterator()
{
    auto fail = test_iterator_basic();
    fail |= test_iterator_equality();
    if (!fail) {
        cout << "initial test OK\n";
    }
}

void example_and_test_iterator()
{
    cout << "example_and_test_iterator:\n";

    test_iterator();
    std::vector<int> v(fs.size());
    std::copy_n(FibonacciIterator{}, v.size(), v.begin());

    check(std::equal(begin(v), end(v), FibonacciIterator{}), true);

    print_and_check(v);

}

void test_functor()
{
    FibonacciFunctor f1{};
    FibonacciFunctor f2{};
    auto fail = check(f1(), 0);
    fail |= check(f2(), 0);
    fail |= check(f1(), 1);
    fail |= check(f1(), 1);
    fail |= check(f1(), 2);
    fail |= check(f2(), 1);
    fail |= check(f2(), 1);

    if (!fail)
        cout << "initial test OK\n";
}

void example_and_test_functor()
{
    cout << "example_and_test_functor:\n";

    test_functor();
    std::vector<int> v(fs.size());
    std::generate_n(v.begin(), v.size(), FibonacciFunctor{});
    print_and_check(v);
}

int main()
{
    example_and_test_iterator();
    example_and_test_functor();
}
