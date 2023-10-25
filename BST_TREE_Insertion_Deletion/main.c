#include <stdio.h>
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

tree* initTree()
{
    tree* tr = malloc(sizeof(tree));
    tr->root =NULL;
}
node* initNode(int data)
{
    node* newNode = malloc(sizeof(node));
    newNode->data=data;
    newNode-> left= NULL;
    newNode-> right= NULL;
    return newNode;
}

void pushBST(tree* tr, int data)
{
    node* newNode = initNode(data);
    if(tr->root ==NULL)
    {
        tr->root =newNode;
        return;
    }
    node* pNode; 
    node* cNode = tr->root; 
    while(cNode!=NULL)
    {    
        pNode = cNode;
        if(data>cNode->data)    
        {
            cNode = cNode->right; 
        }
        else
        {
            cNode = cNode->left;
        }
    }
    if(data>pNode->data)    
    {
        pNode->right = newNode; 
    }
    else
    {
        pNode->left = newNode;
    }
}

tree* findMin(node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

node* deleteNode(node* current, int data)
{
    if(current == NULL)
        return current;
    if(data > current->data)
        current->right = deleteNode(current->right, data);
    else if(data < current->data)
        current->left = deleteNode(current->left, data);
    else
    {
        if(current->left == NULL)
        {   
            node* temp = current->right;
            free(current);
            return temp;
        }
        else if(current->right == NULL)
        {
            node* temp = current->left;
            free(current);
            return temp;
        }
        node* temp = findMin(current->right);
        current->data = temp->data;
        current->right = deleteNode(current->right, temp->data);
    }
    return current;
}

void inorderPrint(node* node)
{
    if(node==NULL)
        return;
    inorderPrint(node->left);
    printf("%d\n", node->data);
    inorderPrint(node->right);
}
int main()
{
    tree* tr= initTree();
    pushBST(tr,5);
    pushBST(tr,4);
    pushBST(tr,3);
    pushBST(tr,6);
    pushBST(tr,8);
    node* rootNode= tr->root;
    inorderPrint(rootNode);
    printf("\n");
    deleteNode(rootNode, 3);
    inorderPrint(rootNode);
    printf("\n");
    deleteNode(rootNode, 5);
    inorderPrint(rootNode);
    printf("\n");   
}