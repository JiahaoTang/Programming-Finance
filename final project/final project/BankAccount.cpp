#define _CRT_SECURE_NO_WARNINGS
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
		file.open("bankAccountHistory.txt", ios::app);
		file << std::left << setw(20) << "Event" << std::left << setw(20) << "Amount" << std::left << setw(20) << "Date" << std::left << setw(20) << "Balance" << "\n";
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

double BankAccount::getCashBalance() {
	return cashBalance;
}

void BankAccount::deposit(double amount) {
	cashBalance += amount;
	ofstream file;
	file.open("bankCashBalance.txt");
	file << cashBalance << "\n";
	file.close();
	file.open("bankAccountHistory.txt", ios::app);
	//calcuate the date.
	time_t seconds;
	seconds = time(NULL);
	char date[12];
	tm * timeinfo;
	timeinfo = localtime(&seconds);
	strftime(date, 100, "%D", timeinfo);
	file << std::left << setw(20) << "Deposit" << std::left << setw(1) << "$" << std::left << setw(19) << amount << std::left << setw(20) << date << std::left << setw(20) << cashBalance << "\n";
	file.close();
}

double BankAccount::withdraw(double amount) {
	if (amount > getCashBalance()) {
		return -1;
	}
	cashBalance -= amount;
	ofstream file;
	file.open("bankCashBalance.txt");
	file << cashBalance << "\n";
	file.close();
	file.open("bankAccountHistory.txt", ios::app);
	//calcuate the date.
	time_t seconds;
	seconds = time(NULL);
	char date[12];
	tm * timeinfo;
	timeinfo = localtime(&seconds);
	strftime(date, 100, "%D", timeinfo);
	file << std::left << setw(20) << "Withdrawal" << std::left << setw(1) << "$" << std::left << setw(19) << amount << std::left << setw(20) << date << std::left << setw(20) << cashBalance << "\n";
	file.close();
	return amount;
}

void BankAccount::printHistory() {
	char line[100];
	ifstream inbk("bankCashBalance.txt");
	inbk.getline(line, 100);
	cout << "The cash balance of this account is: " << line << "." << endl;
	cout << endl;

	ifstream in("bankAccountHistory.txt");
	while (!in.eof()) {
		in.getline(line, 100);
		cout << line;
	}
	in.close();
}