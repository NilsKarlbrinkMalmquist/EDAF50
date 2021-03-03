#include "crypto.h"

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	cout << "Key:       ";
	unsigned key;
	cin >> key;
	cin.ignore();
	cout << "Text:      ";
	string s;
	getline(cin, s);
	string t = Crypto::encrypt(s, key);
	cout << "Encrypted: " << t << endl;
	cout << "Decrypted: " << Crypto::decrypt(t, key) << endl;
}
