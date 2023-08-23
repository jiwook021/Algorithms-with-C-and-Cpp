#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdbool.h>
#define QUE_LEN 100 
typedef struct queue 
{
	int front;
	int rear;
	int queArr[QUE_LEN];
}queue;
void Initqueue(queue *self);
bool QisEmpty(queue *self);
void enqueue(int data,queue *self);
int dequeue(queue *self);
int peek(queue *self);
#endif 