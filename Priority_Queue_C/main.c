#include "Priority_Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int main()
{
	//for random generation
 	time_t t;
   	srand((unsigned) time(&t));

	heap heap;
	heapInit(&heap);
	static const uint8_t size = 20; 
	for(uint8_t i =0; i < size; i++)
    {
		HInsert(&heap,rand() % 100, rand() % 20);
    }
	printf("\n\n======================================================Print heap======================================================\n\n");
	while (!HIsEmpty(&heap))
		printf("%d  ", Hdelete(&heap));
		
	printf("\n");
	return 0; 
}