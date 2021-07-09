#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
	int data;
	struct LinkedList *link;
}LinkedList;

void print(LinkedList **first)
{
	LinkedList *temp = *first;
	printf("\n");
	if(temp == NULL)
		printf("NULL");
	else
	{
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->link;
		}
	}
}

void add_at_end(int n, LinkedList **first)
{
	LinkedList *node, *temp;
	node = (LinkedList *)malloc(sizeof(LinkedList));
	if(node == NULL)
		exit(0);
	node->link = NULL;
	node->data = n;
	if (*first == NULL)
		*first = node;
	else
	{
		temp = *first;
		while(temp->link != NULL)
			temp = temp->link;
		temp->link = node;
	}
}

void delete_at_end(LinkedList **first)
{
	LinkedList *temp, *node;
	temp = *first;
	while(temp != NULL)
	{
		if(temp->link->link == NULL)
		{
			node = temp->link->link;
			free(node);
			temp->link = NULL;
		}
		temp = temp->link;
	}
}

void add_at_start(int n, LinkedList **first)
{
	LinkedList *node;
	node = (LinkedList *)malloc(sizeof(LinkedList));
	if(node == NULL)
		exit(0);
	node->data = n;
	node->link = *first;
	*first = node;
}

void delete_at_start(LinkedList **first)
{
	LinkedList *temp = *first;
	*first = temp->link;
	temp->link = NULL;
	free(temp);
}

int linked_list_length(LinkedList **first)
{
	int length = 0;
	LinkedList *temp;
	temp = *first;
	while(temp != NULL)
	{
		length++;
		temp = temp->link;
	}
	return(length);
}

void add_at_position(int n, LinkedList **first, int pos)
{
	LinkedList *node, *temp = *first;
	int cnt = 0;
	int length = linked_list_length(&temp) + 1;
	if(pos > length)
		printf("\nIndex out of range");
	else
	{
		if(pos == 0)
			add_at_start(n, first);
		else if(pos == length)
			add_at_end(n, first);
		else
		{
			temp = *first;
			while(temp != NULL)
			{
				if(pos - 1 == cnt)
				{
					node = (LinkedList *)malloc(sizeof(LinkedList));
					if(node == NULL)
						exit(0);
					node->data = n;
					node->link = temp->link;
					temp->link = node;
					break;
				}
				cnt++;
				temp = temp->link;
			}
		}
	}
}

void delete_at_position(LinkedList **first, int pos)
{
	LinkedList *temp = *first, *node;
	int cnt = 0;
	int length = linked_list_length(&temp) - 1;
	if(pos > length)
		printf("\nIndex out of range");
	else
	{
		if(pos == 0)
			delete_at_start(first);
		else if(pos == length)
			delete_at_end(first);
		else
		{
			while(temp != NULL)
			{
				if(pos - 1 == cnt)
				{
					node = temp->link;
					temp->link = node->link;
					free(node);
					break;
				}
				cnt++;
				temp = temp->link;
			}
		}
	}
}

int search_node(LinkedList **first, int n)
{
	LinkedList *temp = *first;
	while(temp != NULL)
	{
		if(temp->data == n)
			return 1;
		temp = temp->link;
	}
	return 0;
}

int get_node(LinkedList **first, int pos)
{
	int n, count = 0;
	LinkedList *temp = *first;
	int length = linked_list_length(&temp) - 1;
	if(pos > length)
		return NULL;
	if (pos == 0)
		return temp->data;
	while(temp != NULL)
	{
		if(pos == count)
			return temp->data;
		temp = temp->link;
		count++;
	}
	return NULL;
}

void delete_all(LinkedList **first)
{
	LinkedList *temp = *first, *node;
	while(temp != NULL)
	{
		node = temp;
		temp = temp->link;
		free(node);
	}
	free(temp);
	*first = NULL;
}

LinkedList *merge(LinkedList *a, LinkedList *b)
{
	LinkedList *node = NULL;
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	if(a->data <= b->data)
	{
		node = a;
		node->link = merge(a->link, b);
	}
	else
	{
		node = b;
		node->link = merge(a, b->link);
	}
	return node;
}

void split(LinkedList *src, LinkedList **front, LinkedList **back)
{
	LinkedList *a, *b;
	b = src;
	a = src->link;
	while(a != NULL)
	{
		a = a->link;
		if(a != NULL)
		{
			b = b->link;
			a = a->link;
		}
	}
	*front = src;
	*back = b->link;
	b->link = NULL;
}

void sort_linked_list(LinkedList **first)
{
	LinkedList *temp = *first, *a, *b;
	if(temp == NULL || temp->link == NULL)
		return;
	split(temp, &a, &b);
	sort_linked_list(&a);
	sort_linked_list(&b);
	*first = merge(a, b);
}

LinkedList *merger(LinkedList *a, LinkedList *b)
{
	LinkedList *node = NULL;
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	if(a->data > b->data)
	{
		node = a;
		node->link = merger(a->link, b);
	}
	else
	{
		node = b;
		node->link = merger(a, b->link);
	}
	return node;
}

void reverse_linked_list(LinkedList **first)
{
	LinkedList *temp = *first, *a, *b;
	if(temp == NULL || temp->link == NULL)
		return;
	split(temp, &a, &b);
	reverse_linked_list(&a);
	reverse_linked_list(&b);
	*first = merger(a, b);
}