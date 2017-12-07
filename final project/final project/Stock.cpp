#include <iostream>
#include "Stock.h"

using namespace std;

/*Constructor.*/
Stock::Stock(string name, double stockPrice, int amount) {
	companySymbol = name;
	price = stockPrice;
	shares = amount;
	pre = NULL;
	back = NULL;
}

/*Get the price per share of this stock.*/
double Stock::getPrice() {
	return price;
}

/*Get the number of shares.*/
int Stock::getShares() {
	return shares;
}

/*Get the name of this stock.*/
string Stock::getName() {
	return companySymbol;
}

/*Get the total value of this stock.*/
double Stock::getValue() {
	return shares * price;
}

/*Increase shares with given amount.*/
void Stock::increaseShares(int amount) {
	shares += amount;
}

/*Decrease shares with given amount.*/
void Stock::decreaseShares(int amount) {
	shares -= amount;
}