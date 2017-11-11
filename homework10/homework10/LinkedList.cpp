#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
	Size = 0;
}

LinkedList::~LinkedList() {

}

int LinkedList::size() {
	return Size;
}

void LinkedList::addToStart(Node *newNode) {
	if (size() == 0) {
		head = newNode;
		tail = newNode;
		Size++;
	} else {
		newNode->next = head;
		head = newNode;
		Size++;
	}
}

void LinkedList::addToEnd(Node *newNode) {
	if (size() == 0) {
		tail = newNode;
		head = newNode;
		Size++;
	}else {
		tail->next = newNode;
		tail = newNode;
		Size++;
	}
}

void LinkedList::printList() {
	Node *ptr = head;
	while (ptr != NULL) {
		cout << ptr->itemNo << " " << ptr->itemName << endl;
		ptr = ptr->next;
	}
}

bool LinkedList::removeFromStart() {
	if (size() == 0) return false;
	else if (size() != 1) {
		head = head->next;
		Size--;
		return true;
	} else {
		head = NULL;
		tail = head;
		Size--;
		return true;
	}
}

bool LinkedList::removeFromEnd() {
	if (size() == 0) return false;
	else if (size() != 1) {
		Node *ptr = head;
		while (ptr->next->next != NULL) {
			ptr = ptr->next;
		}
		tail = ptr;
		Size--;
		return true;
	}
	else {
		head = NULL;
		tail = head;
		Size--;
		return true;
	}
}

void LinkedList::removeNodeFromList(int no) {
	if (no > size()) {
		cout << "There is no such item." << endl;
	} else if(no == size()) {
		removeFromEnd();
	}
	else if (no == 1) removeFromStart();
	else {
		int counter = 0;
		Node *ptr = head;
		while (counter != no - 1) {
			ptr = ptr->next;
			counter++;
		}
		ptr->next = ptr->next->next;
		Size--;
	}
}

void LinkedList::removeNodeFromList(string name) {
	Node *ptr = head;
	if (name == ptr->itemName) {
		removeFromStart();
		return;
	}
	while (name != ptr->next->itemName) {
		ptr = ptr->next;
	}
	if (ptr->next == tail) {
		removeFromEnd();
		return;
	}
	else {
		ptr->next = ptr->next->next;
		Size--;
	}
}