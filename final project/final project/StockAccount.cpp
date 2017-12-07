#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "StockAccount.h"
#include "BankAccount.h"
#include <iomanip>
#include<yvals.h>
#if(_MSC_VER>=1600)
#define _STDC_utf_16__
#endif
#include"mex.h"
#include<engine.h>
#include <vector>;

#pragma comment(lib,"libmx.lib")
#pragma comment(lib,"libmex.lib")
#pragma comment(lib,"libeng.lib")

using namespace std;

/*Constructor.*/
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
		file << setiosflags(ios::fixed) << setprecision(2);
		file << 10000.00 << "\n";
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
		file << std::left << setw(10) << "Event" << std::left << setw(20) << "Company Symbol" << std::left << setw(10) << "Number" << std::left << setw(10) << "Price" << std::left << setw(15) << "Total value" << std::left << setw(10) << "Time" << "\n";
		file.close();
	}

	/*Initialized the portfolio.txt and DLList if it is not exist.
	Else, read the porfolio. */
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

/*Set cash balance.*/
void StockAccount::setCashBalance(double cash) {
	cashBalance = cash;
}

/*Get cash balance.*/
double StockAccount::getCashBalance() {
	return cashBalance;
}

/*Get the price of given stock from given file.*/
double StockAccount::getStockPrice(string fileName, string companySymbol){
	ifstream file(fileName);
	if(!file.is_open()){
		cout << "Fail: File open error!" << endl;
		return -2;
	}
	string stockSymbol;
	double price;
	while (stockSymbol != companySymbol && !file.eof()) {
		file >> stockSymbol;
	}
	if (file.eof()){
		cout << "Fail: There is no such company!" << endl;
		return -1;
	}
	file >> price;
	return price;
}

/*Buy a specific stock from given file with given price and shares.*/
int StockAccount::buy(string fileName, string companySymbol, int shares, double buyPrice) {
	/*Search companySymbol in file.*/
	ifstream in(fileName);
	string stockSymbol;
	double price;
	while (stockSymbol != companySymbol && !in.eof()) {
		in >> stockSymbol;
	}
	if (in.eof()) return -4;
	in >> price;
	if (shares * price <= cashBalance && price <= buyPrice) {
		/*Initialized newNode and add it into portfolio.*/
		if (!portfolio->increaseShares(companySymbol, shares)) {
			Stock *newNode = new Stock(companySymbol, price, shares);
			portfolio->addLast(newNode);
			portfolio->bubbleSort();
		}

		/*Store it into transaction history.*/
		ofstream file;
		file.open("transactionHistory.txt", ios::app);
		//calcuate the time.
		time_t seconds;
		seconds = time(NULL);
		char time[12];
		tm * timeinfo;
		timeinfo = localtime(&seconds);
		strftime(time, 100, "%X", timeinfo);
		file << setiosflags(ios::fixed) << setprecision(2);
		double stockValue = price * shares;
		file << std::left << setw(10) << "Buy" << std::left << setw(20) << companySymbol << std::left << setw(10) << shares << std::left << setw(1) << "$" << std::left << setw(9) << price << std::left << setw(1) << "$" << std::left << setw(14) << stockValue << std::left << setw(10) << time << "\n";
		file.close();

		/*Updated the portfolio.txt.*/
		portfolio->updatePortfolio();

		/*Increased total value*/
		totalValue = portfolio->getTotalValue();

		/*Updated cashBalance.txt*/
		BankAccount *bk = new BankAccount();
		bk->withdraw(price * shares);
		ifstream in;
		in.open("bankCashBalance.txt");
		in >> cashBalance;
		in.close();
		return 0;
	}
	else if(price > buyPrice && shares * price > cashBalance){
		return -3;
	}
	else if (shares * price > cashBalance) {
		return -2;
	}
	else if (price > buyPrice) {
		return -1;
	}
	
}

