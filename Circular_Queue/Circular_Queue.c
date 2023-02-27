#include "Circular_Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


static Node* rear;

bool QisEmpty()
{
	if (front == NULL && rear == NULL)
		return true;
	else
		return false;
}


void enqueue(int Data)
{

	Node* node = (Node*)malloc(sizeof(Node));
	node->data = Data;

	if (front == NULL && rear == NULL)
	{
		front = node;
		rear = node;
	}

	else
	{
		rear->next = node;
		rear = node;
	}
	printf("Enque: %d\t", Data);
}

int dequeue()
{
	Node* deletenode = front;
	int number = front->data;  //node->data, *(node).data;
	front = front->next;
	free(deletenode);
	return number;
}

int peek()
{
	return front->data;
}
