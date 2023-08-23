#include "doublelinkedlist.h"

void initLinkedList(struct LinkedList* self)
{
	self-> head = NULL; 
	self->tail = NULL;
	self->current = NULL; 
	self->size=0;
	self->init = true; 
} 

//In the insert() function, when the linked list is empty and a new node is added, the self->tail pointer is not updated.

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
		self->tail = newNode;
	}
	else
	{ 
		newNode->previous = self->tail;
		self->tail->next = newNode;
		self->tail = newNode;
	}

	printf("Insert %d\n", data);
	self->size++;
	return true;
}

//In the insertMid() function, the self->tail pointer is updated to point to the new node, which is incorrect. It should only be updated if the new node is added at the end of the list.
bool insertMid(int data, int seq,struct LinkedList* self)
{
	if (!self->init) 
	{
		printf("init Error");
		return false; 
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("newNode Error");
		return false;
	}
	newNode->data = data;
	newNode->next = NULL;
	self->current = self->head;
	for (int i = 1; i < seq - 1; i++)
	{
		self->current = self->current->next;
		if (self->current == NULL)
			return false;
	}

	newNode->next = self->current->next;
	if (self->current->next != NULL)
		self->current->next->previous = newNode;
	newNode->previous = self->current;
	self->current->next = newNode;
	if (self->tail == self->current)
		self->tail = newNode;
	printf("Insert %d at %d\n", data, seq);
	self->size++;
	return true;
}


bool check(int data, struct LinkedList* self) 
{
    self->current = self->head;
    while (self->current != NULL) 
    {
        if (data == self->current->data) 
        {
            return true;
        }
        self->current = self->current->next;
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



// bool Remove(int data, struct LinkedList* self) 
// {
// 	if(self->init==false) 
// 		return false; 

// 	if(check(data,self) == true) 
// 	{ 
// 		self->current = self->head;
// 		for (int i = 1; i <= self->size; i++)
// 		{ 
// 			self->current = self->current->next;	
// 			if (data == self->current->data) break; 
// 		}
// 		self->current->previous->next = self->current->next;
// 		self->current->next->previous = self->current->previous; 
// 		printf("Remove %d\n",data);
// 		//delete current;
// 		free(self->current);
// 		self->size--; 
// 		return true;
// 	}
// 	else 
// 	{
// 		printf("failed to delete %d since its not available\n",data);
// 		return false;
// 	}
// }

bool Remove(int data, struct LinkedList* self) {
	if (self->init == false)
		return false;

	if (check(data, self) == true) {
		self->current = self->head;
		for (int i = 1; i <= self->size-1; i++) {
			self->current = self->current->next;
			if (data == self->current->data) break;
		}
		if (self->current == self->head) {
			self->head = self->current->next;
			self->head->previous = NULL;
		}
		else if (self->current == self->tail) {
			self->tail = self->current->previous;
			self->tail->next = NULL;
		}
		else {
			self->current->previous->next = self->current->next;
			self->current->next->previous = self->current->previous;
		}
		printf("Remove %d\n", data);
		free(self->current);
		self->size--;
		return true;
	}
	else {
		printf("failed to delete %d since its not available\n", data);
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



void sort_double_Linkled_list(struct LinkedList* self) {
    int temp;
    self->current = self->head;
    for (int i = 0; i < self->size - 1; i++) {
        for (int j = 0; j < self->size - i - 1; j++) {
            if (self->current->data > self->current->next->data) {
                temp = self->current->data;
                self->current->data = self->current->next->data;
                self->current->next->data = temp;
            }
            self->current = self->current->next;
        }
        self->current = self->head;
    }
}