#pragma once
#include <string>
#include "User.h"
#include "Package.h"

using namespace std;

class OvernightPackage :public Package {
public:
	OvernightPackage(User, User, int, double, double);
private:
	string type = "Overnight Delivery";
};
