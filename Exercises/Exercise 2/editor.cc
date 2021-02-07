#include "editor.h"

#include <string>

using std::string;

string::size_type Editor::find_left_par(string::size_type pos) const {
	char rightPar = text[pos];
	char leftPar;
	switch (rightPar){
		case ')' : leftPar = '('; break;
		case ']' : leftPar = '['; break;
		case '}' : leftPar = '{'; break;
		default : return string::npos;
	}
	int level = 0;
	bool found = false;
	char ch;
	int i = pos - 1;
	while(i >= 0 && !found){
		ch = text[i];
		if(ch == leftPar && level == 0){
			found = true;
		}
		else{
			if(ch == rightPar){
				level++;
			}
			else if(ch == leftPar){
				level--;
			}
			i--;
		}
	}
	return i;
}
