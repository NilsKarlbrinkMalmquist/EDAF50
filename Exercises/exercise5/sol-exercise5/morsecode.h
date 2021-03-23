/*
 * MorseCode: translates letters a-z to/from Morse code. The code
 * definitions are in the file morse.def.
 *
 * This version uses the standard library classes string and map.
 * For a low-level, C-style solution see morsecode_c
 */
#ifndef MORSECODE_H
#define MORSECODE_H

#include <string>
#include <map>


class MorseCode {
public:
	MorseCode();
	std::string encode(const std::string& text) const;
	std::string decode(const std::string& code) const;
private:
    std::map<char, std::string> table;
};

#endif
