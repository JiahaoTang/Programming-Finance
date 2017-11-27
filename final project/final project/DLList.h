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
	void removeLast();
	double getTotalValue();
	void sortOne();
	void sortTwo();
private:
	Stock *sentinel;
	int listSize;
	double totalValue;
};
#endif /* DLList_h */
