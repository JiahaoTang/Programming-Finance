#pragma once
#include "Node.h"

/*Declaration of class LinkedList*/
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	int size();
	void addToStart(Node *);
	void addToEnd(Node *);
	void printList();
	bool removeFromStart();
	bool removeFromEnd();
	void removeNodeFromList(int);
	void removeNodeFromList(string);
private:
	Node *head;
	Node *tail;
	int Size;
};