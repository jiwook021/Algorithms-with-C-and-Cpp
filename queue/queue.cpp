#include "queue.hpp"
#include <cstdlib>
#include <iostream>

queue::queue()
	: front(0),rear(0)
{ 
}

bool queue::QisEmpty()
{
	if (front == rear)
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

void queue::enqueue(int data)
{
	rear=NextPosIdx(rear); 
	queArr[rear] = data; 
	printf("\nEnqueued: %d\t",data);
}

int queue::dequeue()
{
	front = NextPosIdx(front);
	printf("dequeued: %d",queArr[front]);
	return queArr[front];
}

int queue::peek() 
{
	return queArr[NextPosIdx(front)];
}
