#define _CRT_SECURE_NO_WARNINGS
#include "Circular_Linked_List.h"
#include <stdio.h>
#include <stdlib.h>

void Listinit(LinkedList* L1)
{
	L1->nCurrent = NULL;
	L1-> nTail= NULL;
	L1->nHead = NULL;
	L1->size = 0; 
}

void vInsertion(int iData,LinkedList* L1)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = iData;
	newNode->NextNode = NULL;

	if (L1->nHead == NULL)
	{
		L1->nHead = newNode;
		L1->nHead->NextNode = L1->nHead;
	}
	else
	{
		L1->nCurrent = L1->nHead;
		while (L1->nCurrent->NextNode != L1->nHead)
		{
			L1->nCurrent = L1->nCurrent->NextNode;
		}
		L1->nCurrent->NextNode = newNode;
		L1->nTail = newNode;
		newNode->NextNode = L1->nHead;
	}
	L1->size++;
}


void vInsertion2(int iData, int iSeq,LinkedList* L1)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = iData;
	newNode->NextNode = NULL;

	L1->nCurrent = L1->nHead;
	for (int i = 0; i < (iSeq - 2); i++)
	{
		L1->nCurrent = L1->nCurrent->NextNode;
	}

	newNode->NextNode = L1->nCurrent->NextNode;
	L1->nCurrent->NextNode = newNode;

	L1->nTail = newNode;
	L1->size++;
}

void vRemove(int iData,LinkedList* L1)
{
	if (L1->nHead == NULL) return;
	if (L1->size == 0) return;

	L1->nCurrent = L1->nHead;
	Node* nPrev = L1->nHead;

	if (!(iData == (L1->nHead->data)))
	{
		int i;
		for (i = 0; i < L1->size; i++)
		{
			nPrev = L1->nCurrent;
		
			L1->nCurrent = L1->nCurrent->NextNode;
			
			if (L1->nCurrent == NULL)
			{
				printf("Cannot found %d\n", iData);
				return;
			}
			if (iData == (L1->nCurrent->data))
			{
				nPrev->NextNode = L1->nCurrent->NextNode;
				free(L1->nCurrent);
				L1->size--;
				return;
			}
		}
	}
	else
	{
		L1->nHead = L1->nHead->NextNode;
		L1->nTail->NextNode = L1->nHead; 
		free(nPrev);
		L1->size--;
		return;
	}

}

void vSearch(int iData,LinkedList* L1)
{
	L1->nCurrent = L1->nHead;

	for (int i = 0; i < L1->size; i++)
	{
		if (iData == L1->nCurrent->data)
			printf("Found %d\n", iData);
		L1->nCurrent = L1->nCurrent->NextNode;
	}
}


void vPrint(LinkedList* L1)
{
	L1->nCurrent = L1->nHead;

	for (int i = 0; i < L1->size; i++)
	{
		printf(("%d\n"), L1->nCurrent->data);
		L1->nCurrent = L1->nCurrent->NextNode;
	}
}
