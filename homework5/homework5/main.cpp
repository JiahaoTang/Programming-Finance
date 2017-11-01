#include <iostream>

using namespace std;

bool has_solution(int array[], int start);

int main() {
	//Some remainders for users to input.
	cout << "Tips: The maximum of array' length is 100. Zero means the end of input." << endl;
	cout << "      Using white space between different numbers in array." << endl;
	cout << " Please input the array: ";
	//Initialized the array according to users' input.
	int array[100];
	int input = 1, counter = 0;
	while (input != 0) {
		cin >> input;
		array[counter] = input;
		counter++;
	}
	//Called the recursive function to judge the puzzle could be solved or not.
	cout << "Can the puzzle be solved?" << endl;
	if (has_solution(array, 0)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("Pause");
}

bool has_solution(int array[], int start) {
	//Calculated the number of elements in array.
	int counter = 1;
	int element = array[0];
	while (element != 0) {
		element = array[counter++];
	}
	counter++;
	//If start position is out of array, return false.
	if (start >= counter || start < 0) return false;
	else if (array[start] == -1) return false;
	//If the element of start position is zero, return true.
	else if (array[start] == 0) return true;
	//Calculate the next two position and change current position element to -1.
	else {
		int next_start1 = start + array[start];
		int next_start2 = start - array[start];
		array[start] = -1;
		//Recursion call.
		return has_solution(array, next_start1) || has_solution(array, next_start2);
	}
	return false;
}