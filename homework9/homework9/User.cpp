#pragma once
#include <string>
#include "User.h"

using namespace std;
User::User() {}
/*Constructor
  Set information of user.*/
User::User(string nameStr, string addressStr, string cityStr, string stateStr, string zipCodeStr) {
	name = nameStr;
	address = addressStr;
	city = cityStr;
	state = stateStr;
	zipCode = zipCodeStr;
}

/*Get name of user.*/
string User::getName() {
	return name;
}

/*Get address of user.*/
string User::getAddress() {
	return address;
}

/*Get city of user.*/
string User::getCity() {
	return city;
}

/*Get state of user.*/
string User::getState() {
	return state;
}

/*Get zipcode of user.*/
string User::getZipCode() {
	return zipCode;
}
