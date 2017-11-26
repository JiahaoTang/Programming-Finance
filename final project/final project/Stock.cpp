//
//  Stock.cpp
//  FinalProject
//
//  Created by 唐嘉豪 on 2017/11/25.
//  Copyright © 2017年 唐嘉豪. All rights reserved.
//

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