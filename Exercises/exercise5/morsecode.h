/*
 * MorseCode: translates letters a-z to/from Morse code. The code
 * definitions are in the file morse.def.
 */
#ifndef MORSECODE_H
#define MORSECODE_H

#include<iostream>
#include <string>
#include <vector>
#include <utility>

class MorseCode {
public:
	MorseCode();
	std::string encode(const std::string& text) const;
	std::string decode(const std::string& code) const;
private:
	std::vector<std::pair<char, std::string>> pairs;
};

#endif
