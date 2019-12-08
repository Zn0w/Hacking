#pragma once

#include <stdint.h>


template <class Type>
class LinkedList
{
private:
	struct Node
	{
		Node* next;
		Type data;
	};

	Node* begin = 0;
	Node* end = 0;

public:
	LinkedList(Type* data_array, uint64_t size)
	{
		Node* node = create_node(*(data_array));
		begin = node;

		for (int i = 1; i < size; i++)
		{
			node->next = create_node(*(data_array + i));
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
			delete to_delete;
			to_delete = next_to_delete;
		}
		// delete the last element
		delete to_delete;
	}

	Type get_front()
	{
		return begin->data;
	}

	Type get_back()
	{
		return end->data;
	}

	class iterator
	{
		Node* current = 0;
		
	public:
		iterator(Node* begin)
		{
			current = begin;
		}

		Type value()
		{
			return current->data;
		}

		// TODO : make those ++ and -- operators
		bool advance()
		{
			if (current->next == 0)
				return false;
			else
			{
				current = current->next;
				return true;
			}
		}
	};

	iterator get_iterator()
	{
		iterator i(begin);
		return i;
	}

	void insert_front(Type data)
	{
		Node* new_node = create_node(data);
		new_node->next = begin;
		begin = new_node;
	}

	void insert_back(Type data)
	{
		Node* new_node = create_node(data);
		end->next = new_node;
		end = new_node;
	}

	void delete_front()
	{
		Node* new_begin = begin->next;
		delete begin;
		begin = new_begin;
	}

	void delete_back()
	{
		Node* current_node = begin;
		while (current_node->next->next)
			current_node = current_node->next;

		end = current_node;
		delete current_node->next;
		current_node->next = 0;
	}

private:
	Node* create_node(Type data)
	{
		Node* new_node = new Node;
		new_node->next = 0;
		new_node->data = data;

		return new_node;
	}
};