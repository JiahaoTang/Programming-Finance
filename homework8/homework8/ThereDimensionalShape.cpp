#include <iostream>
#include "ThreeDimensionalShape.h"
using namespace std;

/*Extended from class Shape.*/
ThreeDimensionalShape::ThreeDimensionalShape(int xValue, int yValue, int zValue)
	:Shape(xValue, yValue) {
	setZ(zValue);
}

/*Set z coordinate with value z.*/
void ThreeDimensionalShape::setZ(int zValue) {
	z = zValue;
}

/*Get the z coordinate.*/
int ThreeDimensionalShape::getZ() {
	return z;
}