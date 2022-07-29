#include "doublelinkedlist.hpp"
#include <cstdlib>
#include <iostream>

LinkedList::LinkedList()
	: head(nullptr), tail(nullptr), current(nullptr), size(0)
{ }

void LinkedList::insert(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = nullptr;
	newNode->previous = nullptr;

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{ 
    tail->next = newNode;
	newNode->previous = tail;
	}

	std::cout<<"Insert " << data <<std::endl;
	tail = newNode;
	this->size++;
}

void LinkedList::insert(int data, int seq)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = nullptr;

	current = head;
	for (int i = 0; i < (seq-2); i++)
	{
		current = current->next;
	}

	newNode->next = current->next;
	current->next = newNode; 

	newNode->previous = current; 
	newNode->next->previous = newNode;
	
	tail = newNode;
	std::cout<<"Insert " << data <<" at " << seq <<std::endl;
	this->size++;
}

void LinkedList::remove(int data) {

	current = head;

	for (int i = 0; i < this->size; i++)
	{ 
		current = current->next;	
		if (data == current->data) break; 
	}
	current->previous->next = current->next;
	current->next->previous = current->previous; 
	std::cout<<"Remove " << data <<std::endl;
	free(current);
}
void LinkedList::search(int data) {
	current = head;

	for (int i = 0; i < this->size; i++)
	{
		if (data == current->data) std::cout << "found :" << data << std::endl;
		current = current->next;
	}
	this->size--; 
}

void LinkedList::print()
{
	current = head;

	for (int i = 0; i < this->size; i++)
	{ 	
		std::cout << current->data << std::endl;
		current = current->next;
	}
	printf("=====================\n");
}
