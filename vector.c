// it's a slow version for now

#include <malloc.h>
#include <stdio.h>


struct VectorElement
{
	int data;
};

struct Vector
{
	unsigned int size;
	VectorElement* begin;
};
typedef struct Vector Vector;


void add(Vector* vector, VectorElement element)
{
	int new_index = vector->size
	vector->size++;
	
}

void put(Vector* vector, int index, VectorElement element)
{
	
}


int main()
{
	Vector vector;
	
	return 0;
}