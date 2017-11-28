#include <iostream>
#include "BankAccount.h"
#include "StockAccount.h"

int main(int argc, const char * argv[]) {
	StockAccount *sa = new StockAccount();
	if (!sa->buy("Result_1.txt", "GE", 1000)) 
		cout << "There is no enough cash." << endl;
	sa->printPortfolio();
	cout << endl;
	sa->printTransactionHistory();
	system("Pause");
    return 0;
}
