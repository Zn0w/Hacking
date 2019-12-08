#pragma once

#include <stdint.h>
#include <exception>


class no_pair : public std::exception
{
	virtual const char* what() const throw()
	{
		return "No such key-value pair exists";
	}
} no_pair_exception;

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
		size = reserve;
	}

	Map(Pair* pairs_array, uint32_t size)
	{
		pairs = new Pair[size];
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
	{
		int64_t index = key_exists(key);
		if (index >= 0)
			return pairs[index].value;
		else
			throw no_pair_exception;
	}

	void insert(Pair pair)
	{
		int64_t index;
		if ((index = key_exists(pair.key)) != -1)
			pairs[index].value = pair.value;
		else
		{
			top_index++;
			if (top_index == size)
			{
				// create a bigger array

				Pair* new_pairs = new Pair[size + 1];
				
				for (int i = 0; i < size; i++)
					new_pairs[i] = pairs[i];

				size++;

				delete[] pairs;
				pairs = new_pairs;
			}

			pairs[top_index] = pair;
		}
	}

	void delete_element(KeyType key)
	{
		int64_t index = key_exists(key);
		if (index >= 0)
		{
			for (int i = index; i < size - 1; i++)
				pairs[i] = pairs[i + 1];

			top_index--;
		}
		else
			throw no_pair_exception;
	}

	// if some elements were deleted, the space doesn't get freed (design choice),
	// so you can free unused space explicitly by calling this function
	void shrink()
	{
		if (top_index + 1 != size)
		{
			Pair* new_pairs = new Pair[top_index + 1];

			for (int i = 0; i <= top_index; i++)
				new_pairs[i] = pairs[i];

			size = top_index + 1;

			delete[] pairs;
			pairs = new_pairs;
		}
	}

private:
	// return index if key exists in map, -1 if not
	int64_t key_exists(KeyType key)
	{
		for (int i = 0; i <= top_index; i++)
			if (key == pairs[i].key)
				return i;

		return -1;
	}
};