#pragma once

// IntegerSet.h
// Header file for class IntegerSet

//#ifndef INTEGER_SET_H
#define INTEGER_SET_H

class IntegerSet
{
//friend IntegerSet unionOfSets(IntegerSet setB);

public:
	IntegerSet(); // constructor

	IntegerSet unionOfSets(IntegerSet setB);/* Write a member funcion prototype for UnionOfSets */

	IntegerSet intersectionOfSets(IntegerSet setB);/* Return the intersection of two sets.*/

	void inputSet(); // read values from user

	void printSet() const;

private:
	int set[101]; // range of 0 - 100

	// determines a valid entry to the set
	int validEntry(int x) const
	{
		return (x >= 0 && x <= 100);
	} // end function validEntry
};

