#pragma once

#include <stdint.h>
#include <stdlib.h>


template <class Type>
class Vector
{
private:
	Type* values = 0;
	int64_t top_index = -1;
	uint32_t size = 0;

public:
	Vector(uint64_t reserve)
	{
		values = (Type*)calloc(reserve, sizeof(Type));
		if (values == 0);
		// throw exception
		size = reserve;
	}

	Vector(Type* data_array, uint64_t size)
	{
		values = (Type*)calloc(size, sizeof(Type));
		if (values == 0);
		// throw exception
		this->size = size;
		top_index = size - 1;

		for (int i = 0; i < size; i++)
			values[i] = data_array[i];
	}

	~Vector()
	{
		// For now destructor calls for ValueType are not supported

		free(values);
	}

	void insert(Type value)
	{
		top_index++;
		if (top_index == size)
		{
			// reallocate array with bigger one
			// if success then size++;

			Type* new_values = (Type*)calloc(size + 1, sizeof(Type));
			if (new_values == 0);
			// throw exception

			for (int i = 0; i < size; i++)
				new_values[i] = values[i];

			size++;

			free(values);
			values = new_values;
		}

		values[top_index] = value;
	}

	Type get(uint64_t index)
	{
		if (index <= top_index)
			return values[index];
		else;
		// object doesn't exist, throw exception
	}

	void delete_element(uint64_t index)
	{
		if (index <= top_index)
		{
			for (int i = index; i < size - 1; i++)
				values[i] = values[i + 1];

			top_index--;
		}
		else;
		// object doesn't exist, throw exception
	}
};