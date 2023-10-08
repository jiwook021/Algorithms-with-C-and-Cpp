#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* prev;
}node;

typedef struct Stack
{
    node* top;
    int sz;
}stack;

stack* initstack()
{
    stack* s1 = (stack*)malloc(sizeof(stack));
    s1->top = NULL;
    s1->sz = 0;
    
    return s1;
}

bool empty(stack* s)
{
    return (s->sz)?0:1;
}

void push(stack* s,int data)
{
    node* mynode = (node*)malloc(sizeof(node));
    mynode->data =data; 

    if(empty(s))
    {
        s->top = mynode; 
    }    
    mynode->prev = s->top;
    s->top = mynode;
    s->sz++;    
}
int pop(stack* s)
{
    if(empty(s))
        return -1;
    node* temp = s->top;
    int data = temp->data;
    s->top = s->top->prev;
    free(temp);
    s->sz--;
    return data;
}

int main()
{
    stack* s1 = initstack(); 
    
    push(s1,10);
    printf("hi\n");
    printf("%d\n", pop(s1));
    
    for(int i = 0; i<10;i++)
        push(s1,i);
    
    for(int i = 0; i<11;i++)
        printf("%d\n",pop(s1));

    return 0;
}
