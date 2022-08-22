#include "stack.hpp"
#include <cstdlib>
#include <iostream>

stack::stack()
	: head((Node*)malloc(sizeof(Node)))
{ 


}

void stack::push(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = nullptr;
	newNode->data = data; 
	newNode->next = head->next; 
	head->next = newNode; 
	printf("Pushed %d\n",data);
}

void stack::pop()
{
	Node* deleteNode = head->next;
	head->next = head->next->next;
	printf("Pop: %d\n", deleteNode->data);
	free(deleteNode);
}

int stack::peek() 
{
	return head->next->data; 
}
