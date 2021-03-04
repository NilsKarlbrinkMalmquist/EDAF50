#include<iostream>

#include "rational.h"
#include <stdexcept>



Rational::Rational() : numerator(0), denominator(1) {simplify();}

Rational::Rational(const int& num) 
    : numerator(num), denominator(1) {simplify();}

Rational::Rational(const int& num, const int& denom) 
    : numerator(num), denominator(denom) {simplify();}

Rational::Rational(const Rational& other) 
    : numerator(other.numerator), denominator(other.denominator) {simplify();}

Rational& Rational::operator=(const Rational& other){
    numerator = other.numerator;
    denominator = other.denominator;
    simplify();
    return *this;
}

Rational& Rational::operator=(const int& i){
    numerator = i;
    denominator = i;
    simplify();
    return *this;
}

Rational& Rational::operator+=(const Rational& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    simplify();
    return *this;

}
Rational Rational::operator+(const Rational& other) const {    
    return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

std::ostream& operator<<(std::ostream& stream, const Rational& other){
    stream << "(" <<other.numerator << "/" << other.denominator <<")";
    return stream;
}

void Rational::simplify(){
    int divisor = gcd(numerator, denominator); 
     numerator /= divisor;
     denominator /= divisor;
}

int Rational::gcd(int num, int denom){
    while(denom != 0){
        int temp = denom;
        denom = num % denom;
        num = temp;
    }
    return num;
}
