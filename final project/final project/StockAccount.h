#ifndef StockAccount_h
#define StockAccount_h
#include <string>
#include "DLList.h"
#include "Account.h"

using namespace std;

class StockAccount : public Account{
public:
	StockAccount();
	void setCashBalance(double);
	bool buy(string, string, int);
	bool sell(string, string, int);
	void printPortfolio();
	void printTransactionHistory();
	double getValue();
private:
	DLList *portfolio;
	double totalValue;
	double cashBalance;
};

#endif /* StockAccount_h */
