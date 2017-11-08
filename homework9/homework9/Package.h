#pragma once
#include <string>
#include "User.h"

using namespace std;
/*Declaration of class Package.
  This class is regular package.*/
class Package {
public:
	Package(User, User, int, double);
	virtual double calculateCost();
	User getSender();
	User getReceiver();
	int getWeight();
	string getType();
	double getFee();
	virtual double getFlatFee();
private:
	/*Member variables.*/
	User sender;
	User receiver;
	int weight;
	double costPerOunce;
	string type = "Regular Delivery";
};
