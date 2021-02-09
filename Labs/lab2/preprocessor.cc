#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void getTrigrams(std::vector<string> &trigrams, const string &word){
int nbrTrigrams = word.length()-2;
  for(int i = 0; i < nbrTrigrams; i++){
    trigrams.push_back(word.substr(i, 3));
  }
  std::sort(trigrams.begin(), trigrams.end());
}

int main(){
  std::ifstream readFile("words");
  std::ofstream writeFile;

  writeFile.open("words.txt");
  string word;
  while(std::getline(readFile, word)){
    std::transform(word.begin(), word.end(), word.begin(),[](unsigned char c){ return std::tolower(c); });

    vector<string> trigrams;
    getTrigrams(trigrams, word);

    writeFile << word << " " << trigrams.size() << " ";
    for (const auto& w : trigrams) {
      writeFile << w <<" ";
    }
    writeFile <<endl;
  }

  readFile.close();
  writeFile.close();

  return 0;




}
