#include <iostream>
#include "Shape.h"
using namespace std;

/*Constructor.*/
Shape::Shape(int xValue, int yValue) {
	setX(xValue);
	setY(yValue);
}

/*Set the private variable X*/
void Shape::setX(int xValue) {
	x = xValue;
}

/*Set the private variable Y*/
void Shape::setY(int yValue) {
	y = yValue;
}

/*Get the private variable X*/
int Shape::getX() {
	return x;
}

/*Get the private variable Y*/
int Shape::getY() {
	return y;
}