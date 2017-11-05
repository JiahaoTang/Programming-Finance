#include <iostream>
#include "User.h"
#include "Package.h"
#include <string>
#include <iomanip>

using namespace std;

int main() {
	User sender = User("John Smith", "1 Davidson Road", "Piscataway", "NJ", "08854");
	User receiver = User("Tom Smith", "2 Davidson Road", "Piscataway", "NJ", "08854");
	Package pkg = Package(sender, receiver, 10, 0.5);

	cout << "Sender:" << endl;
	cout << pkg.getSender().getName() << endl;
	cout << pkg.getSender().getAddress() << endl;
	cout << pkg.getSender().getCity() << ", " << pkg.getSender().getState() << " " << pkg.getSender().getZipCode() << endl;
	cout << endl;

	cout << "Receiver:" << endl;
	cout << pkg.getReceiver().getName() << endl;
	cout << pkg.getReceiver().getAddress() << endl;
	cout << pkg.getReceiver().getCity() << ", " << pkg.getReceiver().getState() << " " << pkg.getReceiver().getZipCode() << endl;
	cout << endl;

	cout << "Weight of package: " << pkg.getWeight() << " ounces" << endl;
	cout << "Type of delivery: " << pkg.getType() << endl;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "Cost of Package: $" << pkg.calculateCost() << endl;
	cout << endl;

	system("Pause");
	return 0;
}