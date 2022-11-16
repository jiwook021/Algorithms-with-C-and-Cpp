#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include <memory>
struct Node 
{
	int data; 
	std::shared_ptr<Node> next;
	std::shared_ptr<Node> previous;
};

class LinkedList
{
private: 
	std::shared_ptr<Node> head; 
	std::shared_ptr<Node> tail; 
	std::shared_ptr<Node> current;
	
	int size;
	
public:
	LinkedList();
	void insert(int data);
	void insert(int data, int seq);
	bool search(int data);
	void remove(int data);
	void print();
	bool check(int data);
};


#endif 