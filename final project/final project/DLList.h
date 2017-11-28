#ifndef DLList_h
#define DLList_h
#include <iostream>
#include "Stock.h"

using namespace std;

class DLList {
public:
	DLList();
	int size();
	void addLast(Stock* newNode);
	bool remove(string companySymbol);
	double getTotalValue();
	void sortOne();
	void sortTwo();
	void updatePortfolio();
	int getShares(string companySymbol);
	bool increaseShares(string companySymbol, int shares);
	bool decreaseShares(string companySymbol, int shares);
private:
	Stock *sentinel;
	int listSize;
	double totalValue;
};
#endif /* DLList_h */
