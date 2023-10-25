#include <stdio.h>
#include <stdint.h> 
#include <stdlib.h>

typedef struct Node
{
    struct Node* left;
    struct Node* right; 
    int data;
}node; 


typedef struct Tree
{
    node* root;
}tree;

tree* inittree()
{
    tree* newTree = (tree*)malloc(sizeof(tree));
    newTree -> root = NULL;
    return newTree; 
}

void insertBST(tree* tr, int data)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data =data;
    newNode->left = NULL;
    newNode->right = NULL; 
    if(tr->root ==NULL)
    {
        tr->root = newNode;
        return;
    }
    node* cNode = tr->root;
    node* pNode;
    while(cNode!=NULL)
    {
        pNode = cNode;
        if(cNode->data < data)
        {
            cNode = cNode->right; 
        }
        else
        {
            cNode = cNode->left;
        }
    }
    if(pNode->data < data)
    {
        pNode->right = newNode; 
    }
    else
    {
        pNode->left = newNode;
    }
}

void printTree(node* NODE)
{
    if (NODE == NULL)
        return;
    printTree(NODE->left);
    printf("%d\n",NODE->data);
    printTree(NODE->right);
}


void bfsprint(node *root) {
    if (root == NULL)
        return;
    node* queue[100];  // Queue of node pointers
    int head = 0, tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        node* current = queue[head++];
        printf("%d\n", current->data);
        if (current->left != NULL)
            queue[tail++] = current->left;
        if (current->right != NULL)
            queue[tail++] = current->right;
    }
}

int main()
{
    tree* tr = inittree();
    insertBST(tr, 10);
    insertBST(tr, 12);
    insertBST(tr, 9);
    insertBST(tr, 13);
    //printTree(tr->root);
    bfsprint(tr->root);
}


int main() {
    TREE* tr = initTREE();

    insert(40, tr);
    insert(30, tr);
    insert(5, tr);
    insert(60, tr);
    insert(70, tr);
    insert(80, tr);
    insert(20, tr);
    insert(4, tr);
    insert(3, tr);

    printf("DFS Print:\n");
    dfsprint(tr->root);
    
    printf("\nBFS Print:\n");
    bfsprint(tr->root);

    return 0;
}
