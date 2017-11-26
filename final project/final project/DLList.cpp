//
//  DLList.h
//  FinalProject
//
//  Created by 唐嘉豪 on 2017/11/25.
//  Copyright © 2017年 唐嘉豪. All rights reserved.
//

#include <iostream>
#include "DLList.h"

using namespace std;

DLList::DLList() {
	sentinel = new Stock("sentinel", 0, 0);
	sentinel->back = sentinel;
	sentinel->pre = sentinel;
	listSize = 0;
	totalValue = 0;
}

int DLList::size() {
	return listSize;
}

void DLList::addLast(Stock* newNode) {
	newNode->pre = sentinel->pre;
	newNode->back = sentinel;
	sentinel->pre->back = newNode;
	sentinel->pre = newNode;
	listSize++;
	totalValue += newNode->getValue;
}

void DLList::removeLast() {
	sentinel->pre->pre->back = sentinel;
	Stock* lastNode = sentinel->pre;
	sentinel->pre = sentinel->pre->pre;
	totalValue -= lastNode->getValue;
	delete lastNode;
	listSize--;
}

double DLList::getTotalValue() {
	return totalValue;
}

void DLList::sortOne() {

}

void DLList::sortTwo() {

}