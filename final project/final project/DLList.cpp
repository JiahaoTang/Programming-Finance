#include <iostream>
#include <fstream>
#include "DLList.h"
#include <iomanip>

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
	totalValue += newNode->getValue();
}

void DLList::remove(string companySymbol) {
	Stock *ptr = sentinel->back;
	Stock *removeNode = new Stock("removeNode", -1, -1);
	while (ptr != sentinel) {
		if (ptr->back->getName() == companySymbol) {
			Stock *removeNode = ptr->back;
			ptr->back = ptr->back->back;
			ptr->back->pre = ptr;
		}
		ptr = ptr->back;
	}
	delete removeNode;
	listSize--;
}

double DLList::getTotalValue() {
	return totalValue;
}

void DLList::sortOne() {

}

void DLList::sortTwo() {

}

void DLList::updatePortfolio() {
	ofstream file;
	file.open("portfolio.txt");
	file << std::left << setw(20) << "Company Symbol" << std::left << setw(10) << "Number" << std::left << setw(20) << "Price-per-share" << std::left << setw(10) << "Total value" << "\n";
	Stock *ptr = sentinel;
	ptr = ptr->back;
	while (ptr != sentinel) {
		file << std::left << setw(20) << ptr->getName() << std::left << setw(10) << ptr->getShares() <<  std::left << setw(20) << ptr->getPrice() << std::left << setw(20) << ptr->getValue() << "\n";
		ptr = ptr->back;
	}
	file.close();
}