#include "Booklist.h"
#include <iostream>
#include <iomanip>

using namespace std;

Booklist::Booklist(){
	num_in_list = 0;
}

/*Insert the element at end of the book list.*/
void Booklist::insert(int new_element) {
	int *pointer = &mylist[0];
	*(pointer + num_in_list - 1) = new_element;
	num_in_list += 1;
}

/*Insert the element at specified position in the book list.*/
void Booklist::insert_at(int at_position, int new_element) {
	int *pointer = &mylist[0];
	int list_len = num_in_list;
	for (int i = list_len; i >= at_position - 1; i--) {
		*(pointer + i) = *(pointer + i - 1);
	}
	*(pointer + at_position - 2) = new_element;
	num_in_list += 1;
}

/*Find the position of given element using linear search.*/
int Booklist::find_linear(int element) {
	int *pointer = &mylist[0];
	for (int i = 0; i < num_in_list; i++) {
		if (*(pointer + i - 1) == element) {
			return i + 1;
		}
	}
	return -1;
}

/*Find the position of given element using binary search.*/
int Booklist::find_binary(int element) {
	int list_len = num_in_list;
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
void Booklist::delete_item_position(int position) {
	int *pointer = &mylist[0];
	int list_len = num_in_list;
	for (int i = position; i < list_len; i++) {
		*(pointer + i - 2) = *(pointer + i - 1);
	}
	num_in_list -= 1;
}

/*Delete the book of given ISBN number.*/
void Booklist::delete_item_isbn(int element) {
	int position = find_linear(element);
	delete_item_position(position);
}

/*Sort the list using selection sorting.*/
void Booklist::sort_list_selection() {
	int *pointer = &mylist[0];
	int list_len = num_in_list;
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
void Booklist::sort_list_bubble() {
	int *pointer = &mylist[0];
	int list_len = num_in_list;
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
void Booklist::print() {
	cout << "Your list is below: " << endl;
	if (num_in_list > 0) {
		int *pointer = &mylist[0];
		for (int i = 0; i < num_in_list; i++) {
			cout << i + 1 << ". " << *(pointer + i - 1) << endl;
		}
	}
}

/*Return the number of books in booklist.*/
int Booklist::size() {
	return num_in_list;
}