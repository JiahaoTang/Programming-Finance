#include <iostream>
#include "Tetrahedrons.h"
using namespace std;

Tetrahedrons::Tetrahedrons(int xValue, int yValue, int zValue, double sideLengthValue)
	:ThreeDimensionalShape(xValue, yValue, zValue) {
	setSideLength(sideLengthValue);
}

void Tetrahedrons::setSideLength(double sideLengthValue) {
	sideLength = sideLengthValue;
}

double Tetrahedrons::getSideLength() {
	return sideLength;
}

double Tetrahedrons::getArea() {
	return 1.7321 * getSideLength() * getSideLength();
}

double Tetrahedrons::getVolume() {
	return 1.4142 * getSideLength() * getSideLength() * getSideLength() / 12;
}

void Tetrahedrons::print() {
	cout << "The Tetrahedrons with sideLength " << getSideLength() << " that is located at(" << Shape::getX() << ", " << Shape::getY() << ", " << ThreeDimensionalShape::getZ() << ") has: " << endl;
	cout << "Surface area of " << getArea() << endl;
	cout << "Volume of " << getVolume() << endl;
	cout << endl;
}