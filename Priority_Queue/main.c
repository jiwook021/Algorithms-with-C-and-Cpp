#include "Priority_Queue.h"
#include <stdio.h>
#include <time.h>
#include <stdint.h>

int main()
{
	heap heap;
	heapInit(&heap);

	//for random generation
 	time_t t;
   	srand((unsigned) time(&t));

	const uint8_t size = 40; 
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