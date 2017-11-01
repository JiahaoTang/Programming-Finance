#include <iostream>;
#include <time.h>;
#include <fstream>;
#include <stdlib.h>;

using namespace std;
int main() {
	int iterNum, shaded_counter = 0;
	double x, y, PI;
	ofstream file;

	cout << "Please input a iteration number you want the program to estimate PI." << endl;
	cout << "Please input: ";
	cin >> iterNum;

	srand((unsigned int)(time(NULL)));
	//Generate random x and y coordinate and count if the pointer is in shaded area.
	file.open("MonteCarloData.txt");
	for (int i = 0; i < iterNum; i++) {
		x = rand() / double(RAND_MAX);
		y = rand() / double(RAND_MAX);
		if (x * x + y * y < 1) {
			shaded_counter += 1;
		}
		file<< x <<","<< y <<"\n";
		//Automatically stop if estimated PI reach the percision.
		double tempPI = 4 * ((double)shaded_counter / (double)(i + 1));
		if (abs(tempPI - 3.141592) < 0.001) {
			iterNum = i + 1;
			break;
		}
	}
	cout << "Printed numbers to file MonteCarloData.txt.\n";

	//Calculate PI;
	PI = 4 * ((double)shaded_counter / (double)iterNum);
	cout << "-----------------------------------" << endl;
	cout << "After estimation in " << iterNum << " times with method of Monte carlo," << endl;
	cout << "the result is, PI = " << fixed << PI << endl;

	system("Pause");
	return 0;
}