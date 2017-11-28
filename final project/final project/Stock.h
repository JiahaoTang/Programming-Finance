#include <string>
#ifndef Stock_h
#define Stock_h

using namespace std;

class Stock{
public:
	Stock(string, double, int);
	double getPrice();
    int getShares();
    string getName();
    double getValue();
	Stock* pre;
	Stock* back;
	void increaseShares(int amount);
	void decreaseShares(int amount);
private:
    string companySymbol;
	double price;
    int shares;
};

#endif /* Stock_h */
