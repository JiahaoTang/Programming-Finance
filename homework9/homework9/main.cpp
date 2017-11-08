#include <iostream>
#include "User.h"
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void outputInfo (Package*);

int main() {
	User JohnSmith = User("John Smith", "1 Davidson Road", "Piscataway", "NJ", "08854");
	User TomSmith = User("Tom Smith", "2 Davidson Road", "Piscataway", "NJ", "08854");
	User MarySmith = User("MarySmith", "3 Davidson Road", "Piscataway", "NJ", "08854");
	User JenniferSmith = User("Jennifer Smith", "4 Davidson Road", "Piscataway", "NJ", "08854");

	Package jtPkg = Package(JohnSmith, TomSmith, 10, 0.5);
	Package mjPkg = TwoDayPackage(MarySmith, JenniferSmith, 5, 0.5, 2);
	Package jmPkg = OvernightPackage(JohnSmith, MarySmith, 2, 0.5, 5);

	vector< Package * > vectorOfPackage(3);
	vectorOfPackage[0] = &jtPkg;
	vectorOfPackage[1] = &mjPkg;
	vectorOfPackage[2] = &jmPkg;

	double totalCost = 0;
	for (int i = 0; i < 3; i++) {
		cout << "Package " << i + 1 << ":" << endl;
		cout << endl;
		outputInfo(vectorOfPackage[i]);
		totalCost += (*vectorOfPackage[i]).calculateCost();
	}
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "Totally cost of all the packages:$" << totalCost << endl;
	system("Pause");
	return 0;
}

void outputInfo (Package* pkg) {
	cout << "Sender:" << endl;
	cout << (*pkg).getSender().getName() << endl;
	cout << (*pkg).getSender().getAddress() << endl;
	cout << (*pkg).getSender().getCity() << ", " << (*pkg).getSender().getState() << " " << (*pkg).getSender().getZipCode() << endl;
	cout << endl;

	cout << "Receiver:" << endl;
	cout << (*pkg).getReceiver().getName() << endl;
	cout << (*pkg).getReceiver().getAddress() << endl;
	cout << (*pkg).getReceiver().getCity() << ", " << (*pkg).getReceiver().getState() << " " << (*pkg).getReceiver().getZipCode() << endl;
	cout << endl;

	cout << "Weight of package: " << (*pkg).getWeight() << " ounces" << endl;
	cout << "Type of delivery: " << (*pkg).getType() << endl;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "Cost of Package: $" << (*pkg).calculateCost() << endl;
	cout << endl;
}