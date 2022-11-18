#include "LB_queue.h"
#include <cstdlib>
#include <iostream>
#include <memory>

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

	std::shared_ptr<Node> node(new Node());
	
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
	printf("Enqueued %d\t",Data);
}

int Queue::dequeue()
{
	std::shared_ptr<Node> deletenode = front; 

	int number = front->data; 
	front = front->next; 
//	free(deletenode); 
	return number; 
}

int Queue::peek() 
{
	return front->data; 
}
