

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


