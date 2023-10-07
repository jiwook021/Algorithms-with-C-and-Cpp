#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

// btreenode memory info
// [data] (btreeNode*)[left] (btreeNode*)[right]
typedef struct btreeNode 
{
	int data;
	struct btreeNode* left;
	struct btreeNode* right;
}btreeNode; 

void initbtreeNode(int data,btreeNode* selfNode);
const int GetData(btreeNode* selfNode); 
void SetData(int data,btreeNode* selfNode);
btreeNode* GetLeftTree(btreeNode* selfNode);
btreeNode* GetRightTree(btreeNode* selfNode);
void MakeLeftTree(btreeNode* sub,btreeNode* selfNode);
void MakeRightTree(btreeNode* sub,btreeNode* selfNode);
btreeNode* RemoveLeftTree(btreeNode* selfNode);
btreeNode* RemoveRightTree(btreeNode* selfNode);
void ChangeLeftTree(btreeNode* sub,btreeNode* selfNode);
void ChangeRightTree(btreeNode* sub,btreeNode* selfNode);
void Travelinorder(btreeNode* root);
void Travelpreorder(btreeNode* root);
void Travelpostorder(btreeNode* root); 

#endif