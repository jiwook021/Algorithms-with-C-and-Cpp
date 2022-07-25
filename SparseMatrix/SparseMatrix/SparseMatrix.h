#ifndef __SPARSE_MATRIX_H__
#define __SPARSE_MATRIX_H__

#include "LinkedList.h"

typedef struct _sparseMatrix
{
	LinkedList* wList;
	LinkedList* hList;
} SparseMatrix;

void InitMatrix(SparseMatrix* mat, int height, int width);
void MatInsert(SparseMatrix* mat, char data, int row, int col);
//char Matsearch(SparseMatrix* mat, int row, int col);
void printMat(SparseMatrix* mat, int row, int col);
void printRow(SparseMatrix* mat, int row);
void printCol(SparseMatrix* mat, int col);
void MatDelete(SparseMatrix* mat, char data, int row);
void printMatrix(SparseMatrix* mat, int row, int col);

#endif