#ifndef __Circular_doublelinkedlist_H__
#define __Circular_doublelinkedlist_H__

typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* previous;
}Node;

Node* head;
Node* tail;
Node* current;
int size;
void insert(int data);
void vRemove(int data);
void search(int data);
void print();
#endif 