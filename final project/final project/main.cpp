#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BankAccount.h"
#include "StockAccount.h"
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;
void mainInstructions();
void StockInstructions();
void BankInstructions();
void bankManage();
void stockManage();

int main() {
	int choice;
	mainInstructions();
	cout << "Option: ";
	cin >> choice; 
	cout << endl;
	if (choice > 3 || choice < 1) {
		cout << "The option number is wrong. Please enter a option between 1 and 3." << endl;
		cout << "Option: ";
		cin >> choice;
	}
	while (true) {
		switch (choice) {
		case 1: {
			stockManage();
			return 0;
		}
		case 2: {
			bankManage();
			return 0;
		}
		case 3: {
			return 0;
		}
		}
	}
	return 0;
}

void bankManage() {
	int choice;
	BankAccount *bk = new BankAccount();
	while (true) {
		BankInstructions();
		cout << "Option: ";
		cin >> choice;
		if (choice > 5 || choice < 1) {
			cout << "The option number is wrong. Please enter a option between 1 and 5." << endl;
			cout << "Option: ";
			cin >> choice;
		}
		cout << endl;
		switch (choice) {
		case 1: {
			double cash = bk->getCashBalance();
			cout << setiosflags(ios::fixed) << setprecision(2);
			cout << "1. You have $" << cash << " in your bank account" << endl;
			cout << endl;
			break;
		}
		case 2: {
			double depositAmount;
			cout << "Please select the amount you wish to deposit: $" ;
			cin >> depositAmount;
			bk->deposit(depositAmount);
			break;
		}
		case 3: {
			double withdrawAmount;
			cout << "Please select the amount you wish to withdraw: $";
			cin >> withdrawAmount;
			double tag = bk->withdraw(withdrawAmount);
			if (tag == -1) {
				cout << "Fail: The cash balance is not enough." << endl;
				cout << endl;
			}
			else {
				cout << "Withdraw successfully!" << endl;
				cout << endl;
			}
			break;
		}
		case 4: {
			bk->printHistory();
			cout << endl;
			break;
		}
		case 5: {
			main();
			return;
		}
		}
	}
}

void stockManage() {
	int choice;
	//Create a stockAccount.
	StockAccount *sa = new StockAccount();

	while (true) {
		//Create a random number.
		srand((unsigned)(time(NULL)));
		int fileNo = rand();

		string fileName;
		if (fileNo % 2 == 1) fileName = "Result_1.txt";
		else fileName = "Result_2.txt";

		StockInstructions();
		cout << "Option: ";
		cin >> choice;
		if (choice > 7 || choice < 1) {
			cout << "The option number is wrong. Please enter a option between 1 and 7." << endl;
			cout << "Option: ";
			cin >> choice;
		}
		cout << endl;
		switch (choice) {
		case 1: {//get stock price.
			string companySymbol;
			cout << "Please enter the stock symbol: ";
			cin >> companySymbol;
			double price = sa->getStockPrice(fileName, companySymbol);
			if (price != -1 && price != -2) {
				cout << "Company symbol price per share" << endl;
				cout << setiosflags(ios::fixed) << setprecision(2);
				cout << companySymbol << " $" << price << endl;
			}
			cout << endl;
			break;
		}
		case 2: {//print portfolio
			sa->printPortfolio();
			break;
		}
		case 3: {//buy
			string companySymbol;
			cout << "Please enter the stock symbol you wish to purchase: ";
			cin >> companySymbol;
			int shares;
			cout << "Please enter the number of shares: ";
			cin >> shares;
			double price;
			cout << "Please enter the maximum amount you are willing to pay per share: ";
			cin >> price;

			int tag = sa->buy(fileName, companySymbol, shares, price);
			switch(tag){
				case 0:{
					cout << "Buy successfully!" << endl;
					break;
				}
				case -1:{
					cout << "Fail: The given price is not satisfied." << endl;
					break;
				}
				case -2:{
					cout << "Fail: You do not have enough cash." << endl;
					break;
				}
				case -3:{
					cout << "Fail: You do not have enough cash and the given price is not satisfied." << endl;
					break;
				}
				case -4:{
					cout << "Fail: There is no such company symbol." << endl;
					break;
				}
			}
			cout << endl;
			break;
		}
		case 4: {//sell
			string companySymbol;
			cout << "Please enter the stock symbol you wish to purchase: ";
			cin >> companySymbol;
			int shares;
			cout << "Please enter the number of shares: ";
			cin >> shares;
			double price;
			cout << "Please enter the maximum amount you are willing to pay per share: ";
			cin >> price;

			int tag = sa->sell(fileName, companySymbol, shares, price);
			switch(tag){
				case 0:{
					cout << "Sell successfully!" << endl;
					break;
				}
				case -1:{
					cout << "Fail: The given price is not satisfied." << endl;
					break;
				}
				case -2:{
					cout << "Fail: There is no such company symbol." << endl;
					break;
				}
				case -3:{
					cout << "Fail: You do not have enough shares of this stock to sell." << endl;
					break;
				}
			}
			break;
		}
		case 5: {//graph with MATLAB.
			sa->drawGraph();
			break;
		}
		case 6: {//print transaction history.
			sa->printTransactionHistory();
			cout << endl;
			break;
		}
		case 7: {//return to main menu.
			main();
			return;
		}
		}
	}
	return;
}

void mainInstructions() {
	cout << "Welcom to the Account Management System." << endl;
	cout << "Please select an account to access:" << endl;
	cout << "1. Stock Portfolio Account" << endl;
	cout << "2. Bank Account" << endl;
	cout << "3. Exit" << endl;
}

void StockInstructions() {
	cout << "Please select an option:" << endl;
	cout << "1. Display the price of a stock symbol." << endl;
	cout << "2. Display the current portfolio." << endl;
	cout << "3. Buy shares." << endl;
	cout << "4. Sell shares." << endl;
	cout << "5. View a graph for the portfolio value." << endl;
	cout << "6. View transaction history." << endl;
	cout << "7. Return to previous menu." << endl;
}

void BankInstructions() {
	cout << "Please select an option" << endl;
	cout << "1. View account balance." << endl;
	cout << "2. Deposit money." << endl;
	cout << "3. Withdraw money." << endl;
	cout << "4. Print out history." << endl;
	cout << "5. Return to previous menu" << endl;
}