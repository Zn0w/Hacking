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
	printf("%d\t%d\t%d\n\n", i, i->next, i->data);	
}

int main()
{
	uint64_t values[10] = {800, 600, 12, 453, 56, 288, 45, 7890, 4856, 124576};
	Node* first = construct_list(values, 10);
	Node* last = get_end(first);

	printf("After init\n");
	display_list(first);
	
	insert_front(&first, 8);
	insert_front(&first, 5);
	insert_front(&first, 1);

	printf("After insert_front test\n");
	display_list(first);
	
	insert_back(&last, 2);
	insert_back(&last, 32);
	insert_back(&last,59);

	printf("After insert_back test\n");
	display_list(first);

	delete_front(&first);
	delete_front(&first);
	delete_front(&first);
	delete_front(&first);

	printf("After delete_front test\n");
	display_list(first);

	delete_back(first);
	delete_back(first);
	delete_back(first);

	printf("After delete_back test\n");
	display_list(first);

	delete_list(first);

	printf("After delete_list test\n");
	
	return 0;
}