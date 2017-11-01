#include <iostream>
#include "ThreeDimensionalShape.h"
using namespace std;

ThreeDimensionalShape::ThreeDimensionalShape(int xValue, int yValue, int zValue)
	:Shape(xValue, yValue) {
	setZ(zValue);
}

void ThreeDimensionalShape::setZ(int zValue) {
	z = zValue;
}

int ThreeDimensionalShape::getZ() {
	return z;
}