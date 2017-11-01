#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//Declare functions.
void inputVector(vector<vector<double>> &);
void inputThreeDVector(vector<vector<double>> &);
void outputVector(const vector<vector<double>> &);
vector<vector<double>> addition(vector<vector<double>> &, vector<vector<double>> &);
vector<vector<double>> substraction(vector<vector<double>> &, vector<vector<double>> &);
vector<vector<double>> multiplication(vector<vector<double>> &, vector<vector<double>> &);
vector<vector<double>> transpose(vector<vector<double>> &);
double determinant(vector<vector<double>> &);
vector<vector<double>> inverse(vector<vector<double>> &);
vector<vector<double>> calCofactorMatrix(vector<vector<double>> &);
vector<vector<double>> calPreInverseMatrix(vector<vector<double>> &, double);

//Main function.
int main() {
	while (true) {
		int choice;
		vector<vector<double>> matrix1;
		vector<vector<double>> matrix2;
		//Print out the menu.
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
		//According to operation choice, input matrix data.
		if (choice <= 2) {
			inputVector(matrix1);
			inputVector(matrix2);
			while (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
				cout << "The dimension of two matrices is not equal." << endl;
				cout << "Please enter two equal dimension matrices." << endl;
				cout << "__________________________________________" << endl;
				inputVector(matrix1);
				inputVector(matrix2);
			}
		}
		else if (choice == 3) {
			inputVector(matrix1);
			inputVector(matrix2);
			while (matrix1[0].size() != matrix2.size()) {
				cout << "__________________________________________________________________" << endl;
				cout << "The column of first matrix and row of second matrix are not equal." << endl;
				cout << "Please enter two dimension matrices again." << endl;
				inputVector(matrix1);
				inputVector(matrix2);
			}
		}
		else if (choice == 4) {
			inputVector(matrix1);
		}
		else if (choice <= 6) {
			inputThreeDVector(matrix1);
		}

		//According to operation choice, select different function to calculate result.
		switch (choice) {
		case 1: {
			vector<vector<double>> matrix = addition(matrix1, matrix2);
			outputVector(matrix);
			break;
		}
		case 2: {
			vector<vector<double>> matrix = substraction(matrix1, matrix2);
			outputVector(matrix);
			break; }
		case 3: {
			vector<vector<double>> matrix = multiplication(matrix1, matrix2);
			outputVector(matrix);
			break; }
		case 4: {
			vector<vector<double>> matrix = transpose(matrix1);
			outputVector(matrix);
			break; }
		case 5: {
			double result = determinant(matrix1);
			cout << "Determinant of this matrix is " << result << endl;
			break; }
		case 6: {
			double det = determinant(matrix1);
			if (det == 0) {
				cout << "There is no inverse matrix because determinant is 0." << endl;
				break;
			}
			vector<vector<double>> matrix = inverse(matrix1);
			outputVector(matrix);
			break; }
		case 7: {return 0; }
		}
	}
}

void inputVector(vector<vector<double>> &matrix) {
	int row, column;
	//Input the row of matrix.
	cout << "___________________________________________________________" << endl;
	cout << "Please enter the number of row (0 < row <= 10): ";
	cin >> row;
	while (row < 1 || row > 10) {
		cout << "Error! Please enter row number again.(0 < row <= 10): ";
		cin >> row;
	}
	//Input the column of matrix.
	cout << "Please enter the number of column (0 < column <= 10): ";
	cin >> column;
	while (column < 1 || column > 10) {
		cout << "Error! Please enter column number again.(0 < column <= 10): ";
		cin >> column;
	}
	//Construct the matrix according to row and column.
	matrix.resize(row);
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].resize(column);
	}
	//Input the elements of matrix.
	cout << "___________________________________________________________" << endl;
	cout << "Please enter your matrix with left to right, top to bottom." << endl;
	cout << "Using white space betweent different elements." << endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "Your input is: " << endl;
	outputVector(matrix);
}

