/*
 * MorseCode: translates letters a-z to/from Morse code. The code
 * definitions are in the file morse.def.
 *
 * This version uses a built-in array of strings, and uses the index
 * of the array - 'a' to map letters to code strings.
 *
 * Note that while it may be slightly more memory-efficient, 
 * the code is much more complicated and brittle.
 *
 */
#ifndef MORSECODE_H
#define MORSECODE_H

#include <string>

class MorseCode {
public:
	MorseCode();
	std::string encode(const std::string& text) const;
	std::string decode(const std::string& code) const;
private:
	std::string table[26];
};

#endif
