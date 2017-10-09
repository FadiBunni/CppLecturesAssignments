#pragma once
#include <string>
using namespace std;

class Fraction {
public:
	// Class constructor
	Fraction();

	// Methods to update the fraction
	void add(Fraction F);
	void mult(Fraction F);
	void div(Fraction F);
	
	int getNum();
	int getDenom();
	void setDenom(int b);
	void setNum(int a);
	// Display method
	void display(void);

private:
	// Internal representation of a fraction as two integers
	void reducefraction();
	int numerator;
	int denominator;
};
