#include "morsecode_c.h"

#include <fstream>
#include <sstream>

using std::string;

MorseCode::MorseCode() {
    std::ifstream in("morse.def");
	char ch;
	string code;
	while (in >> ch >> code) {
		table[ch - 'a'] = code;
	}
}

string MorseCode::encode(const string& text) const {
	string result;
	for (char ch : text) {
		if (ch >= 'a' && ch <= 'z') {
			result += table[ch - 'a'] + " ";
		}
	}
	return result;
}

string MorseCode::decode(const string& code) const {
    std::istringstream iss(code);
	string s;
	string result;
	while (iss >> s) {
		int i = 0;
		while (i != 26 && table[i] != s) {
			++i;
		}
		result += (i != 26) ? static_cast<char>(i + 'a') : '?';
	}
	return result;
}
