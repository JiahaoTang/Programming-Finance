#include <iostream>
#include <string>
using namespace std;

int countNum(string, char);
int main() {
	string str;
	char chr;
	cout << "Please enter a string: ";
	getline(cin, str);
	cout << "Please enter a character: ";
	cin.get(chr);

	cout << countNum(str, chr) << endl;
	system("Pause");
	return 0;
}

int countNum(string str, char chr) {
	if (str.length() == 0) {
		return 0;
	}
	else if (chr == str[str.length() - 1]) {
		str.pop_back();
		return 1 + countNum(str, chr);
	}
	else {
		str.pop_back();
		return countNum(str, chr);
	}
}