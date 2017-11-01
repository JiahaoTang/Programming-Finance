#include <iostream>;

using namespace std;

int main() {
	int maximumStars;

	//Tell user to imput the maximum number.
	cout << "Plaase input the maximun stars in each line: ";
	cin >> maximumStars;

	//Make sure that the input number is a positive number;
	while (maximumStars <= 0) {
		cout << "The number of Maximum stars should be a positive number" << endl;
		cout << "Plaase input a positive number: ";
		cin >> maximumStars;
	}

	//Use double for loop to print out the triangle.
	for (int i = 0; i < maximumStars; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		//To start a new line.
		cout << "" << endl;
	}
	system("Pause");
	return 0;
}