#include "Booklist.h"
#include <iostream>

using namespace std;

int input_element();

int main() {
	int choice;
	Booklist bk;
	cout << "Welcome to the Book list program." << endl;

	while (true) {
		cout << "What would you like to do?" << endl;
		cout << "	1. add an element to end of list" << endl;
		cout << "	2. add an element at a location" << endl;
		cout << "	3. find an element by ISBN number (linear search)" << endl;
		cout << "	4. find an element by ISBN number (binary search)" << endl;
		cout << "	5. delete an element at position" << endl;
		cout << "	6. delete an element by ISBN number" << endl;
		cout << "	7. sort the list (using selection sort)" << endl;
		cout << "	8. sort the list (using bubble sort)" << endl;
		cout << "	9. print the list" << endl;
		cout << "	0. exitt" << endl;

		cout << "Your choice ---" << endl;

		cin >> choice;

		switch (choice) {
		case 1: {
			if (bk.size() >= 20) {
				cout << "The book list is full. You cannot add more books." << endl;
				bk.print();
				break;
			}
			int new_element = input_element();
			bk.insert(new_element);
			bk.print();
			break;
		}
		case 2: {
			if (bk.size() >= 20) {
				cout << "The book list is full. You cannot add more books." << endl;
				bk.print();
				break;
			}
			int new_element = input_element();
			int at_position;
			cout << "At what position?" << endl;
			cin >> at_position;
			while (at_position > bk.size()) {
				cout << "The input position is wrong!" << endl;
				cout << "Please enter the position again: ";
				cin >> at_position;
			}
			bk.insert_at(at_position, new_element);
			bk.print();
			break;
		}
		case 3: {
			int element = input_element();
			int position = bk.find_linear(element);
			if (position == -1) {
				cout << "There is no such element in book list." << endl;
			}
			else {
				cout << "The position of " << element << " is " << position << "." << endl;
			}
			break;
		}
		case 4: {
			int element = input_element();
			bk.sort_list_bubble();
			int position = bk.find_binary(element);
			if (position == -1) {
				cout << "There is no such element in book list." << endl;
			}
			else {
				cout << "The position of " << element << " is " << position << "." << endl;
			}
			bk.print();
			break;
		}
		case 5: {
			if (bk.size() == 0) {
				cout << "The book list is empty. You cannot delete any book." << endl;
				break;
			}
			int position;
			cout << "Delete which book (input position)?" << endl;
			cin >> position;
			if (bk.size() < position) {
				cout << "The position is wrong. Please input the position again: ";
				cin >> position;
			}
			bk.delete_item_position(position);
			bk.print();
			break;
		}
		case 6: {
			if (bk.size() == 0) {
				cout << "The book list is empty. You cannot delete any book." << endl;
				break;
			}
			int element;
			cout << "Delete which book (input ISBN number)?" << endl;
			cin >> element;
			int position = bk.find_linear(element);
			bk.delete_item_isbn(element);
			bk.print();
			break;
		}
		case 7: {
			bk.sort_list_selection();
			bk.print();
			break;
		}
		case 8: {
			bk.sort_list_bubble();
			bk.print();
			break;
		}
		case 9: {
			bk.print();
			break;
		}
		case 0: {
			return 0;
			break;
		}
		}
	}
}

/*Input the element.*/
int input_element() {
	int element;
	cout << "Please type in the element" << endl;
	cin >> element;
	return element;
}