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
	double getCashBalance();
	int buy(string, string, int, double);
	int sell(string, string, int, double);
	void printPortfolio();
	void printTransactionHistory();
	double getValue();
	void drawGraph();
	void storeTotalPortfolioValue();
private:
	DLList *portfolio;
	double totalValue;
	double cashBalance;
};

#endif /* StockAccount_h */
