#include <stdio.h>

#include "library/linked_list.h"


int main()
{
	Node* first = create_node(15);

	insert(first, create_node(8));
	insert(first, create_node(1));
	insert(first, create_node(2));
	insert(first, create_node(3));

	// display elements in the list
	Node* i = first;
	while (i->next)
	{
		printf("%d\t%d\t%d\n", i, i->next, i->data);
		i = i->next;
	}
	// display the last element in the list
	printf("%d\t%d\t%d\n", i, i->next, i->data);
	
	return 0;
}