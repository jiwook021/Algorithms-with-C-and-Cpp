#ifndef __LINKED_LIST__
#define __LINKED_LIST__

typedef struct _node
{
	int col;
	int row;
	char data;
	struct _node* next;
	struct _node* below;
} Node;

typedef struct _linkedList
{
	Node* head;
	Node* current;
	int size;
} LinkedList;

void InitList(LinkedList* list);
void LNInsert(LinkedList* list, Node* newNode, char data);
void LBInsert(LinkedList* list, Node* newNode, char data);
void NodebelowDelete(LinkedList* list, char data);

#endif