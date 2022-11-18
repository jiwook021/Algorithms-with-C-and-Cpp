#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Initqueue(queue *self)
{ 
	self->front = 0;
	self->rear = 0;
}

bool QisEmpty(queue *self)
{
	if (self->front == self->rear)
		return true;
	else
		return false;
}

int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1; 
}

void enqueue(int data, queue *self)
{
	self->rear=NextPosIdx(self->rear); 
	self->queArr[self->rear] = data; 
	printf("\nEnqueued: %d\t",data);
}

int dequeue(queue *self)
{
	self->front = NextPosIdx(self->front);
	printf("dequeued: %d",self->queArr[self->front]);
	return self->queArr[self->front];
}

int peek(queue *self) 
{
	return self->queArr[NextPosIdx(self->front)];
}
