//Nils Karlbrink Malmquist, 19971017-2959, ni4838ma-s
#include "fib.h"

FibonacciIterator& FibonacciIterator::operator++(){
	if(fib == 0 && old_fib == 0){
        fib = 1;
        old_fib = 0;
    }
    else{
        int temp = fib;
        fib = fib + old_fib;
        old_fib = temp;
    }
    return *this;
}

FibonacciIterator& FibonacciIterator::operator++(int){
    ++*this;
    return *this;
}

/*FibonacciIterator& FibonacciIterator::operator=(const FibonacciIterator& other){
    fib = other.fib;
    old_fib = other.old_fib;
    return *this;
}*/


int& FibonacciIterator::operator*(){
    return fib;
}

bool FibonacciIterator::operator!=(const FibonacciIterator& other) const {
    if(other.fib != fib) return true;
    return false;
}

bool FibonacciIterator::operator==(const FibonacciIterator& other) const {
    if(other.fib == fib) return true;
    return false;
}