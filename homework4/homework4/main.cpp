#include <iostream>

using namespace std;

int input_element();
void insert(int mylist[], int *num_in_list, int new_element);
void insert_at(int mylist[], int *num_in_list, int at_position, int new_element);
int find_linear(int mylist[], int *num_in_list, int element);
int find_binary(int mylist[], int *num_in_list, int element);
void delete_item_position(int mylist[], int *num_in_list, int position);
void delete_item_isbn(int mylist[], int *num_in_list, int element);
void sort_list_selection(int mylist[], int *num_in_list);
void sort_list_bubble(int mylist[], int *num_in_list);
void print(int mylist[], int num_in_list);

int main() {
	int mylist[20];
	int choice, num_in_list = 0;
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
		cout << "	0. exit" << endl;
		
		cout << "Your choice ---" << endl;

		cin >> choice;

		switch (choice) {
			case 1: {
				if (num_in_list >= 20) {
					cout << "The book list is full. You cannot add more books." << endl;
					print(mylist, num_in_list);
					break;
				}
				int new_element = input_element();
				insert(mylist, &num_in_list, new_element);
				print(mylist, num_in_list);
				break;
			}
			case 2: {
				if (num_in_list >= 20) {
					cout << "The book list is full. You cannot add more books." << endl;
					print(mylist, num_in_list);
					break;
				}
				int new_element = input_element();
				int at_position;
				cout << "At what position?" << endl;
				cin >> at_position;
				while (at_position > num_in_list) {
					cout << "The input position is wrong!" << endl;
					cout << "Please enter the position again: ";
					cin >> at_position;
				}
				insert_at(mylist, &num_in_list, at_position, new_element);
				print(mylist, num_in_list);
				break;
			}
			case 3: {
				int element = input_element();
				int position = find_linear(mylist, &num_in_list, element);
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
				sort_list_bubble(mylist, &num_in_list);
				int position = find_binary(mylist, &num_in_list, element);
				if (position == -1) {
					cout << "There is no such element in book list." << endl;
				}
				else {
					cout << "The position of " << element << " is " << position << "." << endl;
				}
				print(mylist, num_in_list);
				break;
			}
			case 5: {
				if (num_in_list == 0) {
					cout << "The book list is empty. You cannot delete any book." << endl;
					break;
				}
				int position;
				cout << "Delete which book (input position)?" << endl;
				cin >> position;
				delete_item_position(mylist, &num_in_list, position);
				print(mylist, num_in_list);
				break;
			}
			case 6: {
				if (num_in_list == 0) {
					cout << "The book list is empty. You cannot delete any book." << endl;
					break;
				}
				int element;
				cout << "Delete which book (input ISBN number)?" << endl;
				cin >> element;
				int position = find_linear(mylist, &num_in_list, element);
				delete_item_isbn(mylist, &num_in_list, element);
				print(mylist, num_in_list);
				break;
			}
			case 7: {
				sort_list_selection(mylist, &num_in_list);
				print(mylist, num_in_list);
				break;
			}
			case 8: {
				sort_list_bubble(mylist, &num_in_list);
				print(mylist, num_in_list);
				break;
			}
			case 9: {
				print(mylist, num_in_list);
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

/*Insert the element at end of the book list.*/
void insert(int mylist[], int *num_in_list, int new_element) {
	int *pointer = &mylist[0];
	*(pointer + *num_in_list - 1) = new_element;
	*num_in_list += 1;
}

/*Insert the element at specified position in the book list.*/
void insert_at(int mylist[], int *num_in_list, int at_position, int new_element) {
	int *pointer = &mylist[0];
	int list_len = *num_in_list;
	for (int i = list_len; i >= at_position - 1; i--) {
		*(pointer + i) = *(pointer + i - 1);
	}
	*(pointer + at_position - 2) = new_element;
	*num_in_list += 1;
}

/*Find the position of given element using linear search.*/
int find_linear(int mylist[], int *num_in_list, int element) {
	int *pointer = &mylist[0];
	for (int i = 0; i < *num_in_list; i++) {
		if (*(pointer + i - 1) == element) {
			return i + 1;
		}
	}
	return -1;
}

/*Find the position of given element using binary search.*/
int find_binary(int mylist[], int *num_in_list, int element) {
	int list_len = *num_in_list;
	int *pointer = &mylist[0];
	int low = 0;
	int high = list_len - 1;
	int mid = (low + high) / 2;
	while (high >= low) {
		if (*(pointer + mid - 1) == element) {
			return mid + 1;
		}
		if (*(pointer + mid - 1) > element) {
			high = mid;
			mid = (low + high) / 2;
		}
		else if (*(pointer + mid - 1) < element) {
			low = mid + 1;
			mid = (low + high) / 2;
		}
	}
	return -1;
}

/*Delete the book of given position.*/
void delete_item_position(int mylist[], int *num_in_list, int position) {
	int *pointer = &mylist[0];
	int list_len = *num_in_list;
	for (int i = position; i < list_len; i++) {
		*(pointer + i - 2) = *(pointer + i - 1);
	}
	*num_in_list -= 1;
}

/*Delete the book of given ISBN number.*/
void delete_item_isbn(int mylist[], int *num_in_list, int element) {
	int position = find_linear(mylist, num_in_list, element);
	delete_item_position(mylist, num_in_list, position);
}

/*Sort the list using selection sorting.*/
void sort_list_selection(int mylist[], int *num_in_list) {
	int *pointer = &mylist[0];
	int list_len = *num_in_list;
	for (int i = 0; i < list_len - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < list_len; j++) {
			if (*(pointer + j - 1) < *(pointer + min_index - 1)) {
				min_index = j;
			}
		}

		if (i != min_index) {
			int temp = *(pointer + i - 1);
			*(pointer + i - 1) = *(pointer + min_index - 1);
			*(pointer + min_index - 1) = temp;
		}
	}
}

/*Sort the list using bubble sorting.*/
void sort_list_bubble(int mylist[], int *num_in_list) {
	int *pointer = &mylist[0];
	int list_len = *num_in_list;
	for (int i = 0; i < list_len - 1; i++) {
		for (int j = 0; j < list_len - i - 1; j++) {
			if (*(pointer + j - 1) > *(pointer + j)) {
				int temp = *(pointer + j);
				*(pointer + j) = *(pointer + j - 1);
				*(pointer + j - 1) = temp;
			}
		}
	}
}

/*Print out the book list.*/
void print(int mylist[], int num_in_list) {
	cout << "Your list is below: " << endl;
	if (num_in_list > 0) {
		int *pointer = &mylist[0];
		for (int i = 0; i < num_in_list; i++) {
			cout << i + 1 << ". " << *(pointer + i - 1) << endl;
		}
	}
}