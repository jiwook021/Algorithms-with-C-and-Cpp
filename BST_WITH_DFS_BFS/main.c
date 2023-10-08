#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node{
    struct node* left;
    struct node* right;
    int data;
}NODE;

typedef struct tree{
    struct node* root;
}TREE;

TREE* initTREE()
{
    TREE* newTREE = (TREE*)malloc(sizeof(TREE));
    newTREE->root=NULL;
    return newTREE; 
}
void insert(int data, TREE *tree) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if(tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    NODE* temp = tree->root;
    NODE* parent = NULL;

    while(temp != NULL) {
        parent = temp;
        if(data > temp->data) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }

    if(data > parent->data) {
        parent->right = newNode;
    } else {
        parent->left = newNode;
    }
}


void dfsprint(NODE *node)
{
    if(node == NULL)
        return;
    dfsprint(node->left);
    printf("%d\n",node->data);
    dfsprint(node->right);
}


void bfsprint(NODE *root) {
    if (root == NULL)
        return;

    NODE* queue[100];  // Queue of node pointers
    int head = 0, tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        NODE* current = queue[head++];
        
        printf("%d\n", current->data);

        if (current->left != NULL)
            queue[tail++] = current->left;
        if (current->right != NULL)
            queue[tail++] = current->right;
    }
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
