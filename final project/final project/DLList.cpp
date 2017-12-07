#include <iostream>
#include <fstream>
#include "DLList.h"
#include <iomanip>

using namespace std;

/*Constructor.*/
DLList::DLList() {
	sentinel = new Stock("sentinel", 0, 0);
	sentinel->back = sentinel;
	sentinel->pre = sentinel;
	listSize = 0;
	totalValue = 0;
}

/*Get the number of different stocks.*/
int DLList::size() {
	return listSize;
}

/*Add a new stock at the last position of DLList.*/
void DLList::addLast(Stock* newNode) {
	newNode->pre = sentinel->pre;
	newNode->back = sentinel;
	sentinel->pre->back = newNode;
	sentinel->pre = newNode;
	listSize++;
	totalValue += newNode->getValue();
}

/*Remove a stock from DLList by given company symbol.*/
bool DLList::remove(string companySymbol) {
	Stock *ptr = sentinel->back;
	if (ptr->getName() == companySymbol) {
		Stock *removeNode = ptr;
		sentinel->back = ptr->back;
		sentinel->back->pre = sentinel;
		totalValue -= removeNode->getShares() * removeNode->getPrice();
		delete removeNode;
		listSize--;
		return true;
	}
	Stock *removeNode = new Stock("removeNode", -1, -1);
	while (ptr != sentinel) {
		if (ptr->back->getName() == companySymbol) {
			Stock *removeNode = ptr->back;
			ptr->back = ptr->back->back;
			ptr->back->pre = ptr;
			totalValue -= removeNode->getShares() * removeNode->getPrice();
			delete removeNode;
			listSize--;
			return true;
		}
		ptr = ptr->back;
	}
	return false;
}

/*Get the total value of whole DLList.*/
double DLList::getTotalValue() {
	return totalValue;
}

/*Sort the DLList according to the total value of every stock.*/
void DLList::bubbleSort() {
	Stock *ptr = sentinel->pre;
	for (int i = 0; i < listSize - 1; i++) {
		for (int j = 0; j < listSize - i - 1; j++) {
			if (ptr->getValue() > ptr->pre->getValue()) {
				string temp_comSymbol = ptr->companySymbol;
				double temp_price = ptr->price;
				int temp_shares = ptr->shares;

				ptr->companySymbol = ptr->pre->companySymbol;
				ptr->price = ptr->pre->price;
				ptr->shares = ptr->pre->shares;

				ptr->pre->companySymbol = temp_comSymbol;
				ptr->pre->price = temp_price;
				ptr->pre->shares = temp_shares;
			}
			ptr = ptr->pre;
		}
		ptr = sentinel->pre;
	}
}

void DLList::sortTwo() {

}

/*Update the file which store the porfolio information.*/
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

/*Get the number of shares by given company symbol.*/
int DLList::getShares(string companySymbol) {
	Stock *ptr = sentinel->back;
	while (ptr != sentinel) {
		if (ptr->back->getName() == companySymbol) {
			return ptr->getShares();
		}
		ptr = ptr->back;
	}
	return -1;
}

/*Increase the shares by given company symbol and amounts.*/
bool DLList::increaseShares(string companySymbol, int shares) {
	Stock *ptr = sentinel->back;
	while (ptr != sentinel) {
		if (ptr->getName() == companySymbol) {
			ptr->increaseShares(shares);
			totalValue += shares * ptr->getPrice();
			return true;
		}
		ptr = ptr->back;
	}
	return false;
}

/*Decrease the shares by given company symbol and amounts.*/
bool DLList::decreaseShares(string companySymbol, int shares) {
	Stock *ptr = sentinel->back;
	while (ptr != sentinel) {
		if (ptr->getName() == companySymbol) {
			if (ptr->getShares() > shares) {
				ptr->decreaseShares(shares);
				totalValue -= shares * ptr->getPrice();
				return true;
			}
			else if (ptr->getShares() == shares) {
				remove(companySymbol);
				return true;
			}
			else {
				return false;
			}
		}
		ptr = ptr->back;
	}
	return false;
}