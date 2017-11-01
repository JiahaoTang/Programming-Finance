#pragma once
#include "TwoDimensionalShape.h"

class Triangle : public TwoDimensionalShape {
public:
	Triangle(int = 0, int = 0, double = 0, double = 0);
	void setLength(double);
	void setWidth(double);
	double getLength();
	double getWidth();
	double getArea();
	void print();
private:
	double length;
	double width;
};