void inputThreeDVector(vector<vector<double>> &matrix) {
	int row = 3, column = 3;
	//Construct the matrix according to row and column.
	matrix.resize(row);
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].resize(column);
	}
	//Input the elements of matrix.
	cout << "___________________________________________________________" << endl;
	cout << "Please enter a 3¡Á3 matrix with left to right, top to bottom." << endl;
	cout << "Using white space betweent different elements." << endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "Your input is: " << endl;
	outputVector(matrix);
}

void outputVector(const vector<vector<double>> &matrix) {
	cout << "___________________________________________________________" << endl;
	cout << "Your input is:" << endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << setw(10) << matrix[i][j];
		}
		cout << "" << endl;
	}
}

vector<vector<double>> addition(vector<vector<double>> &matrix1, vector<vector<double>> &matrix2) {
	for (int i = 0; i < matrix1.size(); i++) {
		for (int j = 0; j < matrix1[i].size(); j++) {
			matrix1[i][j] += matrix2[i][j];
		}
	}
	return matrix1;
}

vector<vector<double>> substraction(vector<vector<double>> &matrix1, vector<vector<double>> &matrix2) {
	for (int i = 0; i < matrix1.size(); i++) {
		for (int j = 0; j < matrix1[i].size(); j++) {
			matrix1[i][j] -= matrix2[i][j];
		}
	}
	return matrix1;
}

vector<vector<double>> multiplication(vector<vector<double>> &matrix1, vector<vector<double>> &matrix2) {
	vector<vector<double>> matrix;
	matrix.resize(matrix1.size());
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].resize(matrix2[0].size());
	}

	for (int m = 0; m < matrix1.size(); m++) {
		for (int s = 0; s < matrix2[0].size(); s++) {
			matrix[m][s] = 0;
			for (int n = 0; n < matrix2.size(); n++) {
				matrix[m][s] += matrix1[m][n] * matrix2[n][s];
			}
		}
	}
	
	return matrix;
}

vector<vector<double>> transpose(vector<vector<double>> &matrix) {
	vector<vector<double>> resultMatrix;
	resultMatrix.resize(matrix[0].size());
	for (int i = 0; i < resultMatrix.size(); i++) {
		resultMatrix[i].resize(matrix.size());
	}

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			resultMatrix[j][i] = matrix[i][j];
		}
	}
	return resultMatrix;
}

double determinant(vector<vector<double>> &matrix) {
	//Initialize result matrix and finish determinant value.
	double restDeterminant1 = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
	double restDeterminant2 = matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0];
	double restDeterminant3 = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
	double determinant = matrix[0][0] * (restDeterminant1)-matrix[0][1] * (restDeterminant2)+matrix[0][2] * (restDeterminant3);
	return determinant;
}

vector<vector<double>> inverse(vector<vector<double>> &matrix) {
	double det = determinant(matrix);
	vector<vector<double>> matrixT = transpose(matrix);
	vector<vector<double>> cofactorMatrix = calCofactorMatrix(matrixT);
	vector<vector<double>> preInverseMatrix = calPreInverseMatrix(cofactorMatrix, det);
	vector<vector<double>> inverseMatrix = transpose(preInverseMatrix);
	return inverseMatrix;
}

vector<vector<double>> calCofactorMatrix(vector<vector<double>> &matrix) {
	vector<vector<double>> cofactorMatrix(3);
	for (int i = 0; i < cofactorMatrix.size(); i++) {
		cofactorMatrix[i].resize(3);
	}
	cofactorMatrix[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
	cofactorMatrix[0][1] = -(matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
	cofactorMatrix[0][2] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];

	cofactorMatrix[1][0] = -(matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1]);
	cofactorMatrix[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
	cofactorMatrix[1][2] = -(matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0]);

	cofactorMatrix[2][0] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
	cofactorMatrix[2][1] = -(matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0]);
	cofactorMatrix[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

	return cofactorMatrix;
}

vector<vector<double>> calPreInverseMatrix(vector<vector<double>> &matrix, double det) {
	vector<vector<double>> preInverseMatrix(3);
	for (int i = 0; i < preInverseMatrix.size(); i++) {
		preInverseMatrix[i].resize(3);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			preInverseMatrix[i][j] = matrix[i][j] / det;
		}
	}
	return preInverseMatrix;
}