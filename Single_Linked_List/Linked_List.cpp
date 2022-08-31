#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include "Linked_List.hpp"

LinkedList::LinkedList()
	: nHead(NULL), nTail(NULL), nCurrent(NULL), size(0)
{ }


void LinkedList::vInsertion(int iData)
{
	std::shared_ptr<Node> newNode(new Node());

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
	std::shared_ptr<Node> newNode(new Node());
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
	std::shared_ptr<Node> nPrev = nHead;

	if (!(iData == (nHead->iData)))
	{
		for (int i = 0; i < this->size; i++)
		{
			nPrev = nCurrent;
			nCurrent = nCurrent->NextNode;


			if (nCurrent == NULL)
			{
				printf("Cannot found %d\t", iData);
				return;
			}
			if (iData == (nCurrent->iData))
			{
				nPrev->NextNode = nCurrent->NextNode;
				//free(nCurrent);
				this->size--;
				printf("Deleted %d\t", iData);
				return;
			}


		}
	}
	else
	{
		nHead = nHead->NextNode;
		//free(nPrev);
		this->size--;
		return;
	}

}

void LinkedList::vSearch(int iData)
{
	nCurrent = nHead;
	bool check = false; 
	for (int i = 0; i < this->size; i++)
	{
		if (iData == nCurrent->iData)
		{
			printf("Found %d\t", iData);
			check = true; 
			return;
		}
		nCurrent = nCurrent->NextNode;
	}
	if (check == false)
	{
		printf("Can't find %d\t", iData);
	}
}


void LinkedList::vPrint()
{
	nCurrent = nHead;

	for (int i = 0; i < this->size; i++)
	{
		printf(("%d "), nCurrent->iData);
		nCurrent = nCurrent->NextNode;
	}
	printf("\n");
}
