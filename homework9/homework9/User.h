#pragma once
#include <string>

using namespace std;

class User {
public:
	User();
	User(string, string, string, string, string);
	string getName();
	string getAddress();
	string getCity();
	string getState();
	string getZipCode();
private:
	string name;
	string address;
	string city;
	string state;
	string zipCode;
};