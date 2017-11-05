#include <string>
#include "TwoDayPackage.h"
#include <iostream>

using namespace std;

TwoDayPackage::TwoDayPackage(User senderIn, User receiverIn, int weightIn, double cost, double flatFeePerOunce)
: Package(senderIn, receiverIn, weightIn, cost + flatFeePerOunce){}