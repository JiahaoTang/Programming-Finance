#include <iostream>;

using namespace std;

int main() {
	int maximumStars;
	//Tell user to imput the maximum number.
	cout << "Plaase input the maximun stars (an odd number) in each line: ";
	cin >> maximumStars;

	//Make sure that the input number is a positive odd number;
	while (maximumStars % 2 != 1 || maximumStars <= 0) {
		cout << "The number of Maximum stars should be a positive odd number" << endl;
		cout << "Plaase input a positive odd number: ";
		cin >> maximumStars;
	}

	//Use double for loop to print the upper triangle shape of diamond.
	for (int i = 0; i < maximumStars / 2; i++) {
		//Print out the blank space of every line.
		for (int j = 0; j < maximumStars / 2 - i; j++) {
			cout << " ";
		}
		//Print out the stars of every line.
		for (int k = 0; k < 2 * i + 1; k++) {
			cout << "*";
		}
		//To start a new line.
		cout << "" << endl;
	}

	//Print out the center line of diamond.
	for (int i = 0; i < maximumStars; i++) {
		cout << "*";
	}
	//To start a new line.
	cout << "" << endl;

	//Use double for loop to print out the lower triangle shape of diamond.
	for (int i = 0; i < maximumStars / 2; i++) {
		//Print out the blank space of every line.
		for (int j = 0; j < i + 1; j++) {
			cout << " ";
		}
		//Print out the stars of every line.
		for (int k = 0; k < maximumStars - 2 * i - 2; k++) {
			cout << "*";
		}
		//To start a new line.
		cout << "" << endl;
	}

	system("Pause");
	return 0;
}