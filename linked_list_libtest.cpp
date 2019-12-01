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
	Node* first = create_node(15);

	insert(first, create_node(8));

	Node* node = create_node(1);
	insert(first, node);
	
	insert(first, create_node(2));
	insert(first, create_node(3));

	display_list(first);

	delete_node(first, node);

	display_list(first);
	
	return 0;
}