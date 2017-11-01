#pragma once
class Shape {
public:
	Shape(int = 0, int = 0);
	void setX(int xValue);
	void setY(int yValue);
	int getX();
	int getY();
private:
	int x;
	int y;
};