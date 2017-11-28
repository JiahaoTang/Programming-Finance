#include <iostream>
#include "Stock.h"

using namespace std;

Stock::Stock(string name, double stockPrice, int amount) {
	companySymbol = name;
	price = stockPrice;
	shares = amount;
	pre = NULL;
	back = NULL;
}

double Stock::getPrice() {
	return price;
}

int Stock::getShares() {
	return shares;
}

string Stock::getName() {
	return companySymbol;
}

double Stock::getValue() {
	return shares * price;
}

void Stock::increaseShares(int amount) {
	shares += amount;
}
void Stock::decreaseShares(int amount) {
	shares -= amount;
}