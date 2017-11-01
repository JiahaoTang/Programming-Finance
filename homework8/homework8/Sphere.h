#pragma once
#include "ThreeDimensionalShape.h"

class Sphere : public ThreeDimensionalShape {
public:
	Sphere(int = 0, int = 0, int = 0, double = 0);
	void setRadius(double);
	double getRadius();
	double getArea();
	double getVolume();
	void print();
private:
	double radius;
};