#define _CRT_SECURE_NO_WARNINGS
#include "Linked_List.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList::LinkedList()
	: nHead(NULL), nTail(NULL), nCurrent(NULL), size(0)
{ }


void LinkedList::vInsertion(int iData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->iData = iData;
	newNode->NextNode = NULL;

	if (nHead == NULL)
	{
		nHead = newNode;
	}
	else
	{
		nTail->NextNode = newNode;
	}

	nTail = newNode;
	this->size++;
}


void LinkedList::vInsertion(int iData, int iSeq)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->iData = iData;
	newNode->NextNode = NULL;

	nCurrent = nHead;
	for (int i = 0; i < (iSeq - 2); i++)
	{
		nCurrent = nCurrent->NextNode;
	}

	newNode->NextNode = nCurrent->NextNode;
	nCurrent->NextNode = newNode;

	nTail = newNode;
	this->size++;
}

void LinkedList::vRemove(int iData)
{
	if (nHead == NULL) return;

	nCurrent = nHead;
	Node* nPrev = nHead;

	if (!(iData == (nHead->iData)))
	{
		for (int i = 0; i < this->size; i++)
		{
			nPrev = nCurrent;
			nCurrent = nCurrent->NextNode;


			if (nCurrent == NULL)
			{
				printf("Cannot found %d\n", iData);
				return;
			}
			if (iData == (nCurrent->iData))
			{
				nPrev->NextNode = nCurrent->NextNode;
				free(nCurrent);
				this->size--;
				return;
			}


		}
	}
	else
	{
		nHead = nHead->NextNode;
		free(nPrev);
		this->size--;
		return;
	}

}

void LinkedList::vSearch(int iData)
{
	nCurrent = nHead;

	for (int i = 0; i < this->size; i++)
	{
		if (iData == nCurrent->iData)
			printf("Found %d\n", iData);
		nCurrent = nCurrent->NextNode;
	}
}


void LinkedList::vPrint()
{
	nCurrent = nHead;

	for (int i = 0; i < this->size; i++)
	{
		printf(("%d\n"), nCurrent->iData);
		nCurrent = nCurrent->NextNode;
	}
}
