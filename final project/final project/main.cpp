#include <iostream>
#include "BankAccount.h"

int main(int argc, const char * argv[]) {
	BankAccount *ba = new BankAccount();
	ba->deposit(100);
	ba->withdraw(1500);
	ba->printHistory();
    return 0;
}
