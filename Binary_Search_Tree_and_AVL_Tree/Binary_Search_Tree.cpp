#include "Binary_Search_Tree.hpp"
#include "AVLRebalance.hpp"
#include <cstdlib>

void BSTMakeAndInit(btreeNode** Parent_Root)
{
	*Parent_Root = nullptr; 
}

const int BSTGetNodeData(btreeNode* Binary_Search_tree_Node)
{
	return GetData(Binary_Search_tree_Node);
}

btreeNode* BSTInsert(btreeNode** Parent_Root, int data)
{
	if (*Parent_Root == NULL)
	{
		*Parent_Root = (btreeNode*) malloc (sizeof(btreeNode));

		initbtreeNode(data,*Parent_Root);
	}
	else if (data < GetData(*Parent_Root))
	{
		BSTInsert(&((*Parent_Root)->left), data);
		*Parent_Root = Rebalance(Parent_Root);
	}
	else if (data > GetData(*Parent_Root))
	{
		BSTInsert(&((*Parent_Root)->right), data);
		*Parent_Root = Rebalance(Parent_Root);
	}
	else
	{
		return NULL;
	}
	return *Parent_Root;
}

btreeNode* BSTSearch(btreeNode* Binary_Search_tree_Node, int target)
{
	btreeNode* Child_Node = Binary_Search_tree_Node; 
	int cd;
	while (Child_Node != nullptr)
	{
		cd = GetData(Child_Node);
		if (target == cd)
			return Child_Node;
		else if (target < cd)
			Child_Node = GetLeftTree(Child_Node);
		else
			Child_Node = GetRightTree(Child_Node);
	}
	return nullptr; 
}

btreeNode* BSTRemove(btreeNode** Parent_Root, int target)
{
	//btreeNode* pVRoot = new btreeNode(0);
	btreeNode *pVRoot = (btreeNode*) malloc (sizeof(btreeNode));
	initbtreeNode(0,*Parent_Root);
	btreeNode* pNode = pVRoot;
	btreeNode* Child_Node = *Parent_Root; 
	btreeNode* dNode;
	ChangeRightTree(*Parent_Root,pVRoot);
	while (Child_Node != nullptr && GetData(Child_Node) != target)
	{
		pNode = Child_Node; 

		if (target < GetData(Child_Node))
			Child_Node = GetLeftTree(Child_Node);
		else
			Child_Node = GetRightTree(Child_Node); 
	}
	if (Child_Node == nullptr)
		return nullptr;
	dNode = Child_Node; 
	if (GetLeftTree(dNode) == nullptr && GetRightTree(dNode) == nullptr)
	{
		if (GetLeftTree(pNode) == dNode)
			RemoveLeftTree(pNode);
		else
			RemoveRightTree(pNode); 
	}
	else if (GetLeftTree(dNode) == nullptr || GetRightTree(dNode) == nullptr)
	{
		btreeNode* dcNode; 

		if (GetLeftTree(dNode) != nullptr)
			dcNode = GetLeftTree(dNode);
		else 
			dcNode = GetRightTree(dNode);

		if (GetLeftTree(pNode) == dNode)
			ChangeLeftTree(dcNode,pNode);
		else
			ChangeRightTree(dcNode,pNode);
	}
	else
	{
		btreeNode* mNode = GetRightTree(dNode); 
		btreeNode* mpNode = dNode; 
		int delData; 

		while (GetLeftTree(mNode) != nullptr) {
			mpNode = mNode;
			mNode = GetLeftTree(mNode); 
		}
		delData = GetData(dNode); 
		SetData(GetData(mNode),dNode);

		if (GetLeftTree(mpNode) == mNode)
			ChangeLeftTree(GetRightTree(mNode),mpNode);
		else
			ChangeRightTree(GetRightTree(mNode),mpNode);

		dNode = mNode; 
		SetData(delData,dNode);
	}

	if (GetRightTree(pVRoot) != *Parent_Root)
		*Parent_Root = GetRightTree(pVRoot);
	free(pVRoot);
	Rebalance(Parent_Root);
	return dNode; 
}