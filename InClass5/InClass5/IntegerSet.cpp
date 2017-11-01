#include "IntegerSet.h"
// IntegerSet.cpp
// Member-function definitions for class IntegerSet.

#include <iostream>
#include <iomanip>
using namespace std;

/* Write include directive for IntegerSet.h here */

// constructor
IntegerSet::IntegerSet()
{
	for (int i = 0; i < 101; i++) set[i] = 0;
} // end IntegerSet constructor

  // input a set from the user
void IntegerSet::inputSet()
{
	int number;

	do
	{
		cout << "Enter an element (-1 to end): ";
		cin >> number;

		if (validEntry(number))
			set[number] = 1;
		else if (number != -1)
			cout << "Invalid Element\n";
	} while (number != -1); // end do...while

	cout << "Entry complete\n";
} // end function inputSet

  // prints the set to the output stream
void IntegerSet::printSet() const
{
	cout << "{ ";

	for (int u = 0; u < 101; u++)
		if (set[u]) cout << u << " ";

	cout << "}" << endl;
	} // end function printSet

/* Write definition for unionOfSets */
IntegerSet IntegerSet::unionOfSets(IntegerSet setB)
{
	for (int i = 0; i < 101; i++) {
		//If i exists in set A or set B, it will exist in set C.
		if (setB.set[i] == 1 || set[i] == 1) setB.set[i] = 1;
	}
	return setB;
}

/* Write definition for intersectionOfSets */
IntegerSet IntegerSet::intersectionOfSets(IntegerSet setB)
{
	for (int i = 0; i < 101; i++)
	{
		//If i exists in set A and set B, it will exist in set C.
		if (set[i] == 1 && setB.set[i] == 1) {
			setB.set[i] == 1;
		}
		else {
			setB.set[i] = 0;
		}
	}
	return setB;
}

