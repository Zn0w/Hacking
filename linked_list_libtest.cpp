#include <stdio.h>

#include "library/linked_list.h"


void display_list(Node* begin)
{
	Node* i = begin;
	while (i->next)
	{
		printf("%d\t%d\t%d\n", i, i->next, i->data);
		i = i->next;
	}
	// display the last element in the list
	printf("%d\t%d\t%d\n", i, i->next, i->data);	
}

int main()
{
	uint64_t values[10] = {800, 600, 12, 453, 56, 288, 45, 7890, 4856, 124576};
	Node* first = construct_list(values, 10);
	Node* last = get_end(first);

	insert_front(&first, 8);
	insert_front(&first, 5);
	insert_front(&first, 1);
	
	insert_back(&last, 2);
	insert_back(&last, 32);
	insert_back(&last,59);
	
	insert_back_unknown(first, 2);
	insert_back_unknown(first, 32);
	insert_back_unknown(first,59);


	display_list(first);
	/*
	// testing delete_node
	delete_node(first, node);
	delete_node(first, first);

	display_list(first);

	// testing construct_list
	//Node* first_2
	*/
	return 0;
}