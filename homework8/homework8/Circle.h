#pragma once
#include "TwoDimensionalShape.h"

class Circle : public TwoDimensionalShape {
public:
	Circle(int = 0, int = 0, double = 0);
	void setRadius(double);
	double getRadius();
	double getArea();
	void print();
private:
	double radius;
};