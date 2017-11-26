//
//  DLList.h
//  FinalProject
//
//  Created by 唐嘉豪 on 2017/11/25.
//  Copyright © 2017年 唐嘉豪. All rights reserved.
//

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
	void sortOne();
	void sortTwo();
private:
	Stock *sentinel;
	int listSize;
	double totalValue;
};
#endif /* DLList_h */
