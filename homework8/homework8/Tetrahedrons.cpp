#include <iostream>
#include "Tetrahedrons.h"
using namespace std;

/*Constructor.*/
Tetrahedrons::Tetrahedrons(int xValue, int yValue, int zValue, double sideLengthValue)
	:ThreeDimensionalShape(xValue, yValue, zValue) {
	setSideLength(sideLengthValue);
}

/*Set the private variable side length of tetrahedron.*/
void Tetrahedrons::setSideLength(double sideLengthValue) {
	sideLength = sideLengthValue;
}

/*Get the private variable side length of tetrahedron.*/
double Tetrahedrons::getSideLength() {
	return sideLength;
}

/*Calculated the surface area of tetrahedron.*/
double Tetrahedrons::getArea() {
	return 1.7321 * getSideLength() * getSideLength();
}

/*Calculated the volume of tetrahedron.*/
double Tetrahedrons::getVolume() {
	return 1.4142 * getSideLength() * getSideLength() * getSideLength() / 12;
}

/*Print out the result.*/
void Tetrahedrons::print() {
	cout << "The Tetrahedrons with sideLength " << getSideLength() << " that is located at(" << Shape::getX() << ", " << Shape::getY() << ", " << ThreeDimensionalShape::getZ() << ") has: " << endl;
	cout << "Surface area of " << getArea() << endl;
	cout << "Volume of " << getVolume() << endl;
	cout << endl;
}