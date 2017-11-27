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
		file.open("bankAccountHistory.txt");
		file.close();
	}
	else {
		double cash;
		ifstream OpenFile("bankCashBalance.txt");
		OpenFile >> cash;
		setCashBalance(cash);
		OpenFile.close();
	}
}

void BankAccount::setCashBalance(double cash) {
	cashBalance = cash;
}

void BankAccount::deposit(double amount) {
	cashBalance += amount;
	ofstream file;
	file.open("bankCashBalance.txt");
	file << cashBalance << "\n";
	file.close();
	file.open("bankAccountHistory.txt", ios::app);
	file << std::left << setw(10) << "Deposit" << std::left << setw(10) << amount << endl;
	file.close();
}

double BankAccount::withdraw(double amount) {
	cashBalance -= amount;
	ofstream file;
	file.open("bankCashBalance.txt");
	file << cashBalance << "\n";
	file.close();
	file.open("bankAccountHistory.txt", ios::app);
	file << std::left << setw(10) << "Withdraw" << std::left << setw(10) << amount << endl;
	file.close();
	return amount;
}

void BankAccount::printHistory() {
	char line[100];
	ifstream inbk("bankCashBalance.txt");
	inbk.getline(line, 100);
	cout << "The cash balance of this account is: " << line << "." << endl;

	ifstream in("bankAccountHistory.txt");
	while (!in.eof()) {
		in.getline(line, 100);
		cout << line << endl;
	}
	in.close();
}