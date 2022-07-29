#include "Binary_Search_Tree.hpp"
#include "AVLRebalance.hpp"
#include <malloc.h>

void BSTMakeAndInit(btreeNode** Parent_Root)
{
	*Parent_Root = nullptr; 
}

int BSTGetNodeData(btreeNode* Binary_Search_tree_Node)
{
	return Binary_Search_tree_Node->GetData();
}

btreeNode* BSTInsert(btreeNode** Parent_Root, int data)
{
	if (*Parent_Root == NULL)
	{
		*Parent_Root = new btreeNode(data);
	}
	else if (data < (*Parent_Root)->GetData())
	{
		BSTInsert(&((*Parent_Root)->left), data);
		*Parent_Root = Rebalance(Parent_Root);
	}
	else if (data > (*Parent_Root)->GetData())
	{
		BSTInsert(&((*Parent_Root)->right), data);
		*Parent_Root = Rebalance(Parent_Root);
	}
	else
	{
		return nullptr;
	}
	return *Parent_Root;
}

btreeNode* BSTSearch(btreeNode* Binary_Search_tree_Node, int target)
{
	btreeNode* Child_Node = Binary_Search_tree_Node; 
	int cd;

	while (Child_Node != nullptr)
	{
		cd = Child_Node->GetData();
		if (target == cd)
			return Child_Node;
		else if (target < cd)
			Child_Node = Child_Node->GetLeftTree();
		else
			Child_Node = Child_Node->GetRightTree();
	}
	return nullptr; 
}

btreeNode* BSTRemove(btreeNode** Parent_Root, int target)
{
	btreeNode* pVRoot = new btreeNode(0);
	btreeNode* pNode = pVRoot;
	btreeNode* Child_Node = *Parent_Root; 
	btreeNode* dNode;

	pVRoot->ChangeRightTree(*Parent_Root);

	while (Child_Node != nullptr && Child_Node->GetData() != target)
	{
		pNode = Child_Node; 

		if (target < Child_Node->GetData())
			Child_Node = Child_Node->GetLeftTree();
		else
			Child_Node = Child_Node->GetRightTree(); 
	}

	if (Child_Node == nullptr)
		return nullptr;

	dNode = Child_Node; 

	if (dNode->GetLeftTree() == nullptr && dNode->GetRightTree() == nullptr)
	{
		if (pNode->GetLeftTree() == dNode)
			pNode->RemoveLeftTree();
		else
			pNode->RemoveRightTree(); 
	}
	else if (dNode->GetLeftTree() == nullptr || dNode->GetRightTree() == nullptr)
	{
		btreeNode* dcNode; 

		if (dNode->GetLeftTree() != nullptr)
			dcNode = dNode->GetLeftTree();
		else 
			dcNode = dNode->GetRightTree();

		if (pNode->GetLeftTree() == dNode)
			pNode->ChangeLeftTree(dcNode);
		else
			pNode->ChangeRightTree(dcNode);
	}
	else
	{
		btreeNode* mNode = dNode->GetRightTree(); 
		btreeNode* mpNode = dNode; 
		int delData; 

		while (mNode->GetLeftTree() != nullptr) {
			mpNode = mNode;
			mNode = mNode->GetLeftTree(); 
		}

		delData = dNode->GetData(); 
		dNode->SetData(mNode->GetData());

		if (mpNode->GetLeftTree() == mNode)
			mpNode->ChangeLeftTree(mNode->GetRightTree());
		else
			mpNode->ChangeRightTree(mNode->GetRightTree());

		dNode = mNode; 

		dNode->SetData(delData);

	}

	if (pVRoot->GetRightTree() != *Parent_Root)
		*Parent_Root = pVRoot->GetRightTree();
	free(pVRoot);
	Rebalance(Parent_Root);
	return dNode; 
}
