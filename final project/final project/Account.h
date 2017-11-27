#ifndef Account_h
#define Account_h
#include <string>

using namespace std;

class Account {
private:
	double cashBalance;
public:
	virtual void setCashBalance(double) = 0;
};

#endif /* Account_h */
