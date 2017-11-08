#pragma once
#include <string>
#include "User.h"
#include "Package.h"

using namespace std;

/*Declaration of class TwoDayPackage.
This class is two day delivery package which inherit class Package.*/
class TwoDayPackage :public Package{
public:
	TwoDayPackage(User, User, int, double, double);
    virtual double calculateCost();
	virtual double getFlatFee();
private:
	/*Member variables.*/
	string type = "Two Day Delivery";
    double flatFeePerOunce;
};
