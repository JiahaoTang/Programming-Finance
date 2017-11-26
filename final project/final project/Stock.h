//
//  Stock.h
//  FinalProject
//
//  Created by 唐嘉豪 on 2017/11/25.
//  Copyright © 2017年 唐嘉豪. All rights reserved.
//
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
private:
    string companySymbol;
	double price;
    int shares;
};

#endif /* Stock_h */
