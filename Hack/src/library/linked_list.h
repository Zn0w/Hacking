#pragma once

#include <stdint.h>


template <class ElementType>
struct Node
{
	Node<ElementType>* next;
	ElementType data;
};

template <class Type>
class LinkedList
{
private:
	Node<Type>* begin = 0;
	Node<Type>* end = 0;

public:
	LinkedList(Type* data_array, uint64_t size);
	~LinkedList();

	inline Node<Type>* getBegin()
	{
		return begin;
	}

	inline Node<Type>* getEnd()
	{
		return end;
	}

	void insert_front(Type data);
	void insert_back(Type data);

	void delete_front();
	void delete_back();

private:
	Node<Type>* create_node(Type data);
};


template <class Type>
Node<Type>* LinkedList<Type>::create_node(Type data)
{
	Node<Type>* new_node = new Node<Type>;
	new_node->next = 0;
	new_node->data = data;

	return new_node;
}

template <class Type>
LinkedList<Type>::LinkedList(Type* data_array, uint64_t size)
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

template <class Type>
LinkedList<Type>::~LinkedList()
{
	Node<Type>* to_delete = begin;
	while (to_delete->next)
	{
		Node<Type>* next_to_delete = to_delete->next;
		delete to_delete;
		to_delete = next_to_delete;
	}
	// delete the last element
	delete to_delete;
}

template <class Type>
void LinkedList<Type>::insert_front(Type data)
{
	Node<Type>* new_node = create_node(data);
	new_node->next = begin;
	begin = new_node;
}

template <class Type>
void LinkedList<Type>::insert_back(Type data)
{
	Node<Type>* new_node = create_node(data);
	end->next = new_node;
	end = new_node;
}

template <class Type>
void LinkedList<Type>::delete_front()
{
	Node<Type>* new_begin = begin->next;
	delete begin;
	begin = new_begin;
}

template <class Type>
void LinkedList<Type>::delete_back()
{
	Node<Type>* current_node = begin;
	while (current_node->next->next)
		current_node = current_node->next;

	delete current_node->next;
	current_node->next = 0;
}