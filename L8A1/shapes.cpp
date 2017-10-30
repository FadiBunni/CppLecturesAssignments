#define _USE_MATH_DEFINES
#include <math.h>
#include "shapes.h"

Shape::Shape() {}

Rectangle::Rectangle(double a, double b) {
	x = a;
	y = b;
}

Square::Square(double a) {
	x = a;

}

Circle::Circle(double R) {
	r = R;
}

double Square::area(void)
{
	return x*x;
}

double Square::perimeter(void)
{
	return 4 * x;
}

double Square::height(void)
{
	return x;
}

double Square::width(void)
{
	return x;
}

void Square::rotate(void)
{
	return;
}

double Circle::area(void)
{
	return M_PI*pow(r, 2.0);

}

double Circle::perimeter(void)
{
	return 2*r*M_PI;
}

double Circle::height(void)
{
	return 2*r;
}

double Circle::width(void)
{
	return 2*r;
}

void Circle::rotate(void)
{
	return;
}

double Rectangle::area() {
	return x*y;
}

double Rectangle::perimeter(void)
{
	return 2*x + 2*y;
}

double Rectangle::height(void)
{
	return x;
}

double Rectangle::width(void) {
	return y;
}

void Rectangle::rotate(void)
{
	int temp = 0;
	temp = x;
	x = y;
	y = temp;
}


