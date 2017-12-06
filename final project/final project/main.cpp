#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BankAccount.h"
#include "StockAccount.h"
#include <time.h>
#include <fstream>

using namespace std;
void mainInstructions();
void StockInstructions();
void BankInstructions();
void bankManage();
void stockManage();

int main() {
	int choice;
	mainInstructions();
	cout << "Option:";
	cin >> choice;
	while (true) {
		switch (choice) {
		case 1: {
			bankManage();
			break;
		}
		case 2: {
			stockManage();
			break;
		}
		case 3: {
			return 0;
		}
		}
	}

	system("Pause");
    return 0;
}

void bankManage() {
	int choice;
	mainInstructions();
	cout << "Option:";
	cin >> choice;
	BankAccount *bk = new BankAccount();
	while (true) {
		switch (choice) {
		case 1: {
			int cash = bk->getCashBalance();
			cout << "1. You have $" << cash << " in your bank account" << endl;
			cout << endl;
			break;
		}
		case 2: {
			double depositAmount;
			cout << "Please selec the amount you wish to deposit: $" << endl;
			cin >> depositAmount;
			bk->deposit(depositAmount);
			break;
		}
		case 3: {
			double withdrawAmount;
			cout << "Please selec the amount you wish to withdraw: $" << endl;
			cin >> withdrawAmount;
			bk->withdraw(withdrawAmount);
			break;
			break;
		}
		case 4: {
			bk->printHistory();
			break;
		}
		case 5: {
			main();
		}
		}
	}
}

void stockManange() {

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