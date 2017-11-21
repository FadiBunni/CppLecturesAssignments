#include "fibtree.h"
#include <iostream>
#include <algorithm>

using namespace std;

Fibtree::Fibtree(unsigned int n)
{

	leftExpr = nullptr;
	rightExpr = nullptr;
	if (n == 0 || n == 1) {
		value = 1;
	}
	else {
		leftExpr = new Fibtree(n - 1);
		rightExpr = new Fibtree(n - 2);
		value = leftExpr->value + rightExpr->value;

	}
}

Fibtree::~Fibtree()
{
	if (leftExpr != nullptr) {
		delete leftExpr;
	}
	if (rightExpr != nullptr) {
		delete rightExpr;
	}
}

int Fibtree::size()
{
	if (leftExpr == nullptr && rightExpr == nullptr) {
		return 1;
	}
	else {
		// The size of a the node is 1
		//plus the number of nodes in the sub-trees
		return 1 + leftExpr->size() + rightExpr->size();
	}
}

int Fibtree::height()
{
	if (leftExpr == nullptr && rightExpr == nullptr) {
		return 1;
	}
	else {
		// The height of a compound expression is 1
		// plus the maximum height of its sub-trees
		return 1 + max(leftExpr->height(), rightExpr->height());
	}
}

int Fibtree::leaves()
{
	// The size of a constant is 1
	if (leftExpr == nullptr && rightExpr == nullptr) {
		return 1;
	}
	else {
		// The number of leaves of a compound expression is
		//the number of leaves in the sub-trees
		return leftExpr->leaves() + rightExpr->leaves();
	}
}

void Fibtree::traverse_pre()
{
	cout << value << " ";
	if (leftExpr == nullptr && rightExpr == nullptr) return;
	else {
		leftExpr->traverse_pre();
		rightExpr->traverse_pre();
	}
}