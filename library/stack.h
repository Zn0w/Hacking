#pragma once

#include <stdint.h>
#include <stdlib.h>

class FixedStack
{
private:
	uint32_t size = 0;
	int64_t top_index = -1;
	int64_t* array = 0;
	
public:
	FixedStack(uint32_t size)
	{
		array = (int64_t*)calloc(size, sizeof(int64_t));
		if (array == 0);
			// TODO : throw exception or something
		this->size = size;
	}

	FixedStack(uint32_t size, int64_t* values, uint32_t array_size)
	{
		array = (int64_t*)calloc(size, sizeof(int64_t));
		if (array == 0);
			// TODO : throw exception 'unable to allocate memory for the stack	
			
		for (int i = 0; i < array_size && i < size; i++)
			array[i] = values[i];

		this->size = size;
	}

	~FixedStack()
	{
		free(array);
	}

	uint64_t top()
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
	
	bool push(uint64_t data)
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