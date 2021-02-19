#include <iostream>
#include <string>
#include <vector>
#include "primeFinder.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(){
    primeFinder p;
    vector<int> primes = p.getPrimes(200);
    long biggestPrime = p.getBiggestPrime(100000);
    cout <<"The primes in the intervall are: ";
    for(auto c : primes){
      cout <<c <<" ";
    }
    cout <<endl << "The biggest prime is: " <<biggestPrime <<endl;
  return 0;
}
