#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H
#include <iostream>
#include <string>
#include <vector>

using std::string;

class primeFinder{
public:
  //primeFinder();
  std::vector<int> getPrimes(int n);
  long getBiggestPrime(int n);
private:
  void calculatePrimes(int n);
  string primes;
};
#endif
