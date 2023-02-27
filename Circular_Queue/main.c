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
		printf("Peek:%d  \n", peek());
    }
	// printf("\n");
	
	// for(uint8_t i =0; i < size-1; i++)
    // {
	// 	printf("dequeue: %d\t", dequeue());
	// 	printf("Peek: %d  \n", peek());
	// }

	printf("\n");
	sortQueue();

	for(uint8_t i =0; i < size-1; i++)
    {
		printf("dequeue: %d\t", dequeue());
		printf("Peek: %d  \n", peek());
	}

	printf("\n");
}



//sort queue
void sortQueue()
{
	int temp;
	Node* current = front;
	Node* next = front->next;
	while(current->next != NULL)
	{
		while(next != NULL)
		{
			if(current->data > next->data)
			{
				temp = current->data;
				current->data = next->data;
				next->data = temp;
			}
			next = next->next;
		}
		current = current->next;
		next = current->next;
	}
	printf("queue complete sorted\n");	
}