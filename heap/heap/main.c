#include "heap.h"
#include <stdio.h>

int main()
{
	heap heap;
	heapInit(&heap);

	HInsert(&heap, 1, 1);
	HInsert(&heap, 4, 2);
	HInsert(&heap, 7, 3);
	HInsert(&heap, 8, 4);
	HInsert(&heap, 9, 5);
	HInsert(&heap, 12, 6);
	HInsert(&heap, 13, 7);
	HInsert(&heap, 15, 8);
	HInsert(&heap, 3, 9);


	while (!HIsEmpty(&heap))
		printf("%d \n", Hdelete(&heap));

	return 0; 
}