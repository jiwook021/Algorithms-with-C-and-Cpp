#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
//single linked list


const int NUM_THREADS = 10;
static pthread_mutex_t majormtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t majorcond = PTHREAD_COND_INITIALIZER;
    
typedef struct Node
{
    int data;
    struct Node* next; 
} node; 

typedef struct List
{
    int sz;    
    node* top;
    node* tail;
    pthread_mutex_t mtx;
    pthread_cond_t cond;
}list;

list* initlist()
{
    list* l = (list*)malloc(sizeof(list));
    l->sz = 0; 
    l->top = NULL;
    pthread_mutex_init(&l->mtx, NULL);
    pthread_mutex_init(&l->cond, NULL);
    return l;
}


typedef struct {
    list* param1;
    int param2;
} ThreadParams;


//stack push
void push_front(void* arg)
{
    ThreadParams* params = (ThreadParams*)arg;
    list* l = params->param1;
    int data = params->param2;
    node* newNode = (node*)malloc(sizeof(node));
    newNode-> data = data; 
    l->sz++;
    if(l->top==NULL)
    {
        l->top = l->tail = newNode;
        newNode->next = NULL;
        pthread_mutex_lock(&l->mtx);
        pthread_cond_signal(&l->cond);
        pthread_mutex_unlock(&l->mtx);
        return;
    }
    newNode->next = l->top;
    l->top = newNode;
    pthread_mutex_lock(&l->mtx);
    pthread_cond_signal(&l->cond);
    pthread_mutex_unlock(&l->mtx);  
    return;
}


//queue push 
void push_back(void* arg)
{
    ThreadParams* params = (ThreadParams*)arg;
    list* l = params->param1;
    int data = params->param2;
    node* newNode = (node*)malloc(sizeof(node));
    newNode-> data = data; 
    newNode-> next = NULL;
    l->sz++;
    if(l->top==NULL)
    {
        l->top = l->tail = newNode;
        newNode->next = NULL;
        pthread_mutex_lock(&l->mtx);
        pthread_cond_signal(&l->cond);
        pthread_mutex_unlock(&l->mtx); 
        return;
    }
    l->tail->next = newNode; 
    l->tail = l->tail->next; 
    pthread_mutex_lock(&l->mtx);
    pthread_cond_signal(&l->cond);
    pthread_mutex_unlock(&l->mtx); 
    return;
}

//linked list
void insert(list* l, int data, int index)
{
    if(index > l->sz-1)
    {
        return;
    }
    if(index == 0)
    {
        ThreadParams params;
        params.param1 = l;
        params.param2 = data;
        push_front(&params);
        return;
    }
    if(index == l->sz-1)
    {
        ThreadParams params;
        params.param1 = l;
        params.param2 = data;
        push_back(&params);
        return;
    }
    node* current = l->top;
    index--;
    while(index--)
    {
        current = current->next;
    }
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = current ->next;
    current->next = newNode;
    l->sz++;
    return;
}



//stack // queue 
int pop(list *l)
{
    pthread_mutex_lock(&l->mtx);
    pthread_cond_signal(&l->cond);
    pthread_mutex_unlock(&l->mtx);
    if(l->sz == 0)
    {
        return -1;
    }
    l->sz--;
    int Topvalue = l->top->data; 
    node* dNode = l->top; 
    l->top = l->top ->next;
    free(dNode);
    return Topvalue;
}



void deleteNode(list*l, int data)
{  
    if(l->sz == 0)
    {
        return;
    }
    if(l->top->data ==data)
    {
        pop(l);
        if(l->top->data ==data)
        {
            pop(l);
        }
    }
    node* current = l->top; 
    node* pnode;
    while(current !=NULL)
    {
        if(data == current ->data)
        {
            node* dnode = current; 
            pnode->next = current -> next;
            current = pnode;
            free(dnode); 
            l->sz--;
        }
        pnode = current; 
        current = current -> next; 
    }
}

void printList(list *l)
{
    pthread_mutex_lock(&l->mtx);
    pthread_cond_wait(&l->cond, &l->mtx);
    pthread_mutex_unlock(&l->mtx);
    node* temp = l->top; 
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp ->next;
    }
    printf("\n");
}

