#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


typedef struct Node {
	int iData;
	struct Node* NextNode;
}Node;

typedef struct LinkedList {
	int size;
	Node* nCurrent;
	Node* nTail;
	Node* nHead;
	LinkedList();
	void vSearch(int iData);
	void vInsertion(int iData);
	void vInsertion(int iData, int iSeq);
	void vRemove(int data);
	void vPrint();
}LinkedList;

void example1();
void example2();

#endif 