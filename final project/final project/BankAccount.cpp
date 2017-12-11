#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "BankAccount.h"
#include <iomanip>

using namespace std;
using std::setw;

/*Constructor.*/
BankAccount::BankAccount() {
	ifstream in("bankCashBalance.txt");
	if (!in.is_open()) {
		setCashBalance(10000);
		ofstream file;
		file.open("bankCashBalance.txt");
		file << setiosflags(ios::fixed) << setprecision(2);
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

/*Set the cash balance.*/
void BankAccount::setCashBalance(double cash) {
	cashBalance = cash;
}

/*Get the cash balance.*/
double BankAccount::getCashBalance() {
	return cashBalance;
}

/*Deposit money to bank account with given amount.*/
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
	file << setiosflags(ios::fixed) << setprecision(2);
	file << std::left << setw(20) << "Deposit" << std::left << setw(1) << "$" << std::left << setw(19) << amount << std::left << setw(20) << date << std::left << setw(20) << cashBalance << "\n";
	storeTotalPortfolioValue();
	file.close();
}

/*Withdraw money from bank account with given amount.*/
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
	file << setiosflags(ios::fixed) << setprecision(2);
	file << std::left << setw(20) << "Withdrawal" << std::left << setw(1) << "$" << std::left << setw(19) << amount << std::left << setw(20) << date << std::left << setw(20) << cashBalance << "\n";
	file.close();
	storeTotalPortfolioValue();
	return amount;
}

/*Print out the history of bank account.*/
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

/*Store the total porfolio value and time in to file.*/
void BankAccount::storeTotalPortfolioValue() {
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
		file << std::left << setw(15) << getCashBalance() << std::left << setw(15) << seconds << "\n";
		file.close();
	}
	else {
		file << setiosflags(ios::fixed) << setprecision(2);
		file << std::left << setw(15) << getCashBalance() << std::left << setw(15) << seconds << "\n";
		file.close();
	}
}