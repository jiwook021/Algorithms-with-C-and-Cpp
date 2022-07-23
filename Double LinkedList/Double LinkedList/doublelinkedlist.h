#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct Node 
{
	int data; 
	Node* next;
	Node* previous;
};

class LinkedList
{
private: 
	Node* head; 
	Node* tail; 
	Node* current;
	
	int size;
	
public:
	LinkedList();
	void insert(int data);
	void insert(int data, int seq);
	void search(int data);
	void remove(int data);
	void print();
};


#endif 