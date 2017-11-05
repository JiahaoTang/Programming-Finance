#pragma once
#include <string>
#include "User.h"

using namespace std;

class Package {
public:
	Package(User, User, int, double);
	double calculateCost();
	User getSender();
	User getReceiver();
	int getWeight();
	string getType();
private:
	User sender;
	User receiver;
	int weight;
	double costPerOunce;
	string type = "Regular Delivery";
};
