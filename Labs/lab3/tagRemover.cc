#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <regex>
#include "tagRemover.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ostream;

tagRemover::tagRemover(istream& in){
  string line;
	while(getline(in, line)){
		text += line + "\n";
	}
  removeTags();
  translateHtmlChars();
}

tagRemover::tagRemover(string input){
  text = input;
  removeTags();
  translateHtmlChars();
}

void tagRemover::print(ostream& os){
  os <<text;
}

string tagRemover::getResult() const{
  return text;
}


//private methods:

void tagRemover::removeTags(){
  while (text.find("<") != std::string::npos){
    auto startpos = text.find("<");
    auto endpos = text.find(">") + 1;

    if (endpos != std::string::npos){
      text.erase(startpos, endpos - startpos);
    }
  }
}

void tagRemover::translateHtmlChars(){
  std::regex tag("&lt;");
  text = regex_replace(text, tag, "<");
  tag = {"&gt;"};
  text = regex_replace(text, tag, ">");
  tag = {"&nbsp;"};
  text = regex_replace(text, tag, " ");
  tag = {"&amp;"};
  text = regex_replace(text, tag, "&");
}
