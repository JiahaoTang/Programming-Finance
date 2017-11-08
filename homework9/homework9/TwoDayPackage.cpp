#include <string>
#include "TwoDayPackage.h"
#include <iostream>

using namespace std;

/*Constructor.
Set information of two day delivery package.*/
TwoDayPackage::TwoDayPackage(User senderIn, User receiverIn, int weightIn, double cost, double flatFee)
: Package(senderIn, receiverIn, weightIn, cost){
    flatFeePerOunce = flatFee;
}

/*Calculate cost of a two day delivery package.*/
double TwoDayPackage::calculateCost(){
    return Package::calculateCost() + Package::getWeight() * flatFeePerOunce;
}

/*Get flat fee per ounce of a two day delivery pacakge.*/
double TwoDayPackage::getFlatFee() {
	return flatFeePerOunce;
}