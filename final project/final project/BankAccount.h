#ifndef BankAccount_h
#define BankAccount_h
#include <string>
#include "Account.h"

using namespace std;

class BankAccount : public Account {
public:
	BankAccount();
	void setCashBalance(double cash);
	void deposit(double amount);
	double withdraw(double amount);
	void printHistory();
private:
	double cashBalance;
};

#endif /* BankAccount_h */
