#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

class btreeNode
{
public: 

	int data;
	btreeNode* left;
	btreeNode* right;

public: 

	btreeNode(int data);
	int GetData(); 
	void SetData(int data);
	btreeNode* GetLeftTree();
	btreeNode* GetRightTree();
	void MakeLeftTree(btreeNode* sub);
	void MakeRightTree(btreeNode* sub);

	btreeNode* RemoveLeftTree();
	btreeNode* RemoveRightTree();
	void ChangeLeftTree(btreeNode* sub);
	void ChangeRightTree(btreeNode* sub);
};

void Travelinorder(btreeNode* root);
void Travelpreorder(btreeNode* root);
void Travelpostorder(btreeNode* root); 

#endif