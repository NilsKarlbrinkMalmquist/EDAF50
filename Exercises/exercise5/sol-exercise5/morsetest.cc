#include "morsecode.h"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


int main() {
	MorseCode mc;
	string text = "a man, a plan, a canal - panama";
    string codetext = mc.encode(text);
	cout << codetext << endl;
	cout << mc.decode(codetext) << endl;
	string code = ".... . .-.. .-.. --- .-- --- .-. .-.. -..";
	cout << mc.decode(code) << endl;
}
