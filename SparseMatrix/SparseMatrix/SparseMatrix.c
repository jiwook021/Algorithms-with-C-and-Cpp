#include "SparseMatrix.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void InitMatrix(SparseMatrix* mat, int height, int width)
{
	mat->wList = (LinkedList*)malloc(sizeof(LinkedList) * width);

	for (int i = 0; i < width; i++)
	{
		InitList((mat->wList) + i);
	}
	mat->hList = (LinkedList*)malloc(sizeof(LinkedList) * height);
	for (int i = 0; i < height; i++)
	{
		InitList((mat->hList) + i);
	}
}


void MatInsert(SparseMatrix* mat, char data, int row, int col)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	LNInsert(&(mat->hList[row]), newNode, data);
	LBInsert(&(mat->wList[col]), newNode, data);
}



void MatDelete(SparseMatrix* mat, char data, int row)
{
	for (int i = 0; i <= row; i++)
	{
		NodeDelete(&(mat->hList[i]), data);
	}
}



void printMatrix(SparseMatrix* mat, int row, int col)
{
	mat->hList[row].current = mat->hList[row].head;

	printf("Matrix\n\n");

	for (int j = 1; j <= row; j++)
	{
		printf("\nrow %d: ", j);

		for (int i = 0; i < mat->hList[j].size; i++)
		{
			printf("%c ", mat->hList[j].current->data);
			mat->hList[j].current = mat->hList[j].current->next;
		}
	}
	printf("\n");
}



void printMat(SparseMatrix* mat, int row, int col)
{
	for (int i = 1; i<=row;i++)
	{
		if (mat->hList[i].size == 0) continue;
		
		printRow(mat, i);

	}
	printf("\n\n");
	for (int j = 1; j <= col; j++)
	{

		if (mat->wList[j].size == 0) continue;

		printCol(mat, j);
	}
}


void printRow(SparseMatrix* mat, int row)
{
	mat->hList[row].current = mat->hList[row].head;

	printf("Matrix row %d: ", row);

	for (int i = 0; i < mat->hList[row].size; i++)
	{
		printf("%c ", mat->hList[row].current->data);
		mat->hList[row].current = mat->hList[row].current->next;
	}
	printf("\n");
}

void printCol(SparseMatrix* mat, int col)
{
	mat->wList[col].current = mat->wList[col].head;

	printf("Matrix column %d: ", col);

	for (int i = 0; i < mat->wList[col].size; i++)
	{
		printf("%c ", mat->wList[col].current->data);
		mat->wList[col].current = mat->wList[col].current->below;
	}

	printf("\n");
}
