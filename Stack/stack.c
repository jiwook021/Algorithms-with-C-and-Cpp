#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void initstack(stack* self)
{ 
	self->head = (Node*)malloc(sizeof(Node)); 
}

void push(int data,stack* self)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data; 
	newNode->next = self->head->next; 
	self->head->next = newNode; 
	printf("Pushed %d\t",data);
}

void pop(stack* self)
{
	Node* deleteNode = self->head->next;
	self->head->next = self->head->next->next;
	printf("Pop: %d\t", deleteNode->data);
	free(deleteNode);
}

int peek(stack* self) 
{
	return self->head->next->data; 
}
