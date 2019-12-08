#pragma once

#include <stdint.h>
#include <exception>


class invalid_index : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Object of that index doesn't exist";
	}
} invalid_index_exception;

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
		values = new Type[reserve];
		size = reserve;
	}

	Vector(Type* data_array, uint64_t size)
	{
		values = new Type[size];
		this->size = size;
		top_index = size - 1;

		for (int i = 0; i < size; i++)
			values[i] = data_array[i];
	}

	~Vector()
	{
		delete[] values;
	}

	void insert(Type value)
	{
		top_index++;
		if (top_index == size)
		{
			// create a bigger array

			Type* new_values = new Type[size + 1];

			for (int i = 0; i < size; i++)
				new_values[i] = values[i];

			size++;

			delete[] values;
			values = new_values;
		}

		values[top_index] = value;
	}

	Type get(uint64_t index)
	{
		if (index <= top_index)
			return values[index];
		else
			throw invalid_index_exception;
	}

	void delete_element(uint64_t index)
	{
		if (index <= top_index)
		{
			for (int i = index; i < size - 1; i++)
				values[i] = values[i + 1];

			top_index--;
		}
		else
			throw invalid_index_exception;
	}
};