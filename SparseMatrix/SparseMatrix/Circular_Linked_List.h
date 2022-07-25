#ifndef __CIRCULAR_LINKED_LIST_H__
#define __CIRCULAR_LINKED_LIST_H__



typedef struct Node {
	int row;
	int column;
	char data;
	struct Node* NextNode;
	struct Node* BelowNode;
}Node;

typedef struct LinkedList {
	int size;
	Node* nCurrent;
	Node* nTail;
	Node* nHead;
}LinkedList;

#endif 