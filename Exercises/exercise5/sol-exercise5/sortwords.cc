#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

ostream& operator<<(ostream& os, const vector<string>& v) {
	for (const string& s : v) {
		os << s << " ";
	}
	return os;
}

int main() {
	vector<string> v = {"Mary", "had", "a", "little", "lamb", "and", "some",
		"olives", "on", "the", "side"};
	
	// print the words: Mary had a little lamb and some olives on the side
	cout << v << endl;
	
	// sort in alphabetical order: Mary a and had lamb little olives on side some the
	sort(v.begin(), v.end());
	cout << v << endl;
	
	// in reverse order:the some side on olives little lamb had and a Mary
	sort(v.begin(), v.end(),
		 [](const string& s1, const string& s2) { return s1 > s2; });
	cout << v << endl;
	
	// by ascending length: a on the and had Mary lamb side some olives little
	sort(v.begin(), v.end(),
		 [](const string& s1, const string& s2) { return s1.length() < s2.length(); });
	cout << v << endl;
	
	// sort in alphabetical order again, print three-letter words: and had the
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(),
			 [](const string& s) { if (s.length() == 3) { cout << s << " "; }});
	cout << endl;

    // For the output, an alternative to for_each, an if-statement and cout << s is: 
    // use copy_if and an ostream_iterator: same output as above
    std::copy_if(v.begin(), v.end(), std::ostream_iterator<string>(cout, " "), 
                [](const string& s) {return s.length() == 3;}) ;
    cout << endl;

	
	// remove words with <= three letters: Mary lamb little olives side some
	auto it = remove_if(v.begin(), v.end(),
						[](const string& s) { return s.length() <= 3; });
	v.erase(it, v.end());
	cout << v << endl;
}
