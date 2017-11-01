#include <iostream>
#include "Circle.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Tetrahedrons.h"

using namespace std;

int main() {
	int choice, x, y, z;
	double radius, length, width, sideLength;
	Circle ci;
	Triangle tr;
	Sphere sp;
	Tetrahedrons te;
	while (true) {
		cout << "Please choose a shape or 0 to exit:" << endl;
		cout << "1. Circle" << endl;
		cout << "2. Triangle" << endl;
		cout << "3. Sphere" << endl;
		cout << "4. Regular Tetrahedron " << endl;
		cout << "0. Exit" << endl;
		cout << "Choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << endl;
			cout << "You have chosen the circle." << endl;
			cout << endl;
			cout << "Please enter the center of the circle (x-coordinate and then y-coordinate):" << endl;
			cin >> x;
			cin >> y;
			cout << endl;
			cout << "Please enter the radius of the circle." << endl;
			cin >> radius;
			cout << endl;
			ci = Circle(x, y, radius);
			ci.print();
			break;
			}
		case 2: {
			cout << endl;
			cout << "You have chosen the triangle." << endl;
			cout << endl;
			cout << "Please enter the center of the triangle (x-coordinate and then y-coordinate):" << endl;
			cin >> x;
			cin >> y;
			cout << endl;
			cout << "Please enter the length and width of the triangle." << endl;
			cin >> length;
			cin >> width;
			cout << endl;
			tr = Triangle(x, y, length, width);
			tr.print();
			break;
			}
		case 3: {
			cout << endl;
			cout << "You have chosen the sphere." << endl;
			cout << endl;
			cout << "Please enter the radius of the sphere." << endl;
			cin >> radius;
			cout << endl;
			cout << "Please enter the center of the sphere (x-coordinate, y-coordinate, then z-coordinate):" << endl;
			cin >> x;
			cin >> y;
			cin >> z;
			cout << endl;
			sp = Sphere(x, y, z, radius);
			sp.print();
			break;
			}
		case 4: {
			cout << endl;
			cout << "You have chosen the regular tetrahedron." << endl;
			cout << endl;
			cout << "Please enter the edge length of the regular tetrahedron." << endl;
			cin >> sideLength;
			cout << endl;
			cout << "Please enter the center of the regular tetrahedron (x-coordinate, y-coordinate, then z-coordinate):" << endl;
			cin >> x;
			cin >> y;
			cin >> z;
			cout << endl;
			te = Tetrahedrons(x, y, z, sideLength);
			te.print();
			break;
			}
		case 0: {
			return 0;
			break;
			}
		}
	}
}