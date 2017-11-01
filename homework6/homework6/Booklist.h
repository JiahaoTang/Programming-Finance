#pragma once
class Booklist
{
public:
	//Constructor.
	Booklist();
	//Methods in booklist class.
	void insert(int new_element);
	void insert_at(int at_position, int new_element);
	int find_linear(int element);
	int find_binary(int element);
	void delete_item_position(int position);
	void delete_item_isbn(int element);
	void sort_list_selection();
	void sort_list_bubble();
	void print();
	int size();
private:
	//The booklist and the number of boods.
	int mylist[20], num_in_list;
};

