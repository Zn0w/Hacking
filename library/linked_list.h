#pragma once

#include <malloc.h>
#include <stdint.h>


struct Node
{
	Node* next;
	uint64_t data;
};


// non-oop implementation

// DOCS : If success, returns a pointer to the allocated on the heap node
// DOCS : If fail, returns 0
Node* create_node(uint64_t data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->next = 0;
	new_node->data = data;

	return new_node;
}

// DOCS : If success, returns
// DOCS : If fail, returns
void insert(Node* begin, Node* new_node)
{
	Node* latest = begin;
	while (latest->next)
		latest = latest->next;
	
	latest->next = new_node;
}

// DOCS : If two nodes are equal, returns true
// DOCS : If two nodes are not equal, returns false
bool equals(Node* n1, Node* n2)
{
	return n1->next == n2->next && n1->data == n2->data;
}

// DOCS : If success, returns
// DOCS : If fail, returns
void delete_node(Node* begin, Node* to_delete)
{
	if (begin == 0)
	{
		return;
	}
	else if (equals(begin, to_delete))
	{
		Node* new_begin = begin->next;
		free(begin);
		begin = new_begin;
		return;
	}
	
	Node* current_node = begin;
	while (current_node->next)
	{
		if (equals(current_node->next, to_delete))
			break;
		
		current_node = current_node->next;
	}
	
	if (current_node->next == 0)
	{
		//printf("There is no element with this index\n");
		return;
	}
	
	Node* node = current_node->next->next;
	free(current_node->next);
	current_node->next = node;
}

// DOCS : If success, returns a pointer to the beginning of the linked list
// DOCS : If fail, returns 0
Node* construct_list(uint64_t* data_array, uint64_t size)
{
	Node* begin = 0;
	Node* node = create_node(*(data_array));
	begin = node;
	
	for (int i = 1; i < size; i++)
	{
		node->next = create_node(*(data_array + i));
		if (node->next == 0)
			return 0;
		else
			node = node->next;
	}

	return begin;
}