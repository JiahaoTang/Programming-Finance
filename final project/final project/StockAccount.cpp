#include <iostream>
#include <fstream>
#include "StockAccount.h"
#include <iomanip>

using namespace std;

StockAccount::StockAccount() {
	totalValue = 0;

	/*Open cashBalance.txt, if successed, read cash data and set it.
	  Else, established cashBalance and set it to 10000.
	*/
	ifstream in("bankCashBalance.txt");
	if (!in.is_open()) {
		setCashBalance(10000);
		ofstream file;
		file.open("bankCashBalance.txt");
		file << 10000 << "\n";
		file.close();
	}
	else {
		double cash;
		ifstream OpenFile("bankCashBalance.txt");
		OpenFile >> cash;
		setCashBalance(cash);
		OpenFile.close();
	}

	/*Initialized the transaction history if it is not exist.
	  Else, nothing to do.*/
	ifstream historyIn("transactionHistory.txt");
	if (!historyIn.is_open()) {
		ofstream file;
		file.open("transactionHistory.txt");
		file << std::left << setw(10) << "Event" << std::left << setw(20) << "Company Symbol" << std::left << setw(10) << "Number" << std::left << setw(10) << "Price" << std::left << setw(10) << "Total value" << "\n";
		file.close();
	}

	/*Initialized the portfolio.txt and DLList if it is not exist.
	Else, read the porfolio and */
	ifstream portIn("portfolio.txt");
	if (!portIn.is_open()) {
		ofstream file;
		file.open("portfolio.txt");
		file << std::left << setw(20) << "Company Symbol" << std::left << setw(10) << "Number" << std::left << setw(20) << "Price-per-share" << std::left << setw(10) << "Total value" << "\n";
		file.close();
		portfolio = new DLList();
	}
	else {
		string head;
		for (int i = 0; i < 6; i++) {
			portIn >> head;
		}
		int counter = 0;
		string name;
		double price;
		int shares;
		double value;
		portfolio = new DLList();
		while (!portIn.eof()) {
			if (counter % 4 == 0 && counter > 0) {
				Stock *newNode = new Stock(name, price, shares);
				portfolio->addLast(newNode);
				portIn >> name;
			}
			if (counter % 4 == 0 && counter == 0) portIn >> name;
			if (counter % 4 == 1) portIn >> shares;
			if (counter % 4 == 2) portIn >> price;
			if (counter % 4 == 3) portIn >> value;
			counter++;
		}
		totalValue = portfolio->getTotalValue();
		portIn.close();
	}
}

void StockAccount::setCashBalance(double cash) {
	cashBalance = cash;
}

bool StockAccount::buy(string fileName, string companySymbol, int shares) {
	/*Search companySymbol in file.*/
	ifstream in(fileName);
	string stockSymbol;
	double price;
	while (stockSymbol != companySymbol) {
		in >> stockSymbol;
	}
	in >> price;
	if (shares * price <= cashBalance) {
		/*Initialized newNode and add it into portfolio.*/
		if (!portfolio->increaseShares(companySymbol, shares)) {
			Stock *newNode = new Stock(companySymbol, price, shares);
			portfolio->addLast(newNode);
		}

		/*Store it into transaction history.*/
		ofstream file;
		file.open("transactionHistory.txt", ios::app);
		file << std::left << setw(10) << "Buy" << std::left << setw(20) << companySymbol << std::left << setw(10) << shares << std::left << setw(1) << "$" << std::left << setw(9) << price << std::left << setw(1) << "$" << std::left << setw(9) << price * shares << "\n";
		file.close();

		/*Updated the portfolio.txt.*/
		portfolio->updatePortfolio();

		/*Increased total value*/
		totalValue += price * shares;

		/*Updated cashBalance.txt*/
		cashBalance -= price * shares;
		file.open("bankCashBalance.txt");;
		file << cashBalance << "\n";
		file.close();
		return true;
	}
	else {
		return false;
	}
	
}

bool StockAccount::sell(string fileName, string companySymbol, int shares) {
	/*Search companySymbol in DLList.*/
	if (portfolio->decreaseShares(companySymbol, shares)) {
		/*Search stock in file and get the price.*/
		ifstream in(fileName);
		string stockSymbol;
		double price;
		while (stockSymbol != companySymbol) {
			in >> stockSymbol;
		}
		in >> price;

		/*Store it into transaction history.*/
		ofstream file;
		file.open("transactionHistory.txt", ios::app);
		file << std::left << setw(10) << "Sell" << std::left << setw(20) << companySymbol << std::left << setw(10) << shares << std::left << setw(1) << "$" << std::left << setw(9) << price << std::left << setw(1) << "$" << std::left << setw(9) << price * shares << "\n";
		file.close();

		/*Updated the portfolio.txt.*/
		portfolio->updatePortfolio();

		/*Increased total value*/
		totalValue -= price * shares;

		/*Updated cashBalance.txt*/
		cashBalance += price * shares;
		file.open("bankCashBalance.txt");;
		file << cashBalance << "\n";
		file.close();
		return true;
	}
	else {
		return false;
	}
}

void StockAccount::printPortfolio() {
	cout << "Cash Balance = $" << cashBalance << endl;
	char line[100];
	ifstream file;
	file.open("portfolio.txt"); 
	while (!file .eof()) {
		file.getline(line, 100);
		cout << line << "\n";
	}
	file.close();
	cout << "Total Portfolio Value = $" << cashBalance + getValue() << endl;
}

void StockAccount::printTransactionHistory() {
	char line[100];
	ifstream file;
	file.open("transactionHistory.txt");
	while (!file.eof()) {
		file.getline(line, 100);
		cout << line << endl;
	}
	file.close();
}

double StockAccount::getValue() {
	return totalValue;
}