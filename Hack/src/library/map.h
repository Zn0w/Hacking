#pragma once

#include <stdint.h>


template <class KeyType, class ValueType>
class Map
{
public:
	struct Pair
	{
		KeyType key;
		ValueType value;
	};

private:
	Pair* pairs = 0;
	int64_t top_index = -1;
	uint32_t size = 0;

public:
	Map(uint32_t reserve)
	{
		pairs = new Pair[reserve];
		if (pairs == 0);
			// throw exception
		size = reserve;
	}

	Map(Pair* pairs_array, uint32_t size)
	{
		pairs = new Pair[size];
		if (pairs == 0);
			// throw exception
		this->size = size;
		top_index = size - 1;

		for (int i = 0; i < size; i++)
			pairs[i] = pairs_array[i];
	}
	
	~Map()
	{
		delete[] pairs;
	}

	ValueType get(KeyType key)
	{}

	void insert_back(Pair pair)
	{
		if (top_index == max_size)
		{
			// reallocate array with bigger one
			// if success then size++;
		}
		
		top_index++;
		pairs[top_index] = pair;
	}

	void delete_element(KeyType key, bool adjust_size)
	{}
};