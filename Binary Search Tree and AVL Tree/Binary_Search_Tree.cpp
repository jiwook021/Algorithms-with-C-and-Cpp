#include "Binary_Search_Tree.h"
#include "AVLRebalance.h"
#include <malloc.h>

void BSTMakeAndInit(btreeNode** pRoot)
{
	*pRoot = nullptr; 
}

int BSTGetNodeData(btreeNode* bst)
{
	return bst->GetData();
}

btreeNode* BSTInsert(btreeNode** pRoot, int data)
{
	if (*pRoot == NULL)
	{
		*pRoot = new btreeNode(data);
	}
	else if (data < (*pRoot)->GetData())
	{
		BSTInsert(&((*pRoot)->left), data);
		*pRoot = Rebalance(pRoot);
	}
	else if (data > (*pRoot)->GetData())
	{
		BSTInsert(&((*pRoot)->right), data);
		*pRoot = Rebalance(pRoot);
	}
	else
	{
		return nullptr;
	}
	return *pRoot;
}

btreeNode* BSTSearch(btreeNode* bst, int target)
{
	btreeNode* cNode = bst; 
	int cd;

	while (cNode != nullptr)
	{
		cd = cNode->GetData();
		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = cNode->GetLeftTree();
		else
			cNode = cNode->GetRightTree();
	}


	return nullptr; 
}

btreeNode* BSTRemove(btreeNode** pRoot, int target)
{
	btreeNode* pVRoot = new btreeNode(0);
	btreeNode* pNode = pVRoot;
	btreeNode* cNode = *pRoot; 
	btreeNode* dNode;

	pVRoot->ChangeRightTree(*pRoot);

	while (cNode != nullptr && cNode->GetData() != target)
	{
		pNode = cNode; 

		if (target < cNode->GetData())
			cNode = cNode->GetLeftTree();
		else
			cNode = cNode->GetRightTree(); 
	}

	if (cNode == nullptr)
		return nullptr;

	dNode = cNode; 

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

	if (pVRoot->GetRightTree() != *pRoot)
		*pRoot = pVRoot->GetRightTree();
	free(pVRoot);
	Rebalance(pRoot);
	return dNode; 
}
