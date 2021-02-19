#include <iostream>
#include <ctime>  // time and localtime
#include <iomanip> // for setw and setfill
#include <string>
#include <algorithm>
#include <ios>
#include <sstream>
#include "date.h"

using std::ostream;
using std::istream;
using std::setw;
using std::setfill;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ios_base;
using std::stoi;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	if (day < daysPerMonth[month-1]) {
		day++;
	}
	else if (month < 12){
		day = 1;
		month++;
	}
	else{
		day = 1;
		month = 1;
		year++;
	}
}

ostream& operator<<(ostream& os, Date& d){
	os << setw(4) << setfill('0') << d.getYear() << '-';
	os << setw(2) << setfill('0') << d.getMonth() << '-';
	os << setw(2) << setfill('0') << d.getDay();
	return os;
}

istream& operator>>(istream& is, Date& d){
	string line;
	std::getline(is, line);
	int n = std::count(line.begin(), line.end(), '-');
	if(n == 2){
		string year = line.substr(0, 4);
		string month = line.substr(5, 2);
		string day = line.substr(8);
		int digit;

		digit = stoi(year);
		if(!(digit >=1000 && digit <= 9999)){
			is.setstate(ios_base::failbit);
			//return is;
		}
		d.year = digit;

		digit = stoi(month);
		if(!(digit >= 1 && digit <= 12)){
			is.setstate(ios_base::failbit);
			//return is;
		}
		d.month = digit;

		digit = stoi(day);
		if(!(digit >= 1 && digit <= Date::daysPerMonth[d.getMonth()-1])){
			is.setstate(ios_base::failbit);
			//return is;
		}
		d.day = digit;
	}
	else{
		cout << "Wrong format, expected XXXX-XX-XX" << endl;
		is.setstate(ios_base::failbit);
		//return is;
	}
	return is;
}
