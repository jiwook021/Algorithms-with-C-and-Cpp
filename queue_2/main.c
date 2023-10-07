#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct node
{
    int data; 
    struct node* next;
    struct node* previous;
}NODE; 

typedef struct queue 
{
    int size;
    NODE* front;
    NODE* back;
}Queue; 

Queue* initqueue()
{
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->size =0;
    q->front =NULL;
    q->back=NULL;
    return q;
}

int size(struct queue* q)
{
    return q->size; 
}

int empty(struct queue* q)
{
    return q->size? 0:1;   
}

int front(struct queue* q)
{
    return q->size? q->front->data: 0; 
}

int back(struct queue* q)
{
    return q->size? q->back->data: 0; 
}

NODE* initnode(int data)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode ->next = NULL;
    newNode ->previous = NULL;
    newNode->data =data;
    return newNode;
}

void push(Queue* q,int data)
{   
    NODE* node = initnode(data);
    q->size++;
    if(q->front== NULL || q->back== NULL)
    {
        q->back = node;
        q->front = node; 
        printf("empty in push function q->back = %d\n", q->back->data);
        return;
    }
    node -> previous = q->back; 
    q->back->next = node; 
    q->back = node; 
    printf("in push function q->back = %d\n", q->back->data);
}

int pop(Queue* q)
{
    if(empty(q))
    {
        printf("Queue is empty!");
    }
    NODE* temp = q->front;
    int item = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->back = NULL;
    } else {
        q->front->previous = NULL;
    }  
    free(temp);
    q->size--;
    return item;
}

void freeQueue(Queue* queue) {
    while (!empty(queue)) {
        printf("Freed:%d!\n",pop(queue));
    }
    free(queue);
}

int main()
{
    Queue* queue = initqueue();
    push(queue, 10);
    push(queue, 20);
    push(queue, 30);
    push(queue, 40);
    printf("Dequeued item = %d\n", pop(queue));
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", back(queue));
    freeQueue(queue);
    return 0; 
}