#include "Circular_Queue.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	enqueue(1);
	printf("Peek: %d\n", peek());
	enqueue(2);
	printf("Peek: %d\n", peek());
	enqueue(3);
	printf("Peek: %d\n", peek());
	enqueue(4);
	printf("Peek: %d\n", peek());
	enqueue(5);
	printf("Peek: %d\n", peek());
	printf("dequeue: %d\n", dequeue());
	printf("dequeue: %d\n", dequeue());
	printf("dequeue: %d\n", dequeue());
	printf("dequeue: %d\n", dequeue());
	printf("dequeue: %d\n", dequeue());
}


