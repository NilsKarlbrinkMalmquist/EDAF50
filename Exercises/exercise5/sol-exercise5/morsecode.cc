#include "morsecode.h"

#define INFO   //remove this to suppress debug output

#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#ifdef INFO
#include <iostream>
#endif

using std::string;

MorseCode::MorseCode() {
    std::ifstream in("morse.def");
    if(!in) {throw std::runtime_error("failed to open morse.def");}
	char ch;
	while (in >> ch) {
	    string code;
        in >> code;
		table[ch] = code;
	}
}

string MorseCode::encode(const string& text) const {
	string result;
	for (char ch : text) {
		try {
			result += table.at(ch) + " ";
		} catch(std::out_of_range&){ // at throws if the key is not in the map
#ifdef INFO
            std::cout << "encode: ignoring " << ch << '\n';
#endif
        }
	}
	return result;
}

string MorseCode::decode(const string& code) const {
    std::istringstream iss(code);
	string s;
	string result;
	while (iss >> s) {
       // The reverse lookup can be done either using a hand-written loop
       // or std::find_if. Prefer the standard algorithms when possible.
#if 0
        for(const auto& p : table) {
            if(p.second == s){ result += p.first; break; }
        }
#else
        auto it = std::find_if(table.begin(), table.end(), 
                               [&](const std::pair<char,std::string>& p){
                                   return p.second == s;});
        if(it != table.end()){result += it->first;}
#endif
	}
	return result;
}
