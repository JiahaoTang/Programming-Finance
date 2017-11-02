#include <iostream>
#include "Circle.h"
using namespace std;

/*Constructor.*/
Circle::Circle(int xValue, int yValue, double radiusValue)
	:TwoDimensionalShape(xValue, yValue) {
	setRadius(radiusValue);
}

/*Set the private variable radius of circle.*/
void Circle::setRadius(double radiusValue) {
	radius = radiusValue;
}

/*Get the private variable radius.*/
double Circle::getRadius() {
	return radius;
}

/*Calculated the area of circle.*/
double Circle::getArea() {
	return 3.1415 * pow(getRadius(), 2.0);
}

/*Print out the result.*/
void Circle::print(){
	cout << "The circle with radius " << getRadius() << "that is located at(" << Shape::getX() << ", " << Shape::getY() << ") has: " << endl;
	cout << "An area of " << getArea() << endl;
	cout << endl;
}