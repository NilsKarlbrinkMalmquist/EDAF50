#include <string>
#include <vector>
#include "word.h"

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t) : word(w), trigrams(t)  {}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
 	int nbrMatches = 0;
	for(auto &w: t){
		for(auto &tri : trigrams){
			if (w.compare(tri) == 0) {
				nbrMatches++;
				break;
			}
			else if(w.compare(tri) < 0){
				break;
			}
		}
	}
	return nbrMatches;
}
