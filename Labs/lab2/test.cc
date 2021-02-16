#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::cin;

/*int main(){
  vector<string> v = {"Hej", "jag", "gillar", "bajskorvar"};
  cout << v.size() <<endl;
  for (const auto& w : v) {
    cout << w <<" ";
  }
  cout <<endl;
}*/

/*
void getTrigrams(std::vector<string> &trigrams, const string &word){
int nbrTrigrams = word.length()-2;
  for(int i = 0; i < nbrTrigrams; i++){
    trigrams.push_back(word.substr(i, 3));
  }
  std::sort(trigrams.begin(), trigrams.end());
}


int main(){

  string word = "handbag";
  std::transform(word.begin(), word.end(), word.begin(),[](unsigned char c){ return std::tolower(c); });

  cout << word <<": ";
  vector<string> trigrams;
  getTrigrams(trigrams, word);
  for (const auto& w : trigrams) {
    cout << w <<" ";
  }
  return 0;
}*/

/*int main(){
  std::unordered_set<string> set = { "handbag", "summer", "handbook" };
  string word = "word";
  set.insert(word);

  string word2 = "word";
  if(set.count(word2)){
    cout <<"Ordet finns \n";
  }
  else{
    cout <<"Ordet finns inte \n";
  }
}*/



/*int main(){
  std::unordered_set<string> set;
  std::ifstream readFile("dicTest.txt");
  string word;

  while(std::getline(readFile, word)){
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		set.insert(word);
	}
	readFile.close();

  string word2;
  while (cin >> word2) {
    if(set.count(word2)){
      cout <<"Ordet finns \n";
    }
    else{
      cout <<"Ordet finns inte \n";
    }
  }
}*/




int main(){
  double a = 7;
  double b = 2;
  double c = a/b;
  cout <<c <<endl;
}
