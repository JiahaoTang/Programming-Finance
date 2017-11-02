#include <iostream>
#include "Circle.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Tetrahedrons.h"

using namespace std;

int main() {
	//Initialized variables.
	int choice, x, y, z;
	double radius, length, width, sideLength;
	Circle ci;
	Triangle tr;
	Sphere sp;
	Tetrahedrons te;
	//Always run the program until user selected 0.
	while (true) {
		cout << "Please choose a shape or 0 to exit:" << endl;
		cout << "1. Circle" << endl;
		cout << "2. Triangle" << endl;
		cout << "3. Sphere" << endl;
		cout << "4. Regular Tetrahedron " << endl;
		cout << "0. Exit" << endl;
		cout << "Choice: ";
		cin >> choice;
		//Selected different class to calculate the result according to users' selection.
		switch (choice) {
		case 1: {
			cout << endl;
			cout << "You have chosen the circle." << endl;
			cout << endl;
			cout << "Please enter the center of the circle (x-coordinate and then y-coordinate):" << endl;
			cin >> x;				//Input x and y coordinate.
			cin >> y;
			cout << endl;
			cout << "Please enter the radius of the circle." << endl;
			cin >> radius;			//Input radius of circle.
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
			cin >> x;				//Input x and y coordinate.
			cin >> y;
			cout << endl;
			cout << "Please enter the length and width of the triangle." << endl;
			cin >> length;			//Input length and width of triangle.
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
			cin >> radius;		//Input radius of sphere.
			cout << endl;
			cout << "Please enter the center of the sphere (x-coordinate, y-coordinate, then z-coordinate):" << endl;
			cin >> x;			//Input x, y and z coordinate.
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
			cin >> sideLength;	//Input length of side of tetrahedron.
			cout << endl;
			cout << "Please enter the center of the regular tetrahedron (x-coordinate, y-coordinate, then z-coordinate):" << endl;
			cin >> x;			//Input x, y and z coordinate.
			cin >> y;
			cin >> z;
			cout << endl;
			te = Tetrahedrons(x, y, z, sideLength);
			te.print();
			break;
			}
		case 0: {
			return 0;	//Stop and exit the program.
			break;
			}
		}
	}
}