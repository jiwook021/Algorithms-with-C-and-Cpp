#ifndef __STACK_H__
#define __STACK_H__


typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* previous;
}Node;

typedef struct stack 
{
	struct Node* head;
	int size;	
}stack;

void initstack(stack* self);
void push(int data,stack* self);
void pop(stack* self);
int peek(stack* self);

#endif 