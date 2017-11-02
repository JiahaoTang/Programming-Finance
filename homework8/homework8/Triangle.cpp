#include <iostream>
#include "Triangle.h"

using namespace std;

/*Constructor.*/
Triangle::Triangle(int xValue, int yValue, double lengthValue, double widthValue) 
	: TwoDimensionalShape(xValue, yValue){
	setLength(lengthValue);
	setWidth(widthValue);
}

/*Set the private variable length of triangle.*/
void Triangle::setLength(double lengthValue) {
	length = lengthValue;
}

/*Set the private variable width of triangle.*/
void Triangle::setWidth(double widthValue) {
	width = widthValue;
}

/*Get the private variable length of triangle.*/
double Triangle::getLength() {
	return length;
}

/*Get the private variable width of triangle.*/
double Triangle::getWidth() {
	return width;
}

/*Get the area of triangle.*/
double Triangle::getArea() {
	return getLength() * getWidth();
}

/*Print out the result.*/
void Triangle::print() {
	cout << "The triangle with length " << getLength() << "and width " << getWidth() << " that is located at(" << Shape::getX() << ", " << Shape::getY() << ") has: " << endl;
	cout << "An area of " << getArea() << endl;
	cout << endl;
}

