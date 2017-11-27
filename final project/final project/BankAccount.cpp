#include <iostream>
#include <fstream>
#include "BankAccount.h"
#include <iomanip>

using namespace std;
using std::setw;

BankAccount::BankAccount() {
	ifstream in("bankCashBalance.txt");
	if (!in.is_open()) {
		setCashBalance(10000);
		ofstream file;
		file.open("bankCashBalance.txt");
		file << 10000 << "\n";
		file.close();

		/*Initialized the bank account history file.*/
		ofstream file;
		file.open("bankAccountHistory.txt");
		file.close();
	}
	else {
		double cash;
		ifstream OpenFile("bankCashBalance.txt");
		OpenFile >> cash;
		setCashBalance(cash);
		OpenFile.close;
	}
}

void BankAccount::setCashBalance(double cash) {
	cashBalance = cash;
}

void BankAccount::deposit(double amount) {
	cashBalance += amount;
	ofstream file;
	file.open("bankAccountHistory.txt", ios::app);
	file << setw(10) << "deposit" << setw(10) << amount << endl;
	file.close();
}

double BankAccount::withdraw(double amount) {
	cashBalance -= amount;
	ofstream file;
	file.open("bankAccountHistory.txt", ios::app);
	file << setw(10) << "withdraw" << setw(10) << amount << endl;
	file.close();
	return amount;
}