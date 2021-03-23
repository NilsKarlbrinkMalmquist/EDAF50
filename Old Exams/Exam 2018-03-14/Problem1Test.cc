#include <iostream>
#include <vector>
#include <functional>
#include "Problem1.h"

int main(){
  std::vector<std::function<int(int,int)>> fs; // the functions

  fs.push_back(std::plus<int>{});
  fs.push_back([](int x, int y) {return 2*x-y;});
  fs.push_back(std::divides<int>{});

  std::vector<int> rs(fs.size()); // where the results will be stored

  apply_all(begin(fs), end(fs), begin(rs), 10, 2);
  
  for(auto r : rs) std::cout << r << " ";
  std::cout << std::endl;
}
