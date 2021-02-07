#include <iostream>

using std::cout;

int main(){
  int i = 1;
  int *p = &i;
  *p = 2;
  cout <<"i = " <<i <<". p = " <<*p <<std::endl;

  return 0;
}
