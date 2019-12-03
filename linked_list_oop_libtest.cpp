#include <iostream>

#include "library/linked_list.h"


template <class Type> void display_list_templates(Node<Type>* begin)
{
	Node<Type>* i = begin;
	while (i->next)
	{
		std::cout << i << "\t" << i->next << "\t" << i->data << std::endl;
		i = i->next;
	}
	// display the last element in the list
	std::cout << i << "\t" << i->next << "\t" << i->data << std::endl;
}

int main()
{
	std::cout << "\nBegin the oop LinkedList test\n";

	char chars[] = {'a', 'b', '3', '0', 'j', ',', 'd', 'q', '6', '+'};

	LinkedList<char> linked_list(chars, 10);

	std::cout << "After constructor test\n";
	display_list_templates(linked_list.begin);

	linked_list.insert_front('3');
	linked_list.insert_front('2');
	linked_list.insert_front('1');

	std::cout << "After insert_front test\n";
	display_list_templates(linked_list.begin);

	linked_list.insert_back('1');
	linked_list.insert_back('2');
	linked_list.insert_back('3');

	std::cout << "After insert_back test\n";
	display_list_templates(linked_list.begin);

	linked_list.delete_front();
	linked_list.delete_front();
	linked_list.delete_front();

	std::cout << "After delete_front test\n";
	display_list_templates(linked_list.begin);

	linked_list.delete_back();
	linked_list.delete_back();
	linked_list.delete_back();

	std::cout << "After delete_back test\n";
	display_list_templates(linked_list.begin);
	
	return 0;
}