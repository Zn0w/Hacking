#include <malloc.h>
#include <stdio.h>


struct Node
{
	struct Node* next;
	int data;
};
typedef struct Node Node;


Node* begin = 0;
Node* latest = 0;


void insert(Node* new_node)
{
	if (begin == 0)
	{
		begin = new_node;
		begin->next = 0;
		latest = begin;
		return;
	}
	
	latest->next = new_node;
	latest = new_node;
}

void delete(unsigned int index)
{
	if (begin == 0)
	{
		printf("There are not any elements in the linked list yet\n");
		return;
	}
	else if (index == 0)
	{
		Node* new_begin = begin->next;
		free(begin);
		begin = new_begin;
		return;
	}

	Node* current_node = begin;
	for (int i = 0; i < index - 1 && current_node->next; i++)
		current_node = current_node->next;

	if (current_node->next == 0)
	{
		printf("There is no element with this index\n");
		return;
	}
	
	Node* node = current_node->next->next;
	free(current_node->next);
	current_node->next = node;
}

void at(unsigned int index)
{
	if (begin == 0)
	{
		printf("There are not any elements in the linked list yet\n");
		return;
	}
	
	Node* current_node = begin;
	int i;
	for (i = 0; i < index && current_node->next; i++)
		current_node = current_node->next;

	printf("index\taddress\tnext\tdata\n\n");
	printf("%d\t%d\t%d\t%d\n", i, current_node, current_node->next, current_node->data);
}

void display_all()
{
	if (begin == 0)
	{
		printf("There are not any elements in the linked list yet\n");
		return;
	}

	Node* current_node = begin;

	printf("index\taddress\tnext\tdata\n\n");
	int i = 0;
	while (current_node->next)
	{
		printf("%d\t%d\t%d\t%d\n", i, current_node, current_node->next, current_node->data);

		current_node = current_node->next;

		i++;
	}
	// print the latest one
	printf("%d\t%d\t%d\t%d\n", i, current_node, current_node->next, current_node->data);
}

int main()
{
	// I will assume that all the malloc calls will be successful
	int option = 1;
	while (option >= 1 && option <= 4)
	{
		printf("\n\n1 - Insert\n2 - Delete\n3 - Display\n4 - Display all\n<any> - Exit\n\n$");
		scanf("%d", &option);

		switch (option)
		{
			case 1 : {
				int data;
				scanf("%d", &data);
				Node* node = malloc(sizeof(Node));
				node->next = 0;
				node->data = data;
				insert(node);
			} break;

			case 2 : {
				int index;
				scanf("%d", &index);
				delete(index);
			} break;

			case 3 : {
				int index;
				scanf("%d", &index);
				at(index);
			} break;

			case 4 :
				display_all();
				break;

			default :
				printf("Exiting the program\n");
				break;
		}
	}
	
	return 0;
}