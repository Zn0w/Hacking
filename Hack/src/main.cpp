#include <iostream>
#include <assert.h>

#include "library/linked_list.h"
//#include "library/stack.h"


void display_list(LinkedList<char>* linked_list)
{
	std::cout << "--------------------------------------------------" << std::endl;
	
	LinkedList<char>::iterator i = linked_list->get_iterator();
	std::cout << i.value() << std::endl;
	while (i.advance())
		std::cout << i.value() << std::endl;

	std::cout << "--------------------------------------------------" << std::endl;
}

void test_linked_list()
{
	char values[] = { 'a', 'b','c', 'd', 'e', 'f', 'g', 'h' };

	LinkedList<char> linked_list(values, 8);
	display_list(&linked_list);

	linked_list.insert_front('3');
	linked_list.insert_front('2');
	linked_list.insert_front('1');
	display_list(&linked_list);

	linked_list.insert_back('3');
	linked_list.insert_back('2');
	linked_list.insert_back('1');
	display_list(&linked_list);

	linked_list.delete_front();
	linked_list.delete_front();
	linked_list.delete_front();
	display_list(&linked_list);

	linked_list.delete_back();
	linked_list.delete_back();
	linked_list.delete_back();
	display_list(&linked_list);
}

/*void test_fixed_stack()
{
	FixedStack fixed_stack(50);

	assert(fixed_stack.isEmpty());
	assert(!fixed_stack.isFull());
	assert(!fixed_stack.pop());

	fixed_stack.push(5);
	fixed_stack.push(4);
	fixed_stack.push(3);
	fixed_stack.push(2);
	fixed_stack.push(1);

	assert(fixed_stack.top() == 1);
	fixed_stack.pop();

	assert(fixed_stack.top() == 2);
	fixed_stack.pop();

	assert(fixed_stack.top() == 3);
	fixed_stack.pop();

	assert(fixed_stack.top() == 4);
	fixed_stack.pop();

	assert(fixed_stack.top() == 5);
	fixed_stack.pop();

	assert(fixed_stack.isEmpty());

	for (int i = 0; i < 50; i++)
		assert(fixed_stack.push(i + 150));

	assert(fixed_stack.isFull());

	assert(!fixed_stack.push(1));

	for (int i = 49; i >= 0; i--)
	{
		assert(fixed_stack.top() == i + 150);
		assert(fixed_stack.pop());
	}

	assert(!fixed_stack.pop());

	assert(fixed_stack.isEmpty());
}

void test_stack()
{
	DynamicStack stack;
	assert(stack.isEmpty());

	stack.push(5);
	stack.push(4);
	stack.push(3);
	stack.push(2);
	stack.push(1);

	assert(stack.getTop() == 1);
	stack.pop();

	assert(stack.getTop() == 2);
	stack.pop();

	assert(stack.getTop() == 3);
	stack.pop();

	assert(stack.getTop() == 4);
	stack.pop();

	assert(stack.getTop() == 5);
	stack.pop();

	assert(stack.isEmpty());

	for (int i = 0; i < 100; i++)
		stack.push(i);

	assert(stack.getTop() == 99);
	assert(stack.getSize() == 100);
}*/

int main()
{
	test_linked_list();

	system("pause");
	
	return 0;
}