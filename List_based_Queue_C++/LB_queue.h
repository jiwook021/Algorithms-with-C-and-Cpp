#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__
#include <memory>

struct Node
{
	int data;
	struct std::shared_ptr<Node> next;
};

class Queue 
{
private:
	std::shared_ptr<Node> front;
	std::shared_ptr<Node> rear;

public:
	Queue();
	bool QisEmpty();
	void enqueue(int data);
	int dequeue();
	int peek();
};


#endif 