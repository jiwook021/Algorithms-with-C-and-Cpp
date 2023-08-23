#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct Node 
{
	int data; 
	struct Node* next;
	struct Node* previous;
}Node;

typedef struct LinkedList
{
	struct Node* head; 
	struct Node* tail;  
	struct Node* current;
	int size;
	bool init; 
}LinkedList;
 
void initLinkedList(struct LinkedList* self);
bool insert(int data,struct LinkedList* self);
bool insertMid(int data, int seq,struct LinkedList* self);
bool check(int data,struct LinkedList* self);
bool Remove(int data,struct LinkedList* self);
bool search(int data,struct LinkedList* self);
void printList(struct LinkedList* self);


#endif 