#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Define a structure for a stack node to hold tree nodes
struct StackNode {
    struct TreeNode* treeNode;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createStackNode(struct TreeNode* treeNode) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->treeNode = treeNode;
    stackNode->next = NULL;
    return stackNode;
}

// Function to check if the stack is empty
int isStackEmpty(struct StackNode* root) {
    return !root;
}

// Function to push a tree node onto the stack
void push(struct StackNode** root, struct TreeNode* treeNode) {
    struct StackNode* stackNode = createStackNode(treeNode);
    stackNode->next = *root;
    *root = stackNode;
}

// Function to pop a tree node from the stack
struct TreeNode* pop(struct StackNode** root) {
    if (isStackEmpty(*root))
        return NULL;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    struct TreeNode* popped = temp->treeNode;
    free(temp);
    return popped;
}

// Function to perform inorder tree traversal without recursion
void inorderTraversal(struct TreeNode* root) {
    if (!root)
        return;

    struct TreeNode* current = root;
    struct StackNode* stack = NULL;

    while (current != NULL || !isStackEmpty(stack)) {
        // Traverse to the leftmost node
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        // Pop the top node from the stack
        current = pop(&stack);

        // Print the data of the popped node
        printf("%d ", current->data);

        // Move to the right subtree
        current = current->right;
    }
}

int main() {
    // Sample binary tree
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->data = 1;
    root->left = malloc(sizeof(struct TreeNode));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = malloc(sizeof(struct TreeNode));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    // Perform inorder traversal without recursion
    printf("Inorder traversal: ");
    inorderTraversal(root);

    return 0;
}
