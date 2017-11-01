#pragma once
#include "Shape.h"

class ThreeDimensionalShape : public Shape {
public:
	ThreeDimensionalShape(int = 0, int = 0, int = 0);
	void setZ(int zValue);
	int getZ();
private:
	int z;
};