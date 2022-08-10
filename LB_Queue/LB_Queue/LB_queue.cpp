#include "LB_queue.h"
#include <cstdlib>
#include <iostream>

Queue::Queue()
	: front(nullptr),rear(nullptr)
{
}

bool Queue::QisEmpty()
{
	if (front==nullptr && rear==nullptr)
		return true;
	else
		return false;
}


void Queue::enqueue(int Data)
{

	Node* node = (Node*)malloc(sizeof(Node));
	node->data = Data;

	if (front == nullptr && rear == nullptr)
	{
		front = node; 
		rear = node; 
	}
 
	else
	{ 
		rear->next = node;
		rear = node;
	}
	printf("Enqueued %d\n",Data);
}

int Queue::dequeue()
{
	Node* deletenode = front; 

	int number = front->data; 
	
	
	front = front->next; 
	free(deletenode); 


	return number; 
}

int Queue::peek() 
{
	return front->data; 
}
