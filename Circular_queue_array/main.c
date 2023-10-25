#include<stdio.h>
#include<stdlib.h>

const int tsz = 10; 
typedef struct circularqueue
{
    int head;
    int tail;
    int array[tsz];
    int sz;
}q;

q* init()
{
    q* q1= (q*)malloc(sizeof(q));
    for(int i =0; i<tsz; i++)
    {
        q1->array[i] =0;
    }
    q1->head = 0;
    q1->tail = 0; 
    q1->sz = 0;

    return q1;
}

int size(q* q)
{
    return q->sz;
}

void push(q* q,int data)
{
    if(size(q) >= tsz)
    {
        return; 
    }
    q->array[q->tail] = data;
    q->tail = (q->tail+1) %(tsz); 
    q->sz++; 
} 

int pop(q* q)
{
    if(size(q)==0)
    {
        return -1;
    }
    int data = q->array[q->head];
    q->head = (q->head+1) %(tsz);
    q->sz--;
    return data;
}

int main()
{
   q* queue =init();
   for(int i = 0; i < 10;i++)
    push(queue,i);   
   for(int i = 0; i < 5;i++)
    printf("%d\n",pop(queue));   
   for(int i = 0; i < 5;i++)
    push(queue,i); 
    for(int i = 0; i < 10;i++)
    printf("%d\n",pop(queue));
}