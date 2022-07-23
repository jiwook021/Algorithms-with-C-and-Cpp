#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node;


Node* front;
Node* rear;

bool QisEmpty();
void enqueue(int data);
int dequeue();
int peek();


#endif 