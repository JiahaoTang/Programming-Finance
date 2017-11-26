#include <iostream>
#include <fstream>
#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount(double cash) {
	ifstream in("portfolio.txt");
	if (!in.is_open()) {
		setCashBalance(10000);
		ofstream file;
		file.open("portfolio.txt");
		file << "10000\n";
		file.close();
	}
	else {

	}
	setCashBalance(cash);
}

void BankAccount::setCashBalance(double cash) {
	cashBalance = cash;
}

void BankAccount::deposit(double amount) {
	cashBalance += amount;
}

double BankAccount::withdraw(double amount) {
	cashBalance -= amount;
	return amount;
}