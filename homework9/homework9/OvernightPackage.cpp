#include <string>
#include "OvernightPackage.h"
#include <iostream>

using namespace std;

/*Constructor.
Set information of overnight delivery package.*/
OvernightPackage::OvernightPackage(User senderIn, User receiverIn, int weightIn, double cost, double flatFee)
	: Package(senderIn, receiverIn, weightIn, cost) {
        flatFeePerOunce = flatFee;
    }

/*Calculate cost of a overnight delivery package.*/
double OvernightPackage::calculateCost(){
    return Package::calculateCost() + Package::getWeight() * flatFeePerOunce;
}

/*Get flat fee per ounce of a overnight delivery pacakge.*/
double OvernightPackage::getFlatFee() {
	return flatFeePerOunce;
}