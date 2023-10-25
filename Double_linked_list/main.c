
typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;    
}node;

typedef struct Dlist
{
    Node* head;
    Node* tail; 
    int sz;
}dlist;

static dlist* init()
{
    dlist* dl = (dlist*)malloc(sizeof(dlist));
    dl -> head = NULL;
    dl -> sz = 0;
}

static void insert_front(dlist* dl, int data)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    dl->sz++;
    if(dl->sz == 1)
    {
        dl->head = dl->tail = newNode; 
        return;
    }
    newNode->next = dl->head; 
    dl->head->prev = newNode; 
    dl->head =newNode;
}

static void insert_back(dlist* dl, int data)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    dl->sz++;
    if(dl->sz == 1)
    {
        dl->head = dl->tail = newNode; 
        return;
    }
    newNode->prev = dl->tail; 
    dl->tail->next = newNode; 
    dl->tail =newNode;
}


static void insert(dlist* dl, int data, int index)
{
    if(index == 0)
    {
        insert_front(dl,data);
        return;
    }
    if(index >= dl->sz)
    {
        insert_back(dl,data);
        return;
    }
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    dl->sz++;
    node* current = dl->head;
    
    while(--index)
        current = current ->next; 
    
    newNode -> next = current ->next; 
    current ->next ->prev = newNode; 
    current -> next = newNode; 
    newNode ->prev = current; 
}

static void DeleteNodeFront(dlist* dl)
{
    node* dnode = dl->head; 
    dl->head = dl->head->next;
    dl->head->prev = NULL; 
    free(dnode);
}

static void DeleteNodeBack(dlist* dl)
{
    node* dnode = dl->tail; 
    dl->tail = dl->tail->prev;
    dl->tail->next = NULL; 
    free(dnode);
}

static void DeleteNode(dlist* dl, int data)
{
    if(dl->sz == 0)
    {
        return;
    }
    if(data == dl ->head->data)
    {
        DeleteNodeFront(dl);
        if(dl->head->data == data)
        {
            DeleteNode(dl,data);
        }
        dl->sz --;
    }
    if(data == dl ->tail->data)
    {
        DeleteNodeBack(dl);
        dl->sz --;
    }
    node* temp = dl->head; 
    node* pnode;
    while(temp->next!=NULL)
    {
        if(data==temp->data)
        {
            node *dnode = temp;
            pnode->next = temp->next;
            temp->next->prev= pnode; 
            temp = temp->next;
            free(dnode);
            dl->sz --;
        }
        pnode = temp;
        temp = temp->next;
    }
    return;
}

static int print(dlist* dl)
{
    int i = 0;
    node* current = dl->head;
    for(int i = 0; i<dl->sz; i++)
    {
        printf("%d ", current->data);
        current = current ->next; 
    }
    printf("\n");
}

int main()
{
    dlist* dl = init();
    insert_front(dl,2);
    insert_front(dl,2);
    insert_front(dl,5);
    insert_front(dl,5);
    insert_front(dl,5);
    insert_front(dl,2);
    insert_front(dl,2);
    insert_front(dl,2);
    insert_front(dl,2);
    insert_front(dl,2);
    insert_front(dl,2);
    insert_front(dl,2);
    insert_front(dl,2);
    print(dl); 
    DeleteNode(dl,0);
    print(dl);
    DeleteNode(dl,2);
    print(dl);
}
