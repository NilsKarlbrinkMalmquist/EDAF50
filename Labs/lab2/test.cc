#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

/*int main(){
  vector<string> v = {"Hej", "jag", "gillar", "bajskorvar"};
  cout << v.size() <<endl;
  for (const auto& w : v) {
    cout << w <<" ";
  }
  cout <<endl;
}*/

void getTrigrams(std::vector<string> &trigrams, const string &word){
int nbrTrigrams = word.length()-2;
  for(int i = 0; i < nbrTrigrams; i++){
    trigrams.push_back(word.substr(i, 3));
  }
  std::sort(trigrams.begin(), trigrams.end());
}


int main(){

  string word = "AIDS";
  std::transform(word.begin(), word.end(), word.begin(),[](unsigned char c){ return std::tolower(c); });

  cout << word <<": ";
  vector<string> trigrams;
  getTrigrams(trigrams, word);
  for (const auto& w : trigrams) {
    cout << w <<" ";
  }
  cout <<endl;



  return 0;




}
