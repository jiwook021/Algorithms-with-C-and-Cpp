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
int size;
void vInsert(int data);
void vRemove(int data);
void vSearch(int data);
void vPrint();
#endif 