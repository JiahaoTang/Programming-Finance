#include <iostream>
#include "Sphere.h"
using namespace std;

/*Constructor.*/
Sphere::Sphere(int xValue, int yValue, int zValue, double radiusValue)
	:ThreeDimensionalShape(xValue, yValue, zValue) {
	setRadius(radiusValue);
}

/*Set the private variable radius of sphere.*/
void Sphere::setRadius(double radiusValue) {
	radius = radiusValue;
}

/*Get the private variable radius.*/
double Sphere::getRadius() {
	return radius;
}

/*Calculated the surface area of sphere.*/
double Sphere::getArea() {
	return 4 * 3.1415 * getRadius() * getRadius();
}

/*Calculated the volume of sphere.*/
double Sphere::getVolume() {
	return 4 * 3.1415 * getRadius() * getRadius() * getRadius() / 3;
}

/*Print out the result.*/
void Sphere::print() {
	cout << "The shpere with radius " << getRadius() << " that is located at(" << Shape::getX() << ", " << Shape::getY() << ", " << ThreeDimensionalShape::getZ() << ") has: " << endl;
	cout << "Surface area of " << getArea() << endl;
	cout << "Volume of " << getVolume() << endl;
	cout << endl;
}