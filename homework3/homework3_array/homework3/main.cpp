#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
using std::setw;

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

void input(int row, int column, double matrix[][10]) {
	double element;
	cout << "Please enter your matrix with left to right, top to bottom." << endl;
	cout << "Using white space betweent different elements." << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> element;
			matrix[i][j] = element;
		}
	}
}

void display(int row, int column, double matrix[][10]) {
	cout << "Your input is:" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << setw(10) << matrix[i][j];
		}
		cout << "" << endl;
	}
}

void Addition() {
	int row1, column1, row2, column2;
	//Initialized matrix1.
	row1 = inputDimension("row1");
	column1 = inputDimension("column1");
	double matrix1[10][10];
	input(row1, column1, matrix1);
	display(row1, column1, matrix1);
	//Initialized matrix2.
	row2 = inputDimension("row2");
	while (row2 != row1) {
		cout << "row2 should be equals to row1, please enter row2 again." << endl;
		row2 = inputDimension("row2");
	}
	column2 = inputDimension("column2");
	while (column2 != column1) {
		cout << "column2 should be equals to column1, please enter column2 again." << endl;
		column2 = inputDimension("column2");
	}
	double matrix2[10][10];
	input(row2, column2, matrix2);
	display(row2, column2, matrix2);
	//Initialize result matrix and finish adding operation.
	double resultMatrix[10][10];
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < column1; j++) {
			resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

	display(row1, column1, resultMatrix);
}

void Substraction() {
	int row1, column1, row2, column2;
	//Initialized matrix1.
	row1 = inputDimension("row1");
	column1 = inputDimension("column1");
	double matrix1[10][10];
	input(row1, column1, matrix1);
	display(row1, column1, matrix1);
	//Initialized matrix2.
	row2 = inputDimension("row2");
	while (row2 != row1) {
		cout << "row2 should be equals to row1, please enter row2 again." << endl;
		row2 = inputDimension("row2");
	}
	column2 = inputDimension("column2");
	while (column2 != column1) {
		cout << "column2 should be equals to column1, please enter column2 again." << endl;
		column2 = inputDimension("column2");
	}
	double matrix2[10][10];
	input(row2, column2, matrix2);
	display(row2, column2, matrix2);
	//Initialize result matrix and finish subtracting operation.
	double resultMatrix[10][10];
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < column1; j++) {
			resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}

	display(row1, column1, resultMatrix);
}

void Multiplication() {
	double row1, column1, row2, column2;
	//Initialized matrix1.
	row1 = inputDimension("row1");
	column1 = inputDimension("column1");
	double matrix1[10][10];
	input(row1, column1, matrix1);
	display(row1, column1, matrix1);
	//Initialized matrix2.
	row2 = inputDimension("row2");
	while (row2 != column1) {
		cout << "row2 should be equals to column1, please enter row2 again." << endl;
		row2 = inputDimension("row2");
	}
	column2 = inputDimension("column2");
	double matrix2[10][10];
	input(row2, column2, matrix2);
	display(row2, column2, matrix2);
	//Initialize result matrix and finish adding operation.
	double resultMatrix[10][10];
	for (int m = 0; m < row1; m++) {
		for (int s = 0; s < column2; s++) {
			resultMatrix[m][s] = 0;//变量使用前记得初始化,否则结果具有不确定性  
			for (int n = 0; n < row2; n++) {
				resultMatrix[m][s] += matrix1[m][n] * matrix2[n][s];
			}
		}
	}

	display(row1, column2, resultMatrix);
}

void Transpose() {
	int row, column;
	//Initialized matrix.
	row = inputDimension("row");
	column = inputDimension("column");
	double matrix[10][10];
	input(row, column, matrix);
	display(row, column, matrix);

	//Initialize result matrix and finish transpose operation.
	double resultMatrix[10][10];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			resultMatrix[j][i] = matrix[i][j];
		}
	}
	display(column, row, resultMatrix);
}

