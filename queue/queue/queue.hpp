#ifndef __QUEUE_H__
#define __QUEUE_H__

#define QUE_LEN 100 

class queue 
{
private:
	int front;
	int rear;
	int queArr[QUE_LEN];

public:
	queue();
	bool QisEmpty();
	void enqueue(int data);
	int dequeue();
	int peek();
};


#endif 