void queueThreadtest()
{
    pthread_t threads[NUM_THREADS];
    list* q = initlist();
    for(int i =0;i<10;i++)
    {
        ThreadParams params;
        params.param1 = q;
        params.param2 = i;
        pthread_create(&threads[i], NULL, &push_back, (void*)&params);
        printList(q);
    }
    for(int i =0;i<10;i++)
    {
    if(pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");  
    }
    }
    pthread_t popthreads[NUM_THREADS];
    for(int i =0;i<10;i++)
    {
        pthread_create(&threads[i], NULL, &pop, (void*)q);
        printList(q);
    }
    pthread_mutex_lock(&majormtx);
    pthread_cond_signal(&majorcond);
    pthread_mutex_unlock(&majormtx);
    return;
}
void stackThreadtest()
{
    pthread_t stack_push_threads[NUM_THREADS];
    list* s = initlist();
    for(int i =0;i<10;i++)
    {
        ThreadParams params;
        params.param1 = s;
        params.param2 = i;
        pthread_create(&stack_push_threads[i], NULL, &push_front, (void*)&params);
        printList(s);
    }
    for(int i =0;i<10;i++)
    {
        if(pthread_join(stack_push_threads[i], NULL) != 0) {
            perror("pthread_join");  
        }
    }
    pthread_t stack_popthreads[NUM_THREADS];
    for(int i =0;i<10;i++)
    {
        pthread_create(&stack_popthreads[i], NULL, &pop, (void*)s);
        printList(s);
    }   
}

int main()
{
    pthread_t queuethread, stackthread;
    pthread_create(&queuethread, NULL, &queueThreadtest, NULL);    
    pthread_mutex_lock(&majormtx);
    pthread_cond_wait(&majorcond,&majormtx);
    pthread_mutex_unlock(&majormtx);
    pthread_create(&stackthread, NULL, &stackThreadtest, NULL);
    if(pthread_join(queuethread, NULL) != 0) {
        perror("pthread_join");  
    }
    if(pthread_join(stackthread, NULL) != 0) {
        perror("pthread_join");  
    }
    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>


// typedef struct node
// {
//     int data;
//     struct node* next;
// }Node; 

// typedef struct Slinked_list
// {
//     Node* head;
//     Node* tail;
//     int sz; 
// }list;

// list* initlist()
// {
//     list* l= (list*)malloc(sizeof(list));
//     l->head = NULL;
//     l->tail = NULL;
//     l->sz = 0;
//     return l; 
// }

// void enqueue(list* l, int data)//queue; 
// {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->next = NULL; 
//     if(l->sz == 0)
//     {
//         l->head = newNode;
//         l->tail = newNode; 
//         l->sz++;  
//         return;
//     }
//     l->tail->next = newNode;
//     l->tail= newNode;
//     l->sz++;
// }


// void push(list* l, int data)//queue; 
// {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->next = NULL; 
//     if(l->sz == 0)
//     {
//         l->head = newNode;
//         l->tail = newNode; 
//         l->sz++;  
//         return;
//     }
//     newNode->next = l->head;
//     l->head = newNode;
//     l->sz++;
// }

// int pop(list* l)
// {
//     int result = l->head->data;
//     Node* dnode= l->head;  
//     l->head = l->head->next;
//     free(dnode); 
//     return result; 
// }


// void print(list* l)
// {
//     Node* current = l->head; 
//     while(current)
//     {
//         printf("%d\n", current->data);
//         current = current->next;
//     }
// }

// void stack()
// {
//     list* l = initlist(); 
//     for(int i=0;i<20;i++)
//         push(l,i);
//     for(int i=0;i<20;i++)
//         printf("%d\n",pop(l));
// }

// void queue()
// {
//     list* l = initlist(); 
//     for(int i=0;i<20;i++)
//         enqueue(l,i);
//     for(int i=0;i<20;i++)
//         printf("%d\n",pop(l));
// }
// int main()
// {
//     //stack();
//     //queue();
// }