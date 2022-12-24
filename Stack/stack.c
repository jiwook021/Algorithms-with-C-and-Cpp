#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

//LIFO
// _____  <--- head 
// _____
// _____  
void initstack(stack* self)
{ 
	self->head = NULL; 
}

//LIFO
// _____ <--- newNode next null(potential head)
//
// _____  <--- head(peek)
// _____
// _____  

void push(int data,stack* self)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data; 
	
	newNode->next = NULL;
	newNode->previous = self->head;
	self->head = newNode;  

	printf("Pushed %d\t",data);
}
// _____  <--- head(needs to be delete)
// _____  <--- potential head
// _____  
void pop(stack* self)
{
	if(self->head == NULL)
		return;
	Node* deleteNode = self->head;
	
	self->head = self->head->previous;
	
	printf("Pop: %d\t", deleteNode->data);
	free(deleteNode);
}

int peek(stack* self) 
{
	if(self->head == NULL)
		return -1;

	return self->head->data; 
}
