#pragma once

#include <malloc.h>
#include <stdint.h>


struct Node
{
	Node* next;
	uint64_t data;
};


// non-oop implementation

// DOCS	: If success, returns a pointer to the allocated on the heap node, the next is set to 0
// 		  If fail, returns 0
Node* create_node(uint64_t data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->next = 0;
	new_node->data = data;

	return new_node;
}

// DOCS : If success, returns a pointer to the beginning of the linked list
// 		  If fail, returns 0
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

Node* get_end(Node* begin)
{
	Node* current_node = begin;
	while (current_node->next)
		current_node = current_node->next;

	return current_node;
}

// DOCS : If success, returns
// 		  If fail, returns
void insert_front(Node** begin, uint64_t data)
{
	Node* new_node = create_node(data);
	new_node->next = *begin;
	*begin = new_node;
}

void insert_back(Node** end, uint64_t data)
{
	Node* new_node = create_node(data);
	(*end)->next = new_node;
	*end = new_node;
}

void insert_back_unknown(Node* begin, uint64_t data)
{
	Node* new_node = create_node(data);
	Node* end = get_end(begin);
	end->next = new_node;
}

void delete_front(Node** begin)
{
	Node* new_begin = (*begin)->next;
	free(*begin);
	*begin = new_begin;
}

void delete_back(Node* begin)
{
	Node* current_node = begin;
	while (current_node->next->next)
		current_node = current_node->next;

	free(current_node->next);
	current_node->next = 0;
}

void delete_list(Node* begin)
{
	Node* to_delete = begin;
	while (to_delete->next)
	{
		Node* next_to_delete = to_delete->next;
		free(to_delete);
		to_delete = next_to_delete;
	}
	// delete the last element
	free(to_delete);
}

/*
// DOCS : If two nodes are equal, returns true
// DOCS : If two nodes are not equal, returns false
bool equals(Node* n1, Node* n2)
{
	return n1->next == n2->next && n1->data == n2->data;
}

void delete_next_to(Node* begin, Node* to_delete)
{	
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
}*/

// oop implementation

class LinkedList
{
public:
	Node* begin = 0;
	Node* end = 0;

public:
	LinkedList(uint64_t* data_array, uint64_t size)
	{
		Node* node = create_node(*(data_array));
		begin = node;
		
		for (int i = 1; i < size; i++)
		{
			node->next = create_node(*(data_array + i));
			if (node->next == 0)
				// TODO : throw exception or something
				return;
			else
				node = node->next;
		}
	
		end = node;
	}
	
	~LinkedList()
	{
		Node* to_delete = begin;
		while (to_delete->next)
		{
			Node* next_to_delete = to_delete->next;
			free(to_delete);
			to_delete = next_to_delete;
		}
		// delete the last element
		free(to_delete);
	}

	void insert_front(uint64_t data)
	{
		Node* new_node = create_node(data);
		new_node->next = begin;
		begin = new_node;
	}

	void insert_back(uint64_t data)
	{
		Node* new_node = create_node(data);
		end->next = new_node;
		end = new_node;
	}

	void delete_front()
	{
		Node* new_begin = begin->next;
		free(begin);
		begin = new_begin;
	}

	void delete_back()
	{
		Node* current_node = begin;
		while (current_node->next->next)
			current_node = current_node->next;
	
		free(current_node->next);
		current_node->next = 0;
	}

private:
	Node* create_node(uint64_t data)
	{
		Node* new_node = (Node*)malloc(sizeof(Node));
		new_node->next = 0;
		new_node->data = data;
	
		return new_node;
	}
};