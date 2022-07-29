
#include "Circular_Linked_List.h"
#include "Sparse_Matrix.h"
#include <stdio.h>


void Init_Matrix(Matrix *mat,int width, int height)
{
	mat-> wList = (LinkedList*)malloc(sizeof(LinkedList) * width);
	
	for (int i = 0; i<width;i++)
	{ 
	Listinit((mat->wList)+i);
	}
	mat -> hList = (LinkedList*)malloc(sizeof(LinkedList) * height);
	for (int i = 0; i < height; i++)
	{
		Listinit((mat->hList) + i);
	}
}

void Matrix_insert(int row, int column, char data, Matrix* mat)
{
	NodeMatrix* newNode = (NodeMatrix*)malloc(sizeof(NodeMatrix));

	newNode->data = data; 
	newNode->NextNode = NULL; 

	if (mat->wList[column].nHead == NULL)
	{
		mat->wList[column].nHead = newNode;
		mat->wList[column].nHead->NextNode = mat->wList[column].nHead;
	}
	else
	{
		mat->wList[column].nCurrent = mat->wList[column].nHead;
		while (mat->wList[column].nCurrent->NextNode != mat->wList[column].nHead)
		{
			mat->wList[column].nCurrent = mat->wList[column].nCurrent->NextNode;
		}
		mat->wList[column].nCurrent->NextNode = newNode;
		mat->wList[column].nTail = newNode;
		newNode->NextNode = mat->wList[column].nHead;
	}


	if (mat->hList->nHead == NULL)
	{
		mat->hList->nHead = newNode;
		mat->hList->nHead->NextNode = mat->hList->nHead;
	}

	else
	{
		mat->hList[row].nCurrent = mat->hList[row].nHead;
		while (mat->hList[row].nCurrent->NextNode != mat->hList[row].nHead)
		{
			mat->hList[row].nCurrent = mat->hList[row].nCurrent->NextNode;
		}
		mat->hList[row].nCurrent->NextNode = newNode;
		mat->hList[row].nTail = newNode;
		newNode->NextNode = mat->hList[column].nHead;
	}

	mat->hList[row].size++;
	mat->wList[column].size++;
}
	
