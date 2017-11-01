#include <iostream>
#include "Shape.h"
using namespace std;

Shape::Shape(int xValue, int yValue) {
	setX(xValue);
	setY(yValue);
}

void Shape::setX(int xValue) {
	x = xValue;
}

void Shape::setY(int yValue) {
	y = yValue;
}

int Shape::getX() {
	return x;
}

int Shape::getY() {
	return y;
}