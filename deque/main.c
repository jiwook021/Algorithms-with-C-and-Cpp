#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* prev;
    struct Node* next;
    int data; 
}NODE; 

typedef struct Deque
{
    NODE* head;
    NODE* rear;
}DEQUE;

NODE* createnode(int data)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    return newNode;
}

DEQUE* initdeque()
{
    DEQUE* dq = (DEQUE*)malloc(sizeof(DEQUE));
    dq->head =NULL;
    dq->rear =NULL;
    return dq;
}

//clears the contents
void clear(DEQUE* dq)
{
    NODE* tmp = dq->head; 
    while(tmp==NULL)
    {
        pop_front(dq);
        tmp = tmp->next;
    }
}

void push_front(DEQUE * dq,int data)
{
    NODE* newNode = createnode(data);
    newNode->prev = NULL;
    if(dq->head ==NULL)
    {
        dq->head = dq->rear = newNode;
        return;
    }
    dq->head-> prev = newNode;
    newNode->next = dq->head;
    dq->head = newNode;
}



void push_back(DEQUE * dq,int data)
{
    NODE* newNode = createnode(data);
    newNode->next = NULL;
    if(dq->rear ==NULL)
    {
        dq->rear = dq->head = newNode;
        return;
    }
    dq->rear-> next = newNode;
    newNode->prev = dq->rear;
    dq->rear = newNode;
}
 
//removes the first element
int pop_front(DEQUE* dq)
{
    if(dq->head == NULL)
    {
        return -1;
    }
    NODE* tmp = dq->head;
    int result = tmp->data; 
    dq->head = dq->head->next;
    free(tmp);
    return result; 
}


//removes the last element
int pop_back(DEQUE* dq)
{
    if(dq->rear == NULL)
    {
        return -1;
    }
    NODE* tmp = dq->rear;
    int result = tmp->data; 
    dq->rear = dq->rear->prev;
    free(tmp);
    return result; 
}

 



// //erases elements
// void erase(DEQUE* dq, int n, int m)
// {

// }

// resize
 
// //swaps the contents
// swap
 
int main()
{
    DEQUE* dq = initdeque();
    for(int i = 0; i<10; i++)
    {
        push_front(dq,i);
    }
    for(int i = 10; i<20; i++)
    {
        push_back(dq,i);
    }
     for(int i = 0; i<20; i++)
    {
        printf("pop front=%d\n", pop_front(dq));
    }
    for(int i = 0; i<10; i++)
    {
        push_front(dq,i);
    }
    for(int i = 10; i<20; i++)
    {
        push_back(dq,i);
    }
     for(int i = 0; i<20; i++)
    {
        printf("pop back= %d\n", pop_back(dq));
    }
    return 0;
} 