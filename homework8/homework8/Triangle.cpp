#include <iostream>
#include "Triangle.h"

using namespace std;

Triangle::Triangle(int xValue, int yValue, double lengthValue, double widthValue) 
	: TwoDimensionalShape(xValue, yValue){
	setLength(lengthValue);
	setWidth(widthValue);
}

void Triangle::setLength(double lengthValue) {
	length = lengthValue;
}

void Triangle::setWidth(double widthValue) {
	width = widthValue;
}

double Triangle::getLength() {
	return length;
}

double Triangle::getWidth() {
	return width;
}

double Triangle::getArea() {
	return getLength() * getWidth();
}

void Triangle::print() {
	cout << "The triangle with length " << getLength() << "and width " << getWidth() << " that is located at(" << Shape::getX() << ", " << Shape::getY() << ") has: " << endl;
	cout << "An area of " << getArea() << endl;
	cout << endl;
}

