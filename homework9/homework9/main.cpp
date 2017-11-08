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
	cout << fixed << setprecision(2);

	User JohnSmith = User("John Smith", "1 Davidson Road", "Piscataway", "NJ", "08854");
	User TomSmith = User("Tom Smith", "2 Davidson Road", "Piscataway", "NJ", "08854");
	User MarySmith = User("MarySmith", "3 Davidson Road", "Piscataway", "NJ", "08854");
	User JenniferSmith = User("Jennifer Smith", "4 Davidson Road", "Piscataway", "NJ", "08854");

	vector< Package * > vectorOfPackage(3);
    Package pkg(JohnSmith, TomSmith, 10, 0.5);
    TwoDayPackage twoDayPkg(MarySmith, JenniferSmith, 5, 0.5, 2);
    OvernightPackage overnightPkg(JohnSmith, MarySmith, 2, 0.5, 5);
    
    vectorOfPackage[0] = &pkg;
    vectorOfPackage[1] = &twoDayPkg;
    vectorOfPackage[2] = &overnightPkg;

	cout << "Package delivery services program" << endl;
	cout << endl;
	cout << "Cost per ounce for a package:  $" << vectorOfPackage[0]->getFee() << "/ounce" << endl;
	cout << "Additional cost for two day delivery:  $" << vectorOfPackage[1]->getFlatFee() << "/ounce" << endl;
	cout << "Cost per ounce for a package:  $" << vectorOfPackage[2]->getFlatFee() << "/ounce" << endl;

	double totalCost = 0;
	for (int i = 0; i < 3; i++) {
		cout << "Package " << i + 1 << ":" << endl;
		cout << endl;
		outputInfo(vectorOfPackage[i]);
		totalCost += (*vectorOfPackage[i]).calculateCost();
	}
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
	cout << "Cost of Package: $" << (*pkg).calculateCost() << endl;
	cout << endl;
}
