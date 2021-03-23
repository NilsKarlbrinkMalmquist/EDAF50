//Nils Karlbrink Malmquist, 19971017-2959, ni4838ma-s
#ifndef FIB_H
#define FIB_H

#include <iterator>

class FibonacciIterator : public std::iterator<std::forward_iterator_tag, bool> {
public:
    FibonacciIterator() : fib(0), old_fib(0) {}
    FibonacciIterator(const FibonacciIterator& a) : fib(a.fib), old_fib(a.old_fib ) {}
    FibonacciIterator& operator++();
    FibonacciIterator& operator++(int);
    //FibonacciIterator& operator=(const FibonacciIterator& other);
    int& operator*();
    bool operator!=(const FibonacciIterator& other) const;
    bool operator==(const FibonacciIterator& other) const;
private:
    int fib;
    int old_fib;
};

class FibonacciFunctor : FibonacciIterator {
public:
    FibonacciFunctor();
private:

};

#endif