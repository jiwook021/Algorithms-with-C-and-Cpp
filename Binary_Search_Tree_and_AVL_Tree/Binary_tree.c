#include "Binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

// btreenode memory info
// [data] = data (btreeNode*)[left] = NULL (btreeNode*)[right] =NULL
void initbtreeNode(int data, btreeNode* selfNode)
{
	selfNode->data = data;
	selfNode->left = NULL;
	selfNode->right = NULL;
}
const int GetData(btreeNode* selfNode)
{
	return selfNode->data;
}
void SetData(int data,btreeNode* selfNode)
{
	selfNode->data=data; 
}
btreeNode* GetLeftTree(btreeNode* selfNode)
{
	return selfNode->left; //bring pointer to left tree
}
btreeNode* GetRightTree(btreeNode* selfNode)
{
	return selfNode->right; //bring pointer to right tree
}
void MakeLeftTree(btreeNode* sub, btreeNode* selfNode)
{
	if (selfNode->left != NULL)
		free(selfNode->left);//delete left node

	selfNode->left = sub;
}
void MakeRightTree(btreeNode* sub,btreeNode* selfNode)
{
	if (selfNode->right != NULL)
		free(selfNode->right);//delete right node

	selfNode->right = sub;
}
//delete node = self -> left
//free self ->left, self -> left = NULL, returns previous selfNode ->left
btreeNode* RemoveLeftTree(btreeNode* selfNode)
{
	btreeNode* delNode = NULL;

	if (selfNode != NULL) {
		delNode = selfNode->left;
		
		free(selfNode->left); //delete left node
		selfNode->left = NULL; 
	}
	return delNode;
}
//delete node = self -> right
//free self ->right, self -> right = NULL, returns previous selfNode ->right
btreeNode* RemoveRightTree(btreeNode* selfNode)
{
	btreeNode* delNode = NULL;
	if (selfNode != NULL) {
		delNode = selfNode->right;
		free(selfNode->right); //delete left node
		selfNode->right = NULL;
	}
	return delNode;
}
void ChangeLeftTree(btreeNode* sub,btreeNode* selfNode)
{
	selfNode->left = sub; 
}
void ChangeRightTree(btreeNode* sub,btreeNode* selfNode)
{
	selfNode->right = sub; 
}
    //      [4pr] 
	// 	   /     \
	// 	 [2]      [6]
	// 	/ \      / \
	// [1]  [3]   [5]  [7]	
	// /\  /\   /\  /\
//    n n  n n n n  n n  
void Travelinorder(btreeNode * root)
{
	if (root == NULL)
	{
		return;
	}
	Travelinorder(GetLeftTree(root));
	printf("%d ", GetData(root));
	Travelinorder(GetRightTree(root));
}

   //        [4pr] 
	// 	   /     \
	// 	 [2]      [6]
	// 	/ \       / \
	// [1]  [3] [5]  [7]	
	// /\   /\  /\   / \
//    n n  n n n n  n  n  
void Travelpreorder(btreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", GetData(root));
	Travelpreorder(GetLeftTree(root));
	Travelpreorder(GetRightTree(root));
}

   //        [4pr] 
	// 	   /     \
	// 	 [2]      [6]
	// 	/ \       / \
	// [1]  [3] [5]  [7]	
	// /\   /\  /\  /\
//    n n  n n n n  n n  
void Travelpostorder(btreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Travelinorder(GetLeftTree(root));
	Travelinorder(GetRightTree(root));
	printf("%d ", GetData(root));
}