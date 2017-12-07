#ifndef BankAccount_h
#define BankAccount_h
#include <string>
#include "Account.h"

using namespace std;

class BankAccount : public Account {
/*Public member functions.*/
public:
	BankAccount();
	void setCashBalance(double cash);
	double getCashBalance();
	void deposit(double amount);
	double withdraw(double amount);
	void printHistory();
/*Privte member variables.*/
private:
	double cashBalance;
};

#endif /* BankAccount_h */
