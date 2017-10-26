#include "vector2d.h"
#include <cmath>
#include <math.h>

v2d::v2d(double a, double b) {

	this->x = a;
	this->y = b;

}

v2d::v2d(const v2d & v) {

	this->x = v.x;
	this->y = v.y;

}

v2d::~v2d() {

}


v2d & v2d::operator=(const v2d &v) {

	this->x = v.x;
	this->y = v.y;

	return *this;
}

v2d & v2d::operator+(const v2d &v) {

	this->x = x + v.x;
	this->y = y + v.y;

	return *this;
}

double v2d::operator*(const v2d &v) {

	double output = x * v.x + y * v.y;

	return output;
}

v2d & v2d::operator*(double k) {

	this->x = k * x;
	this->y = k * y;


	return *this;
}

double v2d::length() {

	double output = sqrt(x*x + y*y);

	return output;
}
