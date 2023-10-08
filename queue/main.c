#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct queue 
{
    int front, back, size;
    unsigned int capacity;
    int* array;
}Queue; 

Queue* initqueue(unsigned int cap)
{
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->size = q->back = 0;
    q->front = 1;
    q->capacity = cap;
    q->array = (int*)malloc(q->capacity * sizeof(int));
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

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int front(struct queue* q)
{
    return q->size? q->array[q->front]: 0; 
}

int back(struct queue* q)
{
    return q->size? q->array[q->back]: 0; 
}

void push(Queue* queue,int item)
{   
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->back = (queue->back + 1) % queue->capacity;
    queue->array[queue->back] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

int pop(Queue* queue)
{
     if (empty(queue)) {
        printf("Queue is empty\n");
        return 99999;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front+1) % queue->capacity;
    queue->size = queue->size - 1;
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
    Queue* queue = initqueue(4);
    push(queue, 10);
    push(queue, 20);
    push(queue, 30);
    push(queue, 40);
    printf("Dequeued item = %d\n", pop(queue));
    
    push(queue, 50);
    push(queue, 60);
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", back(queue));
    freeQueue(queue);
    return 0;
}