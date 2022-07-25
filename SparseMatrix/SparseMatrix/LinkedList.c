#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void InitList(LinkedList* list)
{
	list->size = 0; 
	list->head = NULL;
}

void LNInsert(LinkedList* list, Node *newNode, char data)
{
	
	newNode->data = data;
	newNode->next = NULL;
	
	if (list->head == NULL)
	{
		list->head = newNode;
		list->head->next = list->head;
	}
	else
	{
		list->current = list->head;
		while (list->current->next != list->head)
		{
			list->current = list->current->next;
		}
		list->current->next = newNode;
		newNode->next = list->head;
	}
	list->size++;
}

void LBInsert(LinkedList* list, Node* newNode, char data)
{
	newNode->below = NULL;

	if (list->head == NULL)
	{
		list->head = newNode;
		list->head->below = list->head;
	}
	else
	{
		list->current = list->head;
		while (list->current->below != list->head)
		{
			list->current = list->current->below;
		}
		list->current->below = newNode;
		newNode->below = list->head;
	}
	list->size++;
}


void NodeDelete(LinkedList* list, char data)
{
	if (list->head == NULL) return;
	list->current = list->head;
	Node* nPrev = list->head;

	if (!(data == (list->head->data)))
	{
		for (int i = 0; i < list->size; i++)
		{
			
			nPrev = list->current;

			list->current = list->current->next;


			if (list->current == NULL)
			{
				printf("\nCannot found %d\n", data);
				return;
			}
			if (data == list->current->data)
			{
				nPrev->next = list->current->next;
				free(list->current);
				list->size--;
				return;
			}
		}
	}
	else
	{
		list->head = list->head->next;
		free(nPrev);
		list->size--;
		return;
	}
}


