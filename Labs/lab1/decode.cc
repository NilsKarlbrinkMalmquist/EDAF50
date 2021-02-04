#include <iostream>
#include <fstream>
#include <string>
#include "coding.h"

using std::cout;
using std::cin;
using std::string;

int main(){
  std::ifstream readFile;
  std::ofstream writeFile;

  string readFileName;
  cout <<"Enter filename: ";
  cin >> readFileName;

  readFile.open(readFileName + ".enc");
  writeFile.open(readFileName + ".dec");

  char c;
  readFile.get(c);
  while(!readFile.eof()){
    writeFile.put(decode(c));
    readFile.get(c);
  }

  readFile.close();
  writeFile.close();

  return 0;
}
