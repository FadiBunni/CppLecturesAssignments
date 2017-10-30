#ifndef shapes_h
#define shapes_h

#include <stdio.h>

class Shape {

public:
	Shape(void);
	virtual double area(void) = 0;
	virtual double perimeter(void) = 0;
	virtual double height(void) = 0;
	virtual double width(void) = 0;
	virtual void rotate(void) = 0;
};

class Rectangle : public Shape {
	
public:
	Rectangle(double x, double y);
	
	double x;
	double y;

	double area(void);
	double perimeter(void);
	double height(void);
	double width(void);
	void rotate(void);

};

class Square : public Shape {

public:
	Square(double x);
	double x;

	double area(void);
	double perimeter(void);
	double height(void);
	double width(void);
	void rotate(void);
};

class Circle : public Shape {

public:
	Circle(double r);
	double r;

	double area(void);
	double perimeter(void);
	double height(void);
	double width(void);
	void rotate(void);
};




#endif // !shapes.h
