#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational{
    friend std::ostream& operator<<(std::ostream&, const Rational&);
private:
    int numerator;
    int denominator;
    void simplify();
    int gcd(int, int);
public:
    Rational();
    Rational(const int& num);
    Rational(const int& num, const int& denom);
    Rational(const Rational& other);
    Rational& operator=(const Rational&);
    Rational& operator=(const int& i);
    Rational& operator+=(const Rational& other);
    Rational operator+(const Rational& other) const;
};

std::ostream& operator<<(std::ostream& stream, const Rational& other);

#endif 