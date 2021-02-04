#include <iostream>
#include "list.h"

using std::cout;
using std::endl;

List::List() {
	first = nullptr;
}

List::~List() {
	Node *p = first;
	Node *next;
	while(p != nullptr){
		next = p->next;
		delete p;
		p = next;
	}
}

bool List::exists(int d) const {
	Node *p = first;
	while(p != nullptr){
		if(p->value == d){
			return true;
		}
		p = p->next;
	}
	return false;
}

int List::size() const {
	int size = 0;
	Node *p = first;
	while(p != nullptr){
		size++;
		p = p->next;
	}
	return size;
}

bool List::empty() const {
	if(first == nullptr){
		return true;
	}
	return false;
}

void List::insertFirst(int d) {
	Node *node = new Node(d, first);
	first = node;
}

/*private void removeNode(Node *p, Node *pre){
	if(p == first){
		first = p->next;
	}
	else{
		pre->next = p->next;
	}
	delete p
}*/

void List::remove(int d, DeleteFlag df) {
	Node *p = first;
	Node *pre = nullptr;
	bool del = false;
	while(p != nullptr){
		if(df == DeleteFlag::LESS){
			if(p->value < d){
				del = true;

				//removeNode(p, pre);
				//return;
			}
		}
		else if(df == DeleteFlag::EQUAL){
			if(p->value == d){
				del = true;

				//removeNode(p, pre);
				//return;
			}
		}
		else if(df == DeleteFlag::GREATER){
			if (p->value > d) {
				del =true;

				//removeNode(p, pre);
				//return;
			}
		}
		if(del){
			if(p == first){
				first = p->next;
			}
			else{
				pre->next = p->next;
			}
			delete p;
			return;
		}
		pre = p;
		p = p->next;
	}
}

void List::print() const {
	Node *p = first;
	cout <<"The contents of this list: \n";
	while (p != nullptr) {
		cout <<p->value <<endl;
		p = p->next;
	}
	cout <<"Size: " <<size() <<endl;
}
