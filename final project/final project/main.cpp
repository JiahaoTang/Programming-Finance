#include <iostream>
#include "BankAccount.h"
#include "StockAccount.h"

int main(int argc, const char * argv[]) {
	StockAccount *sa = new StockAccount();
	sa->buy("Result_1.txt", "INTC", 100);
	sa->printPortfolio();
	sa->printTransactionHistory();
	system("Pause");
    return 0;
}
