#pragma once

#include <malloc.h>


template <class ElementType> struct Node
{
	Node<ElementType>* next;
	ElementType data;
};

template <class Type> class LinkedList
{
public:
	Node<Type>* begin = 0;
	Node<Type>* end = 0;

public:
	LinkedList(Type* data_array, uint64_t size)
	{
		Node<Type>* node = create_node(*(data_array));
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
		Node<Type>* to_delete = begin;
		while (to_delete->next)
		{
			Node<Type>* next_to_delete = to_delete->next;
			free(to_delete);
			to_delete = next_to_delete;
		}
		// delete the last element
		free(to_delete);
	}

	void insert_front(Type data)
	{
		Node<Type>* new_node = create_node(data);
		new_node->next = begin;
		begin = new_node;
	}

	void insert_back(Type data)
	{
		Node<Type>* new_node = create_node(data);
		end->next = new_node;
		end = new_node;
	}

	void delete_front()
	{
		Node<Type>* new_begin = begin->next;
		free(begin);
		begin = new_begin;
	}

	void delete_back()
	{
		Node<Type>* current_node = begin;
		while (current_node->next->next)
			current_node = current_node->next;
	
		free(current_node->next);
		current_node->next = 0;
	}

private:
	Node<Type>* create_node(Type data)
	{
		Node<Type>* new_node = (Node<Type>*)malloc(sizeof(Node<Type>));
		new_node->next = 0;
		new_node->data = data;
	
		return new_node;
	}
};