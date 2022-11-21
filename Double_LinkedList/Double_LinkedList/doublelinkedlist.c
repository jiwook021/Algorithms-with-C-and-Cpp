#include "doublelinkedlist.h"

void initLinkedList(struct LinkedList* self)
{
	self-> head = NULL; 
	self->tail = NULL;
	self->current = NULL; 
	self->size=0;
	self->init = true; 
} 

bool insert(int data,struct LinkedList* self) 
{
	if(self->init==false) 
		return false; 

	Node* newNode = (Node*)malloc(sizeof(Node));
	if(NULL==newNode)
		return false;

	newNode->data = data;
	newNode->next = NULL;
	newNode->previous = NULL;

	if (self->head == NULL)
	{
		self->head = newNode;
	}
	else
	{ 
		self->tail->next = newNode;
		newNode->previous = self->tail;
	}

	printf("Insert %d\n", data);
	self->tail = newNode;
	self->size++;
	return true;
}

bool insertMid(int data, int seq,struct LinkedList* self)
{
	if(self->init==false) 
	{
		printf("init Error");
		return false; 
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(NULL==newNode)
	{
		printf("newNode Error");
		return false;
	}
	newNode->data = data;
	newNode->next = NULL;

	self->current = self->head;

	for (int i = 0; i < (seq-2); i++)
	{
		self->current = self->current->next;
	}

	newNode->next = self->current->next;
	self->current->next = newNode; 

	newNode->previous = self->current; 
	newNode->next->previous = newNode;
	
	self->tail = newNode;
	printf("Insert %d at %d \n", data,seq);
	self->size++;
	return true;
}

bool check(int data, struct LinkedList* self) {
	
	self->current = self->head;
	for (int i = 0; i < self->size; i++)
	{
		if (data == self->current->data) 
		{
			return true;
		}
		else
		{
			self->current = self->current->next;
		}
	}
	return false;
}

bool search(int data,struct LinkedList* self) 
{	
	self->current = self->head;

	for (int i = 0; i < self->size; i++)
	{
		if (data == self->current->data) 
		{
			printf("found : %d at index %d\n", data,i+1);
			return true;
		}
		else 
		{
			self->current = self->current->next;
		}
	}
	printf("cannot found : %d\n", data);
	return false;
}

bool Remove(int data, struct LinkedList* self) 
{
	if(self->init==false) 
		return false; 

	if(check(data,self) == true) 
	{ 
		self->current = self->head;
		for (int i = 1; i <= self->size; i++)
		{ 
			self->current = self->current->next;	
			if (data == self->current->data) break; 
		}
		self->current->previous->next = self->current->next;
		self->current->next->previous = self->current->previous; 
		printf("Remove %d\n",data);
		//delete current;

		self->size--; 
	}
	else 
	{
		printf("failed to delete %d since its not available\n",data);
		return false;
	}
}



void printList(struct LinkedList* self)
{
	self->current = self->head;
	printf("\n==============Print==============\n");
	for (int i = 0; i < self->size; i++)
	{ 	
		printf("%d ",self->current->data);
		self->current = self->current->next;
	}
	printf("\n=================================\n");
}
