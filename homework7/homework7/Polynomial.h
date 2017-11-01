#include <iostream>

using namespace std;

class Polynomial {
	friend ostream & operator<<(ostream&, Polynomial &);

public:
	Polynomial();
	void set();
	Polynomial operator+(const Polynomial &);
	Polynomial operator-(const Polynomial &);
	void operator=(const Polynomial &);
	Polynomial operator*(const Polynomial &);
	void operator+=(const Polynomial &);
	void operator-=(const Polynomial &);
	void operator*=(const Polynomial &);
private:
	int coefficient[13];
};