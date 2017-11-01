/*
Time: 2017.9.9
Name: Jiahao Tang
Project Name: Homework1
Function: Input five numbers and output maximum and minimum.
*/
#include<iostream>

using namespace std;

int main() {
	int numbers[5];

	//User reminder.
	cout << "Hello, please input five numbers." << endl;
	cout << "Your input is:";
	/*
	Ask user to input numbers. Using space between every number.
	For example: 1 2 3 4 5.
	*/
	for (int i = 0; i < 5; i++) {
		cin >> numbers[i];
	}
	//Find the Maximum.
	int maxNum = numbers[0];
	for (int i = 0; i < 5; i++){
		if(maxNum < numbers[i]) maxNum = numbers[i];
	}
	//Find the Minimum.
	int minNum = numbers[0];
	for (int i = 0; i < 5; i++) {
		if (minNum > numbers[i]) minNum = numbers[i];
	}
	//Print out the result.
	cout << "****************************" << endl;
	cout << "The maximum of numbers is: ";
	cout << maxNum << endl;
	cout << "The minimum of numbers is: ";
	cout << minNum << endl;

	system("Pause");
	return 0;
}
