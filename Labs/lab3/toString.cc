#include <iostream>
#include <sstream>
#include <string>
#include "date.h"

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::istringstream;

template<typename T>
string toString(T& obj){
  ostringstream print;
  print << obj;
  return print.str();
}

template <typename T>
T string_cast(const string& s){
  istringstream cast(s);
  T t;
  cast >> t;
  if(cast.fail() || !cast.eof()){
    throw std::invalid_argument("String cast failed. \n");
  }
  return t;
}

void test_string_cast(){
  try {
    int i = string_cast<int>("123abc");
    double d = string_cast<double>("12.34");
    Date date = string_cast<Date>("2015-01-10");
    cout << "Int-test passed: " <<i <<endl <<"Double test passed: " <<d <<endl <<"Date test passed: " <<date <<endl;
  } catch (std::invalid_argument& e) {
    cout << "Error: " << e.what() << endl;
  }
}

void intToString(){
  int i = 123;
	string test = toString(i);
	string correct = "123";
	if (test == correct){
		cout << "testIntToString passed" << endl;
	}
  else {
		cout << "testIntToString failed" << endl;
	}
}

void doubleToString(){
  double i = 12.34;
	string test = toString(i);
	string correct = "12.34";
	if (test == correct){
		cout << "testDoubleToString passed" << endl;
	}
  else {
		cout << "testDoubleToString failed" << endl;
	}
}

void dateToString(){
  Date d(2015, 01, 10);
	string test = toString(d);
	string correct = "2015-01-10";
	if (test == correct){
		cout << "testDateToString passed" << endl;
	}
  else {
		cout << "testDateToString failed" << endl;
	}
}


int main(){
  intToString();
  doubleToString();
  dateToString();
  cout <<endl;
  test_string_cast();

  return 0;
}
