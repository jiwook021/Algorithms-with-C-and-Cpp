#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__


struct Node
{
	int data;
	struct Node* next;
};

class Queue 
{
private:
	Node* front;
	Node* rear;

public:
	Queue();
	bool QisEmpty();
	void enqueue(int data);
	int dequeue();
	int peek();
};


#endif 