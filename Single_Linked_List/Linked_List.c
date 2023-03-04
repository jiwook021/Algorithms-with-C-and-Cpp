
#include "Linked_List.h"

void initLinkedList(struct LinkedList* pthis)
{
	pthis-> nHead = NULL; 
	pthis-> nTail = NULL;
	pthis-> nCurrent = NULL; 
	pthis-> size=0;
	pthis-> init = true; 
}

bool vInsertion(int iData,struct LinkedList* pthis)
{
	if(pthis->init==false) 
		return false; 

	Node* newNode = (Node*)malloc(sizeof(Node));
	if(NULL==newNode)
		return false;

	newNode->iData = iData;
	newNode->NextNode = NULL;

	if (pthis->nHead == NULL)
	{
		pthis-> nHead = newNode;
	}
	else
	{
		pthis->nTail->NextNode = newNode;
	}

	pthis->nTail = newNode;
	pthis->size++;
	return true;
}


bool vInsertionMid(int iData, int iSeq,struct LinkedList* pthis)
{
	if(pthis->init==false) 
		return false; 

	Node* newNode = (Node*)malloc(sizeof(Node));
	if(NULL==newNode)
		return false;

	newNode->iData = iData;
	
	pthis->nCurrent = pthis->nHead;
	for (int i = 0; i < (iSeq - 1); i++)
	{
		pthis->nCurrent = pthis->nCurrent->NextNode;
	}

	newNode->NextNode = pthis->nCurrent->NextNode;
	pthis->nCurrent->NextNode = newNode;
	pthis->size++;
	return true;
}

bool vRemove(int iData,struct LinkedList* pthis)
{
	if(pthis->init==false) 
		return false; 

	if (pthis->nHead == NULL) 
		return false;

	pthis->nCurrent = pthis->nHead;	
	Node* nPrev = pthis->nHead;

	if (!(iData == (pthis->nHead->iData)))
	{
		for (int i = 0; i < pthis->size; i++)
		{
			nPrev = pthis->nCurrent;
			pthis->nCurrent = pthis->nCurrent->NextNode;

			if (pthis->nCurrent == NULL)
			{
				printf("Cannot found %d\t", iData);
				return true;
			}
			if (iData == (pthis->nCurrent->iData))
			{
				nPrev->NextNode = pthis->nCurrent->NextNode;
				free(pthis->nCurrent);
				pthis->nCurrent = NULL;
				pthis->size--;
				printf("Deleted %d\t", iData);
				return true;
			}
		}
	}
	else
	{
		pthis->nHead = pthis->nHead->NextNode;
		free(pthis->nCurrent);
		pthis->nCurrent = NULL;
		pthis->size--;
		return true;
	}
}

void vSearch(int iData,struct LinkedList* pthis)
{
	pthis->nCurrent = pthis->nHead;
	bool check = false; 
	for (int i = 0; i < pthis->size; i++)
	{
		if (iData == pthis->nCurrent->iData)
		{
			printf("Found %d at index %d\t", iData, i+1);
			check = true; 
			return;
		}
		pthis->nCurrent = pthis->nCurrent->NextNode;
	}
	if (check == false)
	{
		printf("Can't find %d\t", iData);
	}
}

void vsort_single_linked_list(struct LinkedList* pthis)
{
	int temp;
	pthis->nCurrent = pthis->nHead;
	for (int i = 0; i < pthis->size; i++)
	{
		for (int j = 0; j < pthis->size - i - 1; j++)
		{
			if (pthis->nCurrent->iData > pthis->nCurrent->NextNode->iData)
			{
				temp = pthis->nCurrent->iData;
				pthis->nCurrent->iData = pthis->nCurrent->NextNode->iData;
				pthis->nCurrent->NextNode->iData = temp;
			}
			pthis->nCurrent = pthis->nCurrent->NextNode;
		}
		pthis->nCurrent = pthis->nHead;
	}
}


void vPrint(struct LinkedList* pthis)
{
	pthis->nCurrent = pthis->nHead;

	printf("\n");
	for (int i = 0; i < pthis->size; i++)
	{
		printf(("%d "), pthis->nCurrent->iData);
		pthis->nCurrent = pthis->nCurrent->NextNode;
	}
	printf("\n");
}
