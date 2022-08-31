#include "Circular_Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

int main()
{
	const uint8_t size = 20;
	srand (time(NULL));
    
	for(uint8_t i =0; i < size; i++)
    {
         enqueue(rand() % 10 + 1);
		 printf("Peek: %d  ", peek());
    }
	
	printf("\n");

	for(uint8_t i =0; i < size/4; i++)
    {
	printf("dequeue: %d\n", dequeue());
	printf("Peek: %d  ", peek());
	}

	printf("\n");
}


