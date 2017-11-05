#pragma once
#include <string>
#include "User.h"
#include "Package.h"

using namespace std;

class TwoDayPackage :public Package{
public:
	TwoDayPackage(User, User, int, double, double);
private:
	string type = "Two Day Delivery";
};
