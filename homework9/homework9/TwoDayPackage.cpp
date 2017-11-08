#include <string>
#include "TwoDayPackage.h"
#include <iostream>

using namespace std;

TwoDayPackage::TwoDayPackage(User senderIn, User receiverIn, int weightIn, double cost, double flatFee)
: Package(senderIn, receiverIn, weightIn, cost){
    flatFeePerOunce = flatFee;
}

double TwoDayPackage::calculateCost(){
    return Package::calculateCost() + Package::getWeight() * flatFeePerOunce;
}

double TwoDayPackage::getFlatFee() {
	return flatFeePerOunce;
}