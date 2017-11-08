#include <string>
#include "OvernightPackage.h"
#include <iostream>

using namespace std;

OvernightPackage::OvernightPackage(User senderIn, User receiverIn, int weightIn, double cost, double flatFee)
	: Package(senderIn, receiverIn, weightIn, cost) {
        flatFeePerOunce = flatFee;
    }

double OvernightPackage::calculateCost(){
    return Package::calculateCost() + Package::getWeight() * flatFeePerOunce;
}

double OvernightPackage::getFlatFee() {
	return flatFeePerOunce;
}