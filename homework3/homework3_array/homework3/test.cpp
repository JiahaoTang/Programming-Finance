/*#include <iostream>

using namespace std;

int mai() {
	int row1, column1, row2, column2;
	//Initialized matrix1.
	row1 = inputDimension("row1");
	column1 = inputDimension("column1");
	int matrix1[10][10];
	input(row1, column1, matrix1);
	display(row1, column1, matrix1);
	//Initialized matrix2.
	row2 = inputDimension("row2");
	while (row2 != row1) {
		cout << "row2 does not equals to row1, please enter row2 again." << endl;
		row2 = inputDimension("row2");
	}
	column2 = inputDimension("column2");
	while (column2 != column1) {
		cout << "column2 does not equals to column1, please enter column2 again." << endl;
		column2 = inputDimension("column2");
	}
	int matrix2[10][10];
	input(row2, column2, matrix2);
	display(row2, column2, matrix2);
}

int inputDimension(string dimensionName) {
	int number;
	cout << "Please enter the number of " << dimensionName << " (0 < " << dimensionName << " <= 10): ";
	cin >> number;
	while (number < 1 || number > 10) {
		cout << "Error! Please enter " << dimensionName << " number again.(0 < column <= 10): ";
		cin >> number;
	}
	return number;
}

void input(int row, int column, int matrix[][10]) {
	int element;
	cout << "Please enter your matrix with left to right, top to bottom." << endl;
	cout << "Using white space betweent different elements." << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> element;
			matrix[i][j] = element;
		}
	}
}

void display(int row, int column, int matrix[][10]) {
	cout << "Your input is:" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << setw(10) << matrix[i][j];
		}
		cout << "" << endl;
	}
}*/