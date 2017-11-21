#ifndef __Fibtree__
#define __Fibtree__

class Fibtree {
public:
	Fibtree(unsigned int n);
	~Fibtree();

	int size();
	int height();
	int leaves();

	void traverse_pre();

private:
	int value;                 // if the node is a leaf, this member contains the value of the node
	Fibtree *leftExpr;     // pointer to the left sub-expression (sub-tree)
	Fibtree *rightExpr;    // pointer to the right sub-expression (sub-tree)
};

#endif;