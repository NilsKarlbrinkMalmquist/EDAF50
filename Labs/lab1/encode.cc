/*Note that you cannot use while (infile >> ch) to read all
characters in infile, since >> skips whitespace (why?).
Use infile.get(ch) instead. Output with outfile << ch should be ok,
but outfile.put(ch) looks more symmetric.*/

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
  cout << "Enter filename: ";
  cin >> readFileName;

  readFile.open(readFileName + ".txt");
  writeFile.open(readFileName + ".enc");

  char c;
  readFile.get(c);
  while(!readFile.eof()){
    writeFile.put(encode(c));
    readFile.get(c);
  }

  readFile.close();
  writeFile.close();

  return 0;
}
