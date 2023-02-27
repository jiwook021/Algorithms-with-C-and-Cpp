#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node;



bool QisEmpty();
void enqueue(int data);
int dequeue();
int peek();
Node* front;
#endif 