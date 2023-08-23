#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "stack.h"

int main()
{
	time_t t;
   	srand((unsigned) time(&t));
	stack* stack1 = (stack*)malloc(sizeof(stack));
	initstack(stack1);
	const uint8_t size = 30; 
	for(uint8_t i =0; i < size; i++)
    {
		push(rand() % 88+11,stack1);
		printf("Peek: %d\n",peek(stack1)); 
	}
	printf("\n");
	for(uint8_t i =1; i < size; i++)
    {
		pop(stack1); 
		printf("\tPeek:%d \n",peek(stack1));
	}
	free(stack1);
}


