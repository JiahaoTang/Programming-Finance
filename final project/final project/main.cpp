#include <iostream>
#include "BankAccount.h"
#include "StockAccount.h"

int main(int argc, const char * argv[]) {
	StockAccount *sa = new StockAccount();
	int tag1 = sa->buy("Result_1.txt", "GE", 100, 16.00);
	int tag2 = sa->buy("Result_1.txt", "MSFT", 100, 30.00);
	int tag3 = sa->buy("Result_1.txt", "DIS", 100, 31.00);
	int tag4 = sa->sell("Result_2.txt", "GE", 80, 15.00);
	int tag5 = sa->sell("Result_2.txt", "MSFT", 30, 30.00);
	int tag6 = sa->sell("Result_2.txt", "DIS", 50, 31.00);
	/*switch (tag) {
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
	}*/
	
	sa->printPortfolio();
	cout << endl;
	sa->printTransactionHistory();
	system("Pause");
    return 0;
}
