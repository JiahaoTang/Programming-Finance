#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BankAccount.h"
#include "StockAccount.h"
#include <time.h>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
	StockAccount *sa = new StockAccount();
	int tag = sa->buy("Result_1.txt", "GE", 499, 16.00);
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

	/*ofstream file;
	file.open("time.txt");
	time_t seconds;
	seconds = time(NULL);
	cout << "The number of seconds since January 1, 1970 is:" << seconds << "\n";
	char date[12];
	tm * timeinfo;
	timeinfo = localtime(&seconds);
	strftime(date, 100, "%X", timeinfo);	cout << date;	file << date;*/
	
	/*string time;
	ifstream file;
	file.open("time.txt");
	file >> time;
	cout << time;*/
	/*BankAccount *bk = new BankAccount();
	bk->deposit(100);
	bk->deposit(1222);
	bk->withdraw(200);
	bk->printHistory();*/
	
	
	system("Pause");
    return 0;
}
