#include "person.h"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

//Från facit:
/*bool operator<(const Person& p1, const Person& p2) {
	return p1.get_name() < p2.get_name() ||
		   (p1.get_name() == p2.get_name() && p1.get_phone() < p2.get_phone());
}*/

/*
 * Collect some persons in a phone book (a vector), sort
 * the phone book, print it.
 */
int main() {
	vector<Person> phonebook;
	phonebook.push_back(Person("Petra", "046-12 13 14"));
	phonebook.push_back(Person("Anders", "040-96 97 98"));
	phonebook.push_back(Person("Bosse", "046-15 16 17"));
	phonebook.push_back(Person("Anna", "040-96 97 98"));
	phonebook.push_back(Person("Anders", "046-18 19 20"));

	string name = phonebook[0].get_name();
	
	cout << "Unsorted:" << endl;
	copy(phonebook.begin(), phonebook.end(), 
		 ostream_iterator<Person>(cout, "\n"));
	cout << endl;
	
	sort(phonebook.begin(), phonebook.end(), [] (const Person p1, const Person p2){
		return p1.get_name() < p2.get_name();
	});
	
	cout << "Sorted:" << endl;
	copy(phonebook.begin(), phonebook.end(), 
		 ostream_iterator<Person>(cout, "\n"));
}
