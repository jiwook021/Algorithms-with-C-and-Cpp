#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// initalize queue, set front and rear of queue to 0
void Initqueue(queue *self)
{ 
	self->front = 0;
	self->rear = 0;
}

bool QueueisEmpty(queue *self)
{
	if (self->front == self->rear) //if index value of rear and front is same queue is empty
		return true;
	else
		return false;
}
//return net index 
int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1) //if end -> 99+1 = 0, allocate index to 0. 
		return 0;
	else
		return pos + 1; 
}

//put data at the rear
// 0 1 2 3 4 5 6 7 8 9 memory 
// 0 f q q r 5 6 7 8 9, then if enqueue  
// 0 f q q q r 6 7 8 9, then if enqueue 
// 0 f q q q q r 7 8 9, then if enqueue.

void enqueue(int data, queue *self)
{
	self->rear=NextPosIdx(self->rear); 
	self->queArr[self->rear] = data; 
	printf("\nEnqueued: %d\t",data);
}

// 0 1 2 3 4 5 6 7 8 9 memory 
// f q q q r 5 6 7 8 9, then if dequeue  
// 0 f q q r 5 6 7 8 9, then if deque 
// 0 1 f q r 5 6 7 8 9, then if deque 
//FIFO, return front value,
int dequeue(queue *self)
{
	printf("dequeued: %d",self->queArr[self->front]);
	int returnfront = (self->front); 
	self->front = NextPosIdx(self->front);
	return self->queArr[returnfront];
}

int peek(queue *self) 
{
	return self->queArr[self->front];
}
