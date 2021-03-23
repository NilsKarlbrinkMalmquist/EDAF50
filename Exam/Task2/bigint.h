//Nils Karlbrink Malmquist, 19971017-2959, ni4838ma-s

#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <fstream>

#include <sstream>



class BigInteger {
    friend std::ostream& operator<<(std::ostream& stream, const BigInteger& other);
    friend std::istream& operator>>(std::istream& stream, const BigInteger& other);
public:
    BigInteger();
    BigInteger(std::string nbr){
        int digits = std::stoi(nbr);
        inserEachDigit(digits);
    }
    BigInteger(int nbr){inserEachDigit(nbr);}
    void inserEachDigit(int x){
        if(x >= 10){
            inserEachDigit(x / 10);
        }
        int digit = x % 10;
        bigIntVec.push_back(digit);
    }
    BigInteger& operator +=(const BigInteger& other){
        if(bigIntVec.size() >= other.bigIntVec.size()){
            std::transform(bigIntVec.begin(), bigIntVec.end(), other.bigIntVec.begin(),
               other.bigIntVec.end(), std::plus<int>());
            //std::copy(longest.begin()+shortest.length(), longest.end(), it);

        }
        return *this;
    }

    bool operator==(const BigInteger& other) const {
        return bigIntVec == other.bigIntVec;
        //return equal(bigIntVec.begin(), bigIntVec.end(), other.bigIntVec.begin());
    }
    bool operator!=(const BigInteger& other) const{
        //return !(other==*this);
        return bigIntVec != other.bigIntVec;
    }
private:
    std::vector<int> bigIntVec;
};

std::ostream& operator<<(std::ostream& stream, const BigInteger& other){
    for(auto& x: other.bigIntVec){
        stream <<x;
    }
    return stream;
}

std::istream& operator>>(std::istream& stream, BigInteger& other){
    std::string line;
    std::getline(stream, line);
    int digits = stoi(line);
    other.inserEachDigit(digits);
    return stream;
}


#endif

//operator <<, operator !=, operator ==, operator >>, operator +=
//operator+