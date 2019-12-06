#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <type_traits>


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
		pairs = (Pair*)calloc(reserve, sizeof(Pair));
		if (pairs == 0);
			// throw exception
		size = reserve;
	}

	Map(Pair* pairs_array, uint32_t size)
	{
		pairs = (Pair*)calloc(size, sizeof(Pair));
		if (pairs == 0);
			// throw exception
		this->size = size;
		top_index = size - 1;

		for (int i = 0; i < size; i++)
			pairs[i] = pairs_array[i];
	}
	
	~Map()
	{
		// For now destructor calls for ValueType are not supported

		free(pairs);
		
		/*for (int i = 0; i < size; i++)
		{
			if (!std::is_pod<ValueType>::value)
				pairs[i].value.~ValueType();
			free(pairs + i);
		}*/
	}

	ValueType get(KeyType key)
	{
		int64_t index = key_exists(key);
		if (index >= 0)
			return pairs[index].value;
		else;
			// if key doesn't exist throw exception
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
				// reallocate array with bigger one
				// if success then size++;

				Pair* new_pairs = (Pair*)calloc(size + 1, sizeof(Pair));
				if (pairs == 0);
					// throw exception
				
				for (int i = 0; i < size; i++)
					new_pairs[i] = pairs[i];

				size++;

				free(pairs);
				pairs = new_pairs;
			}

			pairs[top_index] = pair;
		}
	}

	void delete_element(KeyType key, bool adjust_size)
	{}

private:
	// return index if key exists in map, -1 if not
	int64_t key_exists(KeyType key)
	{
		for (int i = 0; i < top_index; i++)
			if (key == pairs[i].key)
				return i;

		return -1;
	}
};