#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include <memory>

typedef struct Node {
	int iData;
	std::shared_ptr<Node> NextNode;
}Node;

typedef struct LinkedList {
	int size;
	std::shared_ptr<Node> nCurrent;
	std::shared_ptr<Node> nTail;
	std::shared_ptr<Node> nHead;
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