void Determinant() {
	int row, column;
	//Initialized matrix.
	cout << "For calulating determinant of matrix, the row and column set 3." << endl;
	row = 3;
	column = 3;
	double matrix[10][10];
	input(3, 3, matrix);
	display(row, column, matrix);

	//Initialize result matrix and finish determinant value.
	double restDeterminant1 = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
	double restDeterminant2 = matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0];
	double restDeterminant3 = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
	double determinant = matrix[0][0] * (restDeterminant1) - matrix[0][1] * (restDeterminant2) + matrix[0][2] * (restDeterminant3);
	cout << "The determinant of matrix is: " << determinant << endl;
}

void Inverse() {
	int row, column;
	//Initialized matrix.
	cout << "For calulating determinant of matrix, the row and column set 3." << endl;
	row = 3;
	column = 3;
	double matrix[10][10];
	input(3, 3, matrix);
	display(row, column, matrix);

	//Calculate determinant of matrix.
	double restDeterminant1 = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
	double restDeterminant2 = matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0];
	double restDeterminant3 = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
	double determinant = matrix[0][0] * (restDeterminant1)-matrix[0][1] * (restDeterminant2)+matrix[0][2] * (restDeterminant3);
	if (determinant == 0) {
		cout << "The determinant of this matrix is 0. So there is no inverse matrix of it." << endl;
		return;
	}

	//Calculate transpose of matrix.
	double transposeMatrix[3][3];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			transposeMatrix[j][i] = matrix[i][j];
		}
	}

	//Calculate 2-complement of matrix.
	double complementMatrix[3][3];
	complementMatrix[0][0] = transposeMatrix[1][1] * transposeMatrix[2][2] - transposeMatrix[1][2] * transposeMatrix[2][1];
	complementMatrix[0][1] = - (transposeMatrix[1][0] * transposeMatrix[2][2] - transposeMatrix[1][2] * transposeMatrix[2][0]);
	complementMatrix[0][2] = transposeMatrix[1][0] * transposeMatrix[2][1] - transposeMatrix[1][1] * transposeMatrix[2][0];

	complementMatrix[1][0] = - (transposeMatrix[0][1] * transposeMatrix[2][2] - transposeMatrix[0][2] * transposeMatrix[2][1]);
	complementMatrix[1][1] = transposeMatrix[0][0] * transposeMatrix[2][2] - transposeMatrix[0][2] * transposeMatrix[2][0];
	complementMatrix[1][2] = - (transposeMatrix[0][0] * transposeMatrix[2][1] - transposeMatrix[0][1] * transposeMatrix[2][0]);

	complementMatrix[2][0] = transposeMatrix[0][1] * transposeMatrix[1][2] - transposeMatrix[0][2] * transposeMatrix[1][1];
	complementMatrix[2][1] = - (transposeMatrix[0][0] * transposeMatrix[1][2] - transposeMatrix[0][2] * transposeMatrix[1][0]);
	complementMatrix[2][2] = transposeMatrix[0][0] * transposeMatrix[1][1] - transposeMatrix[0][1] * transposeMatrix[1][0];

	//The pre-result is 2-complement times 1/det(matrix).
	double preInverseMatrix[10][10];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			preInverseMatrix[i][j] = complementMatrix[i][j] / determinant;
		}
	}

	//The result is transpose of pre-result.
	double inverseMatrix[10][10];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			inverseMatrix[i][j] = preInverseMatrix[j][i];
		}
	}

	display(3, 3, inverseMatrix);
}

int main() {
	while (true) {
		int choice, row1, column1;;

		cout << "_________________________" << endl;
		cout << "Menu" << endl;
		cout << " Choice 1: Addition" << endl;
		cout << " Choice 2: Substraction" << endl;
		cout << " Choice 3: Multiplication" << endl;
		cout << " Choice 4: Transpose" << endl;
		cout << " Choice 5: Determinant" << endl;
		cout << " Choice 6: Inverse" << endl;
		cout << " Choice 7: Quit" << endl;

		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1: {Addition(); break; }
			case 2: {Substraction(); break; }
			case 3: {Multiplication(); break; }
			case 4: {Transpose(); break; }
			case 5: {Determinant(); break; }
			case 6: {Inverse(); break; }
			case 7: {return 0; }
		}
	}
}