#include "morsecode.h"

#include <fstream>
#include <sstream>
#include <utility>
#include <algorithm>


using std::string;
using std::vector;

MorseCode::MorseCode() {
	std::ifstream readFile("morse.def");
	string line;
	while(std::getline(readFile, line)){
		char letter;
		string morse;
		std::stringstream ss(line);
		ss >> letter;
		ss >> morse;
		pairs.push_back(std::make_pair(letter, morse));
	}
}

string MorseCode::encode(const string& words) const {
	string encoded;

	for(char c : words){
		auto it = std::find_if(pairs.begin(), pairs.end(), [c] (const std::pair<char, string> p){
			return p.first == c;
		});
		if(it != pairs.end()){
			encoded.append(it->second + " ");
		}
	}

	return encoded;
}

string MorseCode::decode(const string& morse) const {
	std::istringstream ss(morse);
	string decoded;
	string code;
	while(ss >> code) {
		auto it = std::find_if(pairs.begin(), pairs.end(), [code] (const std::pair<char, string> p){
			return p.second == code;
		});
		if( it != pairs.end()){
			decoded.push_back(it->first);
		}
	}
	return decoded;
}
