#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev; 
}node; 

typedef struct Deque
{
    int data;
    int sz;
    node* front;
    node* back;
    pthread_mutex_t mutex;
}deque;

typedef struct {
    deque* param1;
    int param2;
} ThreadParams;

deque* initdeque()
{
    deque* d = (deque*) malloc(sizeof(deque));
    d->front = NULL;
    d->back = NULL;
    d->sz = 0;
    pthread_mutex_init(&d->mutex, NULL);
    return d;
}

void push_front(void* arg)
{
    ThreadParams* params = (ThreadParams*)arg;
    deque* d= params->param1; 
    int data = params->param2;

    pthread_mutex_lock(&d->mutex);
    node * newNode = (node*) malloc(sizeof(node)); 
    newNode->data = data;
    newNode->prev = NULL;
    d->sz++;
    if(d->sz == 1)
    {
        newNode->next = NULL;
        d->front = d->back = newNode;
        pthread_mutex_unlock(&d->mutex);
        return;
    }
    d->front->prev = newNode; 
    newNode->next = d->front;
    d->front = newNode;
    pthread_mutex_unlock(&d->mutex);
    return; 
}
void push_back(void* arg)
{
    ThreadParams* params = (ThreadParams*)arg;
    deque* d= params->param1; 
    int data = params->param2;
    pthread_mutex_lock(&d->mutex);
    node * newNode = (node*) malloc(sizeof(node)); 
    newNode->data = data;
    newNode->next = NULL;
    d->sz++;
    if(d->sz == 1)
    {
        newNode->prev = NULL;
        d->front = d->back = newNode;
        printf("%d  ",newNode->data);
        pthread_mutex_unlock(&d->mutex);
        return;
    }
    d->back->next = newNode; 
    newNode->prev = d->back;
    d->back = newNode;
    printf("%d  ",newNode->data);
    pthread_mutex_unlock(&d->mutex);
    return; 
}
int pop_front(deque *d)
{
    pthread_mutex_lock(&d->mutex);
    if (d->sz == 0)
        return -1;
    d->sz--;
    int result = d->front->data;
    node* dnode = d->front;
    if (d->front == d->back) 
    {
        d->front = NULL;
        d->back = NULL;
    }
    else
    {
        d->front = d->front->next; 
        d->front->prev = NULL;
    }
    free(dnode);
    
    printf("%d  ", result);
    pthread_mutex_unlock(&d->mutex);
    
    return result;
}
int pop_back(deque *d)
{ 
    pthread_mutex_lock(&d->mutex);
    if (d->sz == 0)
        return -1;
    d->sz--;
    int result = d->back->data;
    node* dnode = d->back;
    if (d->front == d->back) 
    {
        d->front = NULL;
        d->back = NULL;
    }
    else
    {
        d->back = d->back->prev; 
        d->back->next = NULL;
    }
    free(dnode);
    printf("%d  ", result);
    pthread_mutex_unlock(&d->mutex);
    return result;
}


void print_deque(deque *d)
{
    pthread_mutex_lock(&d->mutex);
    node* current = d->front;
    while(current != NULL)
    {
        printf("%d ",current->data);
        current = current ->next;
    }
    printf("\n");
    pthread_mutex_unlock(&d->mutex);
}


#define NUM_THREADS 20
int main()
{
    deque* d = initdeque();
    pthread_t threads[NUM_THREADS];
    pthread_t push_threads[NUM_THREADS];
    
    for(int i =0;i<19;i++)
    {
        ThreadParams params;
        params.param1 = d;
        params.param2 = i;
        pthread_create(&push_threads[i], NULL, &push_back, (void*)&params);
        if (pthread_join(push_threads[i], NULL) != 0) {
            perror("pthread_join");  
        }
    }
    printf("\n");

    for(int i =0;i<19;i++)
    {        
        pthread_create(&threads[i], NULL, &pop_back, (void*)d);
    }
    for(int i =0;i<19;i++)
    {  
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");  
        }
    }
}