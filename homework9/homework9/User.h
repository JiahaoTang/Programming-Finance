#pragma once
#include <string>

using namespace std;

/*Declaration of class User.*/
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
	/*Member variables.*/
	string name;
	string address;
	string city;
	string state;
	string zipCode;
};