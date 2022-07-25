#include <stdio.h>
#include <stdlib.h>
#include "SparseMatrix.h"
#include "LinkedList.h"

int main()
{
	SparseMatrix mat;
	InitMatrix(&mat, 100, 100);

	//void MatInsert(SparseMatrix* mat, char data, int row, int col)
	MatInsert(&mat, 'a', 1, 2);
	MatInsert(&mat, 'b', 2, 3);
	MatInsert(&mat, 'c', 1, 3);
	MatInsert(&mat, 'd', 2, 2);
	MatInsert(&mat, 'e', 2, 9);
	MatInsert(&mat, 'f', 9, 2);

	//MatDelete(&mat, 'd', 8);

	printMatrix(&mat, 9, 9);
	return 0;
}