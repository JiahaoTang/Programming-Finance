#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
	Polynomial poly1;
	poly1.set();
	Polynomial poly2;
	poly2.set();
	cout << "First Polynomial is : ";
	cout << poly1 << endl;
	cout << "Second Polynomial is : ";
	cout << poly2 << endl;
	cout << "" << endl;

	cout << "Adding polynomial yields: ";
	cout << poly1 + poly2 << endl;
	cout << "+= the polynomial yields: ";
	Polynomial poly_first, poly_sencond;
	poly_first = poly1;
	poly_sencond = poly2;
	poly_first += poly_sencond;
	cout << poly_first << endl;
	cout << "" << endl;
	
	cout << "Substracting polynomial yields: ";
	cout << poly1 - poly2 << endl;
	cout << "-= the polynomial yields: ";
	poly_first = poly1;
	poly_sencond = poly2;
	poly_first -= poly_sencond;
	cout << poly_first << endl;
	cout << "" << endl;

	cout << "Multiplying polynomial yields: ";
	cout << poly1 * poly2 << endl;
	cout << "*= the polynomial yields: ";
	poly1 *= poly2;
	cout << poly1 << endl;
	
	system("Pause");
	return 0;
}