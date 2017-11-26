//
//  StockBank.h
//  FinalProject
//
//  Created by JiahaoTang on 2017/11/25.
//  Copyright © 2017年 JiahaoTang. All rights reserved.
//
#ifndef StockBank_h
#define StockBank_h
#include <string>
#include "DLList.h"

using namespace std;

class StockBank {
public:
	StockBank();
	void deposit(int amount);
	int withdraw(int amount);
	void printHistory();
private:
	double cash;
};

#endif /* StockBank_h */
