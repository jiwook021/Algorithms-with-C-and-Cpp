#include "Circular_doublelinkedlist.h"
#include <stdio.h>
#include <stdlib.h>


void insert(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = NULL;
	newNode->previous = NULL;

	if (head == NULL)
	{
		head = newNode;
		head->previous = head;
		head->next = head;
	}
	else
	{
		current = head;
		while (current->next != head)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->previous = current;
		head->previous = newNode;
		newNode->next = head;
	}
	size++;
}


void vRemove(int data)
{
	if (head == NULL) return;
	current = head;
	Node* nPrev = head;

	if (!(data == (head->data)))
	{
		for (int i = 0; i < size; i++)
		{
			current = current->next;
			if (current == NULL)
			{
				printf("Cannot found %d\n", data);
				return;
			}
			if (data == current->data)
			{
				current->previous->next = current->next;
				current->next->previous = current->previous;
				free(current);
				size--;
				return;
			}
		}
	}
	else 
	{
		head = head->next;
		free(nPrev);
		size--;
		return;
	}
}


void search(int data)
{
	current = head;
	if (current == NULL)
	{
		printf("\nEmpty List\n");
	}

	for (int i = 0; i < size; i++)
	{
		current = current->next;

		if (data == current->data) 
			printf("found :%d\n", data);
	}
}

void print()
{
	current = head;
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}
