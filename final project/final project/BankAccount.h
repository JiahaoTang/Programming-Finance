#ifndef BankAccount_h
#define BankAccount_h
#include <string>
#include "Account.h"

using namespace std;

/*BackAccount inherit from class Account.
  And function setCashBalance() is a bridge between StockAccount and BankAccount.
  So we use bridge design pattern at here.*/
class BankAccount : public Account {
/*Public member functions.*/
public:
	BankAccount();
	void setCashBalance(double cash);
	double getCashBalance();
	void deposit(double amount);
	double withdraw(double amount);
	void printHistory();
	void storeTotalPortfolioValue();
/*Privte member variables.*/
private:
	double cashBalance;
};

#endif /* BankAccount_h */
