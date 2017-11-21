#include <iostream>

#include "fibtree.h"

using namespace std;

int main() {
	int n;
	cin >> n;

	Fibtree * newFibTree = new Fibtree(n);
	cout << "Call tree in pre-order: ";
	newFibTree->traverse_pre();
	cout << endl;
	cout << "Call tree size: " << newFibTree->size() << endl;
	cout << "Call tree depth: " << newFibTree->height() << endl;
	cout << "Call tree leafs: " << newFibTree->leaves() << endl;

	return 0;
}