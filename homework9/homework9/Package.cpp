#include <string>
#include "Package.h"
#include <iostream>

using namespace std;

Package::Package(User senderIn, User receiverIn, int weightIn, double cost) {
	sender = senderIn;
	receiver = receiverIn;
	weight = weightIn;
	costPerOunce = cost;
}

double Package::calculateCost() {
	return getWeight() * costPerOunce;
}

User Package::getSender() {
	return sender;
}

User Package::getReceiver() {
	return receiver;
}

int Package::getWeight() {
	return weight;
}

string Package::getType() {
	return type;
}

double Package::getFee() {
	return costPerOunce;
}

double Package::getFlatFee() {
	return 0;
}
