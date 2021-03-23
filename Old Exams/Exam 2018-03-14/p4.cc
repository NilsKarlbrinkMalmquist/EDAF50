#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void create_reverse(){
    std::ifstream readFile("words.txt");
    std::ofstream writeFile("backwords.txt");
    string word;
    vector<string> backwords;

    while(readFile >> word){
        std::transform(word.begin(), word.end(), word.begin(),
        [](unsigned char c){ return std::tolower(c); });
        reverse(word.begin(), word.end());
        backwords.push_back(word);
    }
    sort(backwords.begin(), backwords.end());
    std::unique(backwords.begin(), backwords.end());

    for(auto x : backwords){
        reverse(x.begin(), x.end());
        writeFile << x <<endl;
    }
    readFile.close();
    writeFile.close();
}



int main(){
    create_reverse();
    return 0;
}