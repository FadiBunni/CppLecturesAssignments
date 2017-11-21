#include "doubly-linked.h"
#include <iostream>

using namespace std;


Node* current;

List::List() {
	first = nullptr;
}

List::~List() {}


void List::insert(int n) {
	Node* newNode = new Node;
	newNode->val = n;

	if (first == nullptr) {

		first = newNode;

	}
	else {

		Node* temp = first;

		while (temp->next != nullptr) {

			temp = temp->next;

		}

		temp->next = newNode;
		newNode->prev = temp;

	}

}

void List::reverse() {

	Node* rev1 = new Node;
	Node* rev2 = new Node;

	rev1 = first;
	rev2 = rev1->next;
	rev1->next = nullptr;
	rev1->prev = rev2;

	while (rev2 != nullptr) {
		rev2->prev = rev2->next;
		rev2->next = rev1;
		rev1 = rev2;
		rev2 = rev2->prev;
	}
	first = rev1;
}


void List::print() {
	Node* x = new Node;

	if (first == nullptr) {
		exit(0);
	}
	x = first;
	while (x != nullptr) {
		cout << x->val << " ";
		x = x->next;
	}
	cout << endl;
}
