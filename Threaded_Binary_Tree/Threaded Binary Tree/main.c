#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } boolean;
struct node* in_succ(struct node* p);
struct node* insert(struct node* root, int ikey);
void inprint(struct node* root);

struct node
{
    struct node* left;
    struct node* right;
    boolean lthread;
    boolean rthread;
    int data;
};


struct node* insert(struct node* root, int ikey)
{
    struct node* tmp, * par, * ptr;

    int found = 0;

    ptr = root;
    par = NULL;

    while (ptr != NULL)
    {
        if (ikey == ptr->data)
        {
            found = 1;
            break;
        }
        par = ptr;
        if (ikey < ptr->data)
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    if (found)
        printf("\n\nDuplicate key\n\n");
    else
    {

        tmp = (struct node*)malloc(sizeof(struct node));
        tmp -> data = ikey;
        tmp-> lthread = true;
        tmp-> rthread = true;
        if (par == NULL)
        {
            root = tmp;
            tmp->left = NULL;
            tmp->right = NULL;
        }
        else if (ikey < par->data)
        {
            tmp->left = par->left;
            tmp->right = par;
            par->lthread = false;
            par->left = tmp;
        }
        else
        {
            tmp-> left = par;
            tmp-> right = par->right;
            par-> rthread = false;
            par-> right = tmp;
        }
    }
    return root;
}


struct node* in_succ(struct node* ptr)
{
    if (ptr->rthread == true)
        return ptr->right;
    else
    {
        ptr = ptr->right;
        while (ptr->lthread == false)
            ptr = ptr->left;
        return ptr;
    }
}


void inprint(struct node* root)
{
    struct node* ptr;
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }

    ptr = root;
    /*Find the leftmost node */
    while (ptr->lthread == false)
        ptr = ptr->left;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = in_succ(ptr);
    }
}

int main()
{
    int choice, num;
    struct node* root = NULL;

    while (1)
    {
        printf("\n\nEnter the number to be inserted : ");
        scanf("%d", &num);
        printf("\n");
        root = insert(root, num);
        inprint(root);
    }
    return 0;

}