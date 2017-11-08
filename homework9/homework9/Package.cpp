#include <string>
#include "Package.h"
#include <iostream>

using namespace std;
/*Constructor.
  Set information of package.*/
Package::Package(User senderIn, User receiverIn, int weightIn, double cost) {
	sender = senderIn;
	receiver = receiverIn;
	weight = weightIn;
	costPerOunce = cost;
}

/*Calculate cost of a regular package.*/
double Package::calculateCost() {
	return getWeight() * costPerOunce;
}

/*Get sender of pacakge.*/
User Package::getSender() {
	return sender;
}

/*Get receiver of pacakge.*/
User Package::getReceiver() {
	return receiver;
}

/*Get weight of pacakge.*/
int Package::getWeight() {
	return weight;
}

/*Get type of pacakge.*/
string Package::getType() {
	return type;
}

/*Get fee per ounce of pacakge.*/
double Package::getFee() {
	return costPerOunce;
}

/*A virtual function in pacakge.
  There is no flat fee for regular package.*/
double Package::getFlatFee() {
	return 0;
}
