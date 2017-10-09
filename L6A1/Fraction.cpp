#include "Fraction.h"
#include <iostream>

Fraction::Fraction()
{
}

void Fraction::add(Fraction f)
{
	numerator = (numerator * f.getDenom()) +( f.getNum()*denominator);
	denominator = denominator * f.getDenom();
}

void Fraction::mult(Fraction f)
{
	numerator = numerator * f.getNum();
	denominator = denominator *f.getDenom();
}

void Fraction::div(Fraction f)
{
	numerator = numerator * f.getDenom();
	denominator = denominator * f.getNum();
}

int Fraction::getNum() {
	return numerator;
}

int Fraction::getDenom()
{
	return denominator;
}

void Fraction::setNum(int a) {
	numerator = a;
}

void Fraction::setDenom(int b) {
	denominator = b;
}

void Fraction::reducefraction() {
	for (int i = denominator*numerator; i > 1; i--) {
		if ((denominator %i == 0) && (numerator % i == 0)) {
			denominator /= i;
			numerator /= i;
		}
	}
}

void Fraction::display(void)
{
	reducefraction();
	cout << numerator << " / " << denominator << endl;
}
