//
//  Account.h
//  FinalProject
//
//  Created by JiahaoTang on 2017/11/26.
//  Copyright © 2017年 JiahaoTang. All rights reserved.
//
#ifndef Account_h
#define Account_h
#include <string>

using namespace std;

class Account {
private:
	double cashBalance;
public:
	virtual void setCashBalance() = 0;
};

#endif /* Account_h */
