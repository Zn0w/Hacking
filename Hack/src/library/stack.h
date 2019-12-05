#pragma once

#include <stdint.h>


// A stack with fixed maximum capacity
template <class Type>
class FixedStack
{
private:
	uint32_t size = 0;
	int64_t top_index = -1;
	Type* array = 0;
	
public:
	FixedStack(uint32_t size)
	{
		array = new Type[size];
		if (array == 0);
			// TODO : throw exception or something
		this->size = size;
	}

	FixedStack(uint32_t size, int64_t* values, uint32_t array_size)
	{
		array = new Type[size];
		if (array == 0);
			// TODO : throw exception 'unable to allocate memory for the stack	
			
		for (int i = 0; i < array_size && i < size; i++)
			array[i] = values[i];

		this->size = size;
	}

	~FixedStack()
	{
		delete[] array;
	}

	Type top()
	{
		return array[top_index];
	}
	
	bool pop()
	{
		if (!isEmpty())
		{
			top_index--;

			return true;
		}
		else
			return false;
	}
	
	bool push(Type data)
	{
		if (!isFull())
		{
			top_index++;
			array[top_index] = data;

			return true;
		}
		else
			return false;
	}
	
	bool isEmpty()
	{
		return top_index == -1;
	}
	
	bool isFull()
	{
		return top_index >= (size - 1);
	}
};


// A dynamic size stack implemented with LinkedList
template <class Type>
class DynamicStack
{
private:
	struct Node
	{
		Node* next;
		Type data;
	};
	
	Node* top = 0;
	uint64_t size = 0;
	
public:	
	DynamicStack()
	{}

	DynamicStack(Type* values, uint64_t array_size)
	{
		Node* node = create_node(values[0]);
		top = node;
		
		for (int i = 1; i < size; i++)
		{
			// TODO : catch exception
			node->next = create_node(values[i]);
			node = node->next;
		}
	}

	~DynamicStack()
	{
		Node* to_delete = top;
		while (to_delete->next)
		{
			Node* next_to_delete = to_delete->next;
			delete to_delete;
			to_delete = next_to_delete;
		}
		// delete the last element
		delete to_delete;
	}

	Type getTop()
	{
		if (!isEmpty())
			return top->data;
		else;
			// TODO : throw exception 'trying accessing top element of an empty stack
	}

	void pop()
	{
		if (!isEmpty())
		{
			Node* new_top = top->next;
			delete top;
			top = new_top;
			size--;
		}
	}

	void push(Type data)
	{
		// TODO : catch exception
		Node* new_top = create_node(data);
		new_top->next = top;
		top = new_top;
		size++;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	uint64_t getSize()
	{
		return size;
	}

private:
	Node* create_node(uint64_t data)
	{
		Node* new_node = new Node;
		if (new_node == 0);
			// TODO : throw exception 'failed to allocate memory for the new element
		new_node->next = 0;
		new_node->data = data;
	
		return new_node;
	}
};