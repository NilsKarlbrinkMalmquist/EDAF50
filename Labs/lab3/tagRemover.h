#ifndef TAGREMOVER_H
#define TAGREMOVER_H
#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::ostream;
using std::istream;

class tagRemover{
public:
  tagRemover(istream& in);
  tagRemover(string input);
  void print(ostream& os);
  string getResult() const;
private:
  string text;
  void removeTags();
  void translateHtmlChars();
};
#endif