/*Sell a specific stock from given file with given price and shares.*/
int StockAccount::sell(string fileName, string companySymbol, int shares, double sellPrice) {
	/*Search stock in file and get the price.*/
	ifstream in(fileName);
	string stockSymbol;
	double price;
	while (stockSymbol != companySymbol && !in.eof()) {
		in >> stockSymbol;
	}
	if (in.eof()) return -2;
	in >> price;
	if (price < sellPrice) return -1;

	/*Search companySymbol in DLList.*/
	if (portfolio->decreaseShares(companySymbol, shares)) {
		/*Keep portfolio sorted.*/
		portfolio->bubbleSort();
		/*Store it into transaction history.*/
		ofstream file;
		file.open("transactionHistory.txt", ios::app);

		//calcuate the time.
		time_t seconds;
		seconds = time(NULL);
		char time[12];
		tm * timeinfo;
		timeinfo = localtime(&seconds);
		strftime(time, 100, "%X", timeinfo);
		file << setiosflags(ios::fixed) << setprecision(2);
		file << std::left << setw(10) << "Sell" << std::left << setw(20) << companySymbol << std::left << setw(10) << shares << std::left << setw(1) << "$" << std::left << setw(9) << price << std::left << setw(1) << "$" << std::left << setw(14) << price * shares << std::left << setw(10) << time << "\n";
		file.close();

		/*Updated the portfolio.txt.*/
		portfolio->updatePortfolio();

		/*Increased total value*/
		totalValue = portfolio->getTotalValue();

		/*Updated cashBalance.txt*/
		BankAccount *bk = new BankAccount();
		bk->deposit(price * shares);
		ifstream in;
		in.open("bankCashBalance.txt");
		in >> cashBalance;
		in.close();
		storeTotalPortfolioValue();
		return 0;
	}
	else {
		return -3;
	}
}

/*Print out the information of portfolio.*/
void StockAccount::printPortfolio() {
	ifstream in;
	in.open("bankCashBalance.txt");
	in >> cashBalance;
	in.close();
	cout << setiosflags(ios::fixed) << setprecision(2);
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
	cout << endl;
}

/*Print out the transaction history.*/
void StockAccount::printTransactionHistory() {
	char line[100];
	ifstream file;
	file.open("transactionHistory.txt");
	while (!file.eof()) {
		file.getline(line, 200);
		cout << line << endl;
	}
	file.close();
}

/*Get the total value of portfolio.*/
double StockAccount::getValue() {
	return totalValue;
}

/*Draw the graph in MATLAB.*/
void StockAccount::drawGraph() {
	Engine *ep;
	ep = engOpen(NULL);
	if (ep == NULL)
	{
		cout << "ERROR:engine open failed" << endl;
		exit(1);
	}

	/*Load data from tatalPortfolioValue.*/
	vector<double> timeVec;
	vector<double> valueVec;

	/*Open tatalPortfolioValue and read data to vector value.*/
	ifstream portIn("totalPorfolioValue.txt");
	int time;
	double value;
	int counter = 0;

	while (!portIn.eof()) {
		if (counter % 2 == 0) {
			portIn >> value;
			valueVec.push_back(value);
		}
		if (counter % 2 == 1) {
			portIn >> time;
			timeVec.push_back(time);
		}
		counter++;
	}
	int timeSize = timeVec.size();
	int valueSize = valueVec.size();
	double *timeArray = new double[timeSize];
	double *valueArray = new double[valueSize];

	for (int i = 0; i < timeVec.size(); i++) {
		timeArray[i] = timeVec[i];
		valueArray[i] = valueVec[i];
	}
	

	mxArray *A;
	A = mxCreateDoubleMatrix(1, timeVec.size(), mxREAL);
	memcpy((void*)mxGetPr(A), (void *)timeArray, sizeof(double) * timeVec.size());
	mxArray *B;
	B = mxCreateDoubleMatrix(1, valueVec.size(), mxREAL);
	memcpy((void*)mxGetPr(B), (void *)valueArray, sizeof(double) * valueVec.size());

	engPutVariable(ep, "time", A);
	engPutVariable(ep, "value", B);
	engEvalString(ep, "plot(time, value)");

	system("pause");

	mxDestroyArray(A);
	engEvalString(ep, "close;");

	engClose(ep);
}

/*Store the total porfolio value and time in to file.*/
void StockAccount::storeTotalPortfolioValue() {
	//calcuate current time.
	time_t seconds;
	seconds = time(NULL);
	/*char time[12];
	tm * timeinfo;
	timeinfo = localtime(&seconds);
	strftime(time, 100, "%c", timeinfo);*/
	

	ofstream file("totalPorfolioValue.txt", ios::app);
	if (!file.is_open()) {
		ofstream file;
		file.open("totalPorfolioValue.txt", ios::app); 
		file << std::left << setw(15) << "Total Value" << std::left << setw(15) << "Time" << "\n";
		file << setiosflags(ios::fixed) << setprecision(2);
		file << std::left << setw(15) <<  getCashBalance() + getValue() << std::left << setw(15) << seconds << "\n";
		file.close();
	}
	else {
		file << setiosflags(ios::fixed) << setprecision(2);
		file << std::left << setw(15) << getCashBalance() + getValue() << std::left << setw(15) << seconds << "\n";
		file.close();
	}
}