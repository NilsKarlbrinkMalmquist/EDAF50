#include <iostream>
#include <vector>
#include <string>
#include "primeFinder.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

vector<int> primeFinder::getPrimes(int n){
  calculatePrimes(n);
  vector<int> primeVector;
  int pos = 0;
  for (char c: primes) {
    if(c == 'P'){
      primeVector.push_back(pos);
    }
    pos++;
  }
  return primeVector;
}

long primeFinder::getBiggestPrime(int n) {
  calculatePrimes(n);
  long biggest = primes.find_last_of('P');
  return biggest;
}

void primeFinder::calculatePrimes(int n){
  primes = "CC" + string(n-1, 'P');

  for(int a = 2; a <= n; a++){
    if(primes[a] == 'P'){
      for(int j =a+1; j <= n; j++){
        if(j % a == 0){
          primes[j] = 'C';
        }
      }
    }
  }
}
