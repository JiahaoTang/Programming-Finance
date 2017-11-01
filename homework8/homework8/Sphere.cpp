#include <iostream>
#include "Sphere.h"
using namespace std;

Sphere::Sphere(int xValue, int yValue, int zValue, double radiusValue)
	:ThreeDimensionalShape(xValue, yValue, zValue) {
	setRadius(radiusValue);
}

void Sphere::setRadius(double radiusValue) {
	radius = radiusValue;
}

double Sphere::getRadius() {
	return radius;
}

double Sphere::getArea() {
	return 4 * 3.1415 * getRadius() * getRadius();
}

double Sphere::getVolume() {
	return 4 * 3.1415 * getRadius() * getRadius() * getRadius() / 3;
}

void Sphere::print() {
	cout << "The shpere with radius " << getRadius() << " that is located at(" << Shape::getX() << ", " << Shape::getY() << ", " << ThreeDimensionalShape::getZ() << ") has: " << endl;
	cout << "Surface area of " << getArea() << endl;
	cout << "Volume of " << getVolume() << endl;
	cout << endl;
}