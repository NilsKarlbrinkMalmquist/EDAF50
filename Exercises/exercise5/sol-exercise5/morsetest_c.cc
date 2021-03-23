#include "morsecode_c.h"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


int main() {
	MorseCode mc;
	string text = "a man, a plan, a canal - panama";
	cout << mc.encode(text) << endl;
	string code = ".... . .-.. .-.. --- .-- --- .-. .-.. -..";
	cout << mc.decode(code) << endl;
}
