//
//  Stock.h
//  FinalProject
//
//  Created by 唐嘉豪 on 2017/11/25.
//  Copyright © 2017年 唐嘉豪. All rights reserved.
//
#include <string.h>
#ifndef Stock_h
#define Stock_h

using namespace std;

class Stock{
public:
    int getPrice();
    int getShares();
    string getName();
    int getValue();
private:
    string companySymbol;
    int price;
    int shares;
};

#endif /* Stock_h */
