#include <string>
#include "OvernightPackage.h"
#include <iostream>

using namespace std;

OvernightPackage::OvernightPackage(User senderIn, User receiverIn, int weightIn, double cost, double flatFeePerOunce)
	: Package(senderIn, receiverIn, weightIn, cost + flatFeePerOunce) {}