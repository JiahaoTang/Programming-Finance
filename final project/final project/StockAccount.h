//
//  StockAccount.h
//  FinalProject
//
//  Created by JiahaoTang on 2017/11/25.
//  Copyright © 2017年 JiahaoTang. All rights reserved.
//
#ifndef StockAccount_h
#define StockAccount_h
#include <string>
#include "DLList.h"

using namespace std;

class StockAccount {
public:
	StockAccount();
	void buy();
	void sell();
	void printPortfolio();
	double getValue();
private:
	DLList portfolio;
	double totalValue;
	double cash;
};

#endif /* StockAccount_h */
