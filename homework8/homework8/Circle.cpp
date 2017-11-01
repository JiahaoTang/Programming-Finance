#include <iostream>
#include "Circle.h"
using namespace std;

Circle::Circle(int xValue, int yValue, double radiusValue)
	:TwoDimensionalShape(xValue, yValue) {
	setRadius(radiusValue);
}

void Circle::setRadius(double radiusValue) {
	radius = radiusValue;
}

double Circle::getRadius() {
	return radius;
}

double Circle::getArea() {
	return 3.1415 * pow(getRadius(), 2.0);
}

void Circle::print(){
	cout << "The circle with radius " << getRadius() << "that is located at(" << Shape::getX() << ", " << Shape::getY() << ") has: " << endl;
	cout << "An area of " << getArea() << endl;
	cout << endl;
}