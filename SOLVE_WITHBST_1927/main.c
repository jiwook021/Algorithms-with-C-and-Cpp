// 널리 잘 알려진 자료구조 중 최소 힙이 있다. 최소 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.
// 배열에 자연수 x를 넣는다.
// 배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
// 프로그램은 처음에 비어있는 배열에서 시작하게 된다.
// 입력
// 첫째 줄에 연산의 개수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 만약 x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다. x는 231보다 작은 자연수 또는 0이고, 음의 정수는 입력으로 주어지지 않는다.
// 출력
// 입력에서 0이 주어진 횟수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.
// 예제 입력 1 
// 9
// 0
// 12345678
// 1
// 2
// 0
// 0
// 0
// 0
// 32
// 예제 출력 1 
// 0
// 1
// 2
// 12345678
// 0

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>



typedef struct mytree
{
    struct mytree* left;
    struct mytree* right; 
    int data;
} TREE;

TREE* Makenode(int data)
{
    TREE* newNode = (TREE*) malloc(sizeof(TREE));
    printf("MAKENODE 1\n"); 
    newNode->left = NULL; 
    newNode->right = NULL;
    newNode->data= data;  
    return newNode; 
}

TREE* insert(struct mytree* parent, int data)
{
    printf("insert 1\n"); 
    if (parent == NULL)
    {
        printf("insert 2\n"); 
        return Makenode(data);
    }
    if (parent->data > data)
    {
        parent->left =insert(parent -> left, data); 
    }
    else if (parent->data < data)
    {
        parent->right =insert(parent -> right, data); 
    }

    return parent;
}

void bstInOrderPrint(TREE* root)
{
    if (root != NULL) {
        bstInOrderPrint(root->left);
        printf("%d\n", (root->data));
        bstInOrderPrint(root->right);
    }
}

int main()
{
    struct mytree* ROOT = NULL;
    ROOT = insert(ROOT, 100);
    for(int i = 0; i <10; i++)
    {
        insert(ROOT,i);
        printf("Put in sucess %d\n", i);
    }
    printf("main 1\n");
    bstInOrderPrint(ROOT);
    printf("main 2\n");
    return 0;
}