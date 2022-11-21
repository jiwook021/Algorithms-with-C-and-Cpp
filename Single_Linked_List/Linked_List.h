#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdint.h>

typedef struct Node {
	int iData;
	struct Node* NextNode;
}Node;

typedef struct LinkedList {
	int size;
	bool init;
	Node* nCurrent;
	Node* nTail;
	Node* nHead;
}LinkedList;

void initLinkedList(struct LinkedList* pthis);
bool vInsertion(int iData,struct LinkedList* pthis);
bool vInsertionMid(int iData, int iSeq,struct LinkedList* pthis);
bool vRemove(int data,struct LinkedList* pthis);
void vSearch(int iData,struct LinkedList* pthis);
void vPrint(struct LinkedList* pthis);

void example1(LinkedList* pthis);
void example2(LinkedList* pthis);

#endif 