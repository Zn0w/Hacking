#pragma once

#include <stdint.h>
#include <stdlib.h>


struct Pair
{
	uint64_t key;
	int64_t data;
};

struct Node
{
	Node* next;
	Pair data;
};

// TODO : maybe use LinkedList from my library ???, but first use implement templates in LinkedList
class Map
{
private:
	Pair pairs;

public:
	Map()
	{}

	Map(Pair* pairs_array, uint64_t size)
	{}
	
	~Map()
	{}

	int64_t get(uint64_t key)
	{}

	void insert(Pair pair)
	{}

private:
	Node* create_node(Pair pair)
	{}
};