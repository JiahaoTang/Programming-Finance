#include <iostream>
#include <iomanip>

#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial() {
	for (int i = 0; i < 13; i++) {
		coefficient[i] = 0;
	}
}

void Polynomial::set() {
	cout << "Enter the number of polynomial terms: ";
	int terms;
	cin >> terms;
	for (int i = 0; i < terms; i++) {
		cout << "Enter coefficient and exponent : ";
		int exp, coe;
		cin >> coe;
		cin >> exp;
		coefficient[exp] = coe;
	}
}

Polynomial Polynomial::operator+(const Polynomial& para) {
	Polynomial result;

	for (int i = 0; i < 13; i++) {
		result.coefficient[i] = para.coefficient[i] + coefficient[i];
	}

	return result;
}

Polynomial Polynomial::operator-(const Polynomial& para) {
	Polynomial result;

	for (int i = 0; i < 13; i++) {
		result.coefficient[i] = coefficient[i] - para.coefficient[i];
	}
	return result;
}

void Polynomial::operator=(const Polynomial& para) {
	for (int i = 0; i < 13; i++) {
		coefficient[i] = para.coefficient[i];
	}
}

Polynomial Polynomial::operator*(const Polynomial& para) {
	Polynomial result;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			for (int k = 0; k < 13; k++) {
				if (j + k == i) {
					result.coefficient[i] += coefficient[j] * para.coefficient[k];
				}
			}
		}
	}
	return result;
}

void Polynomial::operator+=(const Polynomial& para) {
	for (int i = 0; i < 13; i++) {
		coefficient[i] += para.coefficient[i];
	}
}

void Polynomial::operator-=(const Polynomial& para) {
	for (int i = 0; i < 13; i++) {
		coefficient[i] -= para.coefficient[i];
	}
}

void Polynomial::operator*=(const Polynomial& para) {
	Polynomial result;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			for (int k = 0; k < 13; k++) {
				if (j + k == i) {
					result.coefficient[i] += coefficient[j] * para.coefficient[k];
				}
			}
		}
	}
	
	for (int i = 0; i < 13; i++) {
		coefficient[i] = result.coefficient[i];
	}
}

ostream & operator<<(ostream & out, Polynomial &para) {
	//If coefficients are all zero, return 0.
	bool allZero = true;
	for (int i = 0; i < 13; i++) {
		if (para.coefficient[i] != 0) allZero = false;
	}
	if (allZero == true) { 
		out << 0;
		return out;
	}

	//Normal print.
	bool isFirst = true;
	for (int i = 0; i < 13; i++) {
		if (para.coefficient[i] == 0) continue;
		else if (para.coefficient[i] > 0) {
			if (i == 0) out << para.coefficient[i];
			else if (i == 1) {
				if (isFirst == true) {
					out << para.coefficient[i] << "x";
				}
				else {
					out << " + " << para.coefficient[i] << "x";
				}
			}
			else {
				if (isFirst == true) {
					out << para.coefficient[i] << "x^" << i;
				}
				else {
					out << " + " << para.coefficient[i] << "x^" << i;
				}
			}
			isFirst = false;
		}else {
			if (i == 0) out << para.coefficient[i];
			else if (i == 1) {
				if (isFirst == true) {
					out << para.coefficient[i] << "x";
				}
				else {
					out << " - " << 0 - para.coefficient[i] << "x";
				}
			}
			else {
				if (isFirst == true) {
					out << para.coefficient[i] << "x^" << i;
				}
				else {
					out << " - " << 0 - para.coefficient[i] << "x^" << i;
				}
			}
			isFirst = false;
		}
	}
	return out;
}