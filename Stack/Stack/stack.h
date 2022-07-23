#ifndef __STACK_H__
#define __STACK_H__


struct Node
{
	int data;
	Node* next;
	Node* previous;
};

class stack 
{
private:
	Node* head;
	int size;

public:
	stack();
	void push(int data);
	void pop();
	int peek();
};


#endif 