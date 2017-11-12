#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include <string>

using namespace std;

void instructions();

int main() {
	int choice;
	//int itemNo = 0;
	//string itemName = "start";
	Node* ptr;
	LinkedList list = LinkedList();
	cout << "Welcome to the shopping list program" << endl;
	while (true) {
		instructions();
		cin >> choice;
		switch (choice) {
		case 1:{
			cout << "Please enter product number to insert at beginning" << endl;
			int itemNo;
			cin >> itemNo;
			cout << "Please enter the name for the product" << endl;
			string itemName;
			cin >> itemName;
			list.addToStart(new Node(itemName, itemNo));
			list.printList();
			break;
		}
		case 2:{
			cout << "Please enter product number to insert at end" << endl;
			int itemNo;
			cin >> itemNo;
			cout << "Please enter the name for the product" << endl;
			string itemName;
			cin >> itemName;
			list.addToEnd(new Node(itemName, itemNo));
			list.printList();
			break;
		}
		case 3:{
			if (list.removeFromStart()) {
				cout << "Remove first item complete!" << endl;
				list.printList();
			}
			else {
				list.printList();
			}
			break;
		}
		case 4:{
			if (list.removeFromEnd()) {
				cout << "Remove last item complete!" << endl;
				list.printList();
			}
			else {
				list.printList();
			}
			break;
		}
		case 5: {
			if (list.size() == 0) {
				list.printList();
			}else {
				int itemNo;
				cout << "Please enter product number to delete from shopping list: " << endl;
				cin >> itemNo;
				list.removeNodeFromList(itemNo);
				list.printList();
			}
			break;
		}
		case 6: {
			if (list.size() == 0) {
				list.printList();
			}
			else {
				int itemName;
				cout << "Please enter product name to delete from shopping list: " << endl;
				cin >> itemName;
				list.removeNodeFromList(itemName);
				list.printList();
			}
			break;
		}
		case 7: {
			list.printList();
			break;
		}
		case 8:
			system("Pause");
			return 0;
		}
	}
}

void instructions() {
	cout << "Please choose an option:" << endl;
	cout << "1.  Add a new node at the beginning" << endl;
	cout << "2.  Add a new node at the end" << endl;
	cout << "3.  Remove the beginning node" << endl;
	cout << "4.  Remove the end node" << endl;
	cout << "5.  Remove a node from the list by entering an item number" << endl;
	cout << "6.  Remove a node from the list by entering an item name" << endl;
	cout << "7.  Print out the list" << endl;
	cout << "8.  Quit the program" << endl;
	cout << "Your choice is: ";
}