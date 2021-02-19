#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "tagRemover.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void testTagRemover(){
  string test = "Sentence without HTML tags. Sentence with tags<yes it is>. Tags again<yesyes>. Special chars: &lt;&nbsp;&amp;&gt;";
  string correct = "Sentence without HTML tags. Sentence with tags. Tags again. Special chars: < &>";
  tagRemover tester(test);
  string result = tester.getResult();
  if(correct.compare(result) == 0){
    cout <<"Tag removal worked! \n";
  }
  else{
    cout <<"Tag removal did not work! \n";
  }
  tester.print(cout);
  cout <<endl;
}

void testHtmlFile(){
  std::ifstream readFile("test.html");
  cin.rdbuf(readFile.rdbuf());
  tagRemover testerHtml(cin);
  testerHtml.print(cout);
}

int main(){
  testTagRemover();
  testHtmlFile();
  return 0;
}
