#ifndef B574EB13_2094_4237_9BC9_7AEFD701E143
#define B574EB13_2094_4237_9BC9_7AEFD701E143
#pragma once

#ifndef __SPARSE_MATRIX_H__
#define __SPARSE_MATRIX_H__

#include "Circular_Linked_List.h"



typedef struct Matrix {
	LinkedList* wList;
	LinkedList* hList;
}Matrix;


void Init_Matrix(int width, int height);
void Matrix_insert(int row, int column, char data, LinkedList* list);
char Matsearch()


#endif 


#endif /* B574EB13_2094_4237_9BC9_7AEFD701E143 */
