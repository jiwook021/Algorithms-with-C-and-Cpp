#include "AVLRebalance.h"
#include "Binary_Search_Tree.h"
#include "Binary_tree.h"
#include <iostream>






int GetHeight(btreeNode* bst)
{
	int leftH, rightH;


	if (bst == nullptr)
		return 0;

	leftH = GetHeight(bst->GetLeftTree());
	rightH = GetHeight(bst->GetRightTree());

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

int getHeightDiff(btreeNode* bst)
{
	int lsh, rsh; 

	if (bst == NULL)
		return 0; 

	lsh = GetHeight(bst->GetLeftTree());
	rsh = GetHeight(bst->GetRightTree());
	return lsh - rsh;
}


btreeNode* RotateLL(btreeNode* bst)
{
	btreeNode* pNode; 
	btreeNode* cNode;

	pNode = bst; 
	cNode = pNode->GetLeftTree(); 
	pNode->ChangeLeftTree(cNode->GetRightTree()); 
	cNode->ChangeRightTree(pNode);
	return cNode; 
}

btreeNode* RotateRR(btreeNode* bst)
{
	btreeNode* pNode;
	btreeNode* cNode;
	
	pNode = bst;
	cNode = pNode->GetRightTree();
	pNode->ChangeRightTree(cNode->GetLeftTree());
	cNode->ChangeLeftTree(pNode);
	return cNode;
}
btreeNode* RotateLR(btreeNode* bst)
{
	btreeNode* pNode;
	btreeNode* cNode;

	pNode = bst;
	cNode = pNode->GetLeftTree();
	pNode-> ChangeLeftTree(RotateRR(cNode));
	return RotateLL(pNode);
}

btreeNode* RotateRL(btreeNode* bst)
{
	btreeNode* pNode;
	btreeNode* cNode;

	pNode = bst;
	cNode = pNode->GetRightTree();
	pNode->ChangeRightTree(RotateLL(cNode));
	return RotateRR(pNode);
}

btreeNode* Rebalance(btreeNode** pRoot)
{
	int hDiff = getHeightDiff(*pRoot);

	if (hDiff > 1)
	{
		if (getHeightDiff((*pRoot)->GetLeftTree())>0)
		{
			*pRoot = RotateLL(*pRoot);
		}
		else
		{
			*pRoot = RotateLR(*pRoot);
		}
	}

	if (hDiff < -1)
	{
		if (getHeightDiff((*pRoot)->GetRightTree()) < 0)
		{
			*pRoot = RotateRR(*pRoot);
		}
		else
		{
			*pRoot = RotateRL(*pRoot);
		}

	}

	return *pRoot; 
}