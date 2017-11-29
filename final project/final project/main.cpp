#include <iostream>
#include "BankAccount.h"
#include "StockAccount.h"

int main(int argc, const char * argv[]) {
	StockAccount *sa = new StockAccount();
	//int x = sa->buy("Result_1.txt", "GE", 100, 16.00);
	int tag = sa->sell("Result_1.txt", "GE", 100, 15.00);
	switch (tag) {
		case 0: {
			cout << "Sell successfully." << endl;
			break;
		}
		case -1: {
			cout << "Price is not satisifing." << endl;
			break;
		}
		case -2: {
			cout << "There is no this stock." << endl;
			break;
		}
		case -3: {
			cout << "The shares of this stock is not enough." << endl;
			break;
		}
	}
	sa->printPortfolio();
	cout << endl;
	sa->printTransactionHistory();
	system("Pause");
    return 0;
}
