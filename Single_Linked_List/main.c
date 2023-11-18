#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    struct Node* next;
    int data;
}node;

typedef struct list
{
    int sz; 
    node* head; 
    node* tail;
}list;

list* init()
{
    list* l =(list*)malloc(sizeof(list));
    l->sz =0;
    l->head = NULL;
    l->tail = NULL;
    return l;
}
void insert_back(list*l, int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data =data; 
    newNode->next =NULL;  
    l->sz++; 
    if(l->sz==1)
    {
        l->head = newNode;
        l->tail = newNode;
        return;
    }
    l->tail -> next = newNode; 
    l->tail = newNode;
}

void insert_front(list*l,int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data =data; 
    l->sz++;
    if(l->sz==1)
    {
        newNode->next =NULL;
        l->head = newNode;
        l->tail = newNode;
        return;
    }
    newNode -> next = l->head; 
    l->head = newNode;

}
void insert(list*l,int data,int index)
{
    if(index ==0)
    {
        insert_front(l,data);
        return;
    }
    if(index >= l->sz-1)
    {
        insert_back(l,data);
        return;
    }
    l->sz++;
    node* newNode = (node*) malloc(sizeof(node));
    newNode ->data =data;
    node* current = l->head;
    while(index--)
        current = current ->next; 
    newNode -> next = current->next;
    current ->next = newNode;
}
void Delete(list*l,int data)
{
    if(l->sz ==0)
    {
        return;
    }
    node* temp = l->head;
    if(l->sz ==1)
    {
        l->head =NULL;
        l->tail =NULL;
        free(temp);
        l->sz--;
        return;
    }
    node* pNode;
    
    //delete head
    if(data == l->head->data)
    {
        node* temp = l->head; 
        l->head = l->head->next;
        free(temp);
        return; 
    }
    while(temp!=NULL)
    {
        if(temp->data == data)
        {
            //delete tail
            if(temp->next == NULL)
            {
                node* dnode= l->tail;
                l->tail = pNode;
                pNode->next = NULL;
                free(dnode);
                return;
            }
            node* current = temp;
            pNode->next = temp ->next;
            temp = temp ->next; 
            free(current);
        }
        pNode = temp;
        temp = temp->next;
    }
}

void reverselist(list* l)
{
    node* current = l->head; 
    node* pNode =NULL; 
    node* nNode = NULL; 
    while(current != NULL)
    {
        nNode = current->next; //next node setting 
        current->next = pNode;  //current ->next pNode   
        pNode = current; 
        current = nNode; 
    }   
    l->head = pNode;
}

void print(list *l)
{
    node* temp = l->head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp = temp->next;
    }
     printf("\n");
}

void copylist(list *l,int arr[])
{
    int i =0;
    node* temp = l->head;
    while(temp!=NULL)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }
}

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main()
{
    list* l = init();

    insert_front(l,1);
    insert_front(l,2);
    insert_front(l,3);
    insert_front(l,4);
    insert_front(l,5);
    insert(l,20,0);
    insert(l,30,5);   
    insert(l,10,1);
    insert(l,40,2);
    
    print(l);
    reverselist(l);
    print(l);
    // Delete(l,1);
    // print(l);
    // Delete(l,5);
    // print(l);
    // Delete(l,3);
    // print(l);
    // Delete(l,2);
    // print(l);
    // Delete(l,4);
    // print(l);

    // const int arrsize= l->sz; 
    // int arr[arrsize];
    // copylist(l,arr);
    // qsort(arr, arrsize, sizeof(int),compare_ints); 
    // for(int i = 0;i<arrsize;i++)
    // {
    //     printf("%d", arr[i]);
    // }


    // for(int i = 0; i<10;i++)
    //     insert_front(l,i);
    // for(int i = 0; i<10;i++)
    //     insert_back(l,i);    
    
    // print(l);
}