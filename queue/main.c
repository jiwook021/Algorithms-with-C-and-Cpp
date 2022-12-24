#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <stdint.h>
#include "queue.h"

int main()
{
	clock_t starttime,endtime;
    starttime = clock();
	time_t t;
   	srand((unsigned) time(&t));



	const uint8_t size = 40; 
	queue * queue1; 

	for(uint8_t i =0; i < size; i++)
    {
		enqueue(rand() % 80+11,queue1);
		printf("Peek: %d",peek(queue1)); 
	}
	
	printf("\n\n");

	for(uint8_t i =0; i < size; i++)
    {
		printf("\nPeek: %d \t", peek(queue1));
		dequeue(queue1); 
	}
	
	printf("\n\n");

	
	
	
	endtime = clock();
    double time_taken = (double)(endtime - starttime)/ (double)(CLOCKS_PER_SEC);
    printf("Time taken by program is : %.10f sec\n\n",time_taken);
}


