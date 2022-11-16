#include "doublelinkedlist.hpp"
#include <cstdlib>
#include <iostream>
#include <memory>

LinkedList::LinkedList()
	: head(nullptr), tail(nullptr), current(nullptr), size(0)
{ }

void LinkedList::insert(int data) {
	
	std::shared_ptr<Node> newNode(new Node());


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
	std::shared_ptr<Node> newNode(new Node());
	
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

	if(check(data) == true) 
	{ 
	current = head;
	for (int i = 1; i <= this->size; i++)
	{ 
		current = current->next;	
		if (data == current->data) break; 
	}
	current->previous->next = current->next;
	current->next->previous = current->previous; 
	std::cout<<"\nRemove " << data <<std::endl;
	//delete current;

	this->size--; 
	}
	else 
	{
		printf("\nfailed to delete %d since its not available\n",data);
		return;
	}
}
bool LinkedList::check(int data) {
	current = head;
	for (int i = 0; i < this->size; i++)
	{
		if (data == current->data) 
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

bool LinkedList::search(int data) {
	current = head;

	for (int i = 0; i < this->size; i++)
	{
		if (data == current->data) 
		{
			std::cout << "found :" << data << std::endl;
			return true;
		}
		current = current->next;
		
	}
	return false;
}

void LinkedList::print()
{
	current = head;
	printf("\n==============Print==============\n");
	for (int i = 0; i < this->size; i++)
	{ 	
		std::cout << current->data << " ";
		current = current->next;
	}
	printf("\n=================================\n");
}
