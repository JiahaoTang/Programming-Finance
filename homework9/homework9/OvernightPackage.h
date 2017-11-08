#pragma once
#include <string>
#include "User.h"
#include "Package.h"

using namespace std;

class OvernightPackage :public Package {
public:
	OvernightPackage(User, User, int, double, double);
    virtual double calculateCost();
	virtual double getFlatFee();
private:
    double flatFeePerOunce;
	string type = "Overnight Delivery";
};
