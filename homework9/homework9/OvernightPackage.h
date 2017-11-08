#pragma once
#include <string>
#include "User.h"
#include "Package.h"

using namespace std;

/*Declaration of class OvernightPackage.
This class is overnight delivery package which inherit class Package.*/
class OvernightPackage :public Package {
public:
	OvernightPackage(User, User, int, double, double);
    virtual double calculateCost();
	virtual double getFlatFee();
private:
	/*Member variables.*/
    double flatFeePerOunce;
	string type = "Overnight Delivery";
};
