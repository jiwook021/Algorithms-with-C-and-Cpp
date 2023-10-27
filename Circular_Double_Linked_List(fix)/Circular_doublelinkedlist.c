#include "Circular_doublelinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void vInsert(int data) {
	Node* newNode = (Node*) malloc(sizeof(Node)); // Allocate size of node to newNode; 


	newNode->data = data; //insert data
	newNode->next = NULL;
	newNode->previous = NULL;

	Node* current = head;
	if (head == NULL)
	{
		head = newNode;
		head-> previous = head;
		head-> next = head;
	}
	else
	{
		while (current->next != head && current->next != NULL)
		{
			current = current->next;
		}	
		current->next = newNode; //put the node at the head
		newNode->previous = current;
	
		head->previous = newNode;
		newNode->next = head;
		
	}
	printf("Inserted %d on head\t",newNode->data);
	size++; //add size
}


void vRemove(int data)
{
	if (head == NULL) return;
	Node* current = head;
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
				printf("Deleted %d ",data);
				return;
			}
			
		}
	}
	else 
	{
		head = head->next;
		free(nPrev);
		size--;
		printf("Deleted %d ",data);
		return;
	}
}


void vSearch(int data)
{
	uint8_t check = 0; 
	Node* current = head;

	if (current == NULL)
	{
		printf("\nEmpty List\n");
	}

	int i;
	for (i = 0; i < size; i++)
	{
		current = current->next;
		if (data == current->data) 
		{
			printf("found :%d\n", current->data);
			check = 1;
		}
	}

	if (check == 0)
	{
		printf("Did not Found :%d\n", data);
	}
}

void vPrint()
{
	printf("\n");
	Node* current = head;
	for (int i = 0; i < size; i++)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}
