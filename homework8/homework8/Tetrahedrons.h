#pragma once
#include "ThreeDimensionalShape.h"

class Tetrahedrons : public ThreeDimensionalShape {
public:
	Tetrahedrons(int = 0, int = 0, int = 0, double = 0);
	void setSideLength(double sideLength);
	double getSideLength();
	double getArea();
	double getVolume();
	void print();
private:
	double sideLength;
};