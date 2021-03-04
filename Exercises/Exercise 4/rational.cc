#include<iostream>

#include "rational.h"
#include <stdexcept>



Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(const int& num) 
    : numerator(num), denominator(1) {}

Rational::Rational(const int& num, const int& denom) 
    : numerator(num), denominator(denom) {}

/*Rational::Rational(const int& numerator, const int& denominator){
    this->numerator = numerator;
    this->denominator = denominator;
}*/

Rational::Rational(const Rational& other) 
    : numerator(other.numerator), denominator(other.denominator) {}

/*Rational& Rational::operator=(const Rational& other){

}*/

Rational& Rational::operator+=(const Rational& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    return *this;

}
Rational Rational::operator+(const Rational& other) const {    
    return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}



std::ostream& operator<<(std::ostream& stream, const Rational& other){
    stream << "(" <<other.numerator << "/" << other.denominator <<")";
    return stream;
}


