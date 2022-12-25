#include "AVLRebalance.hpp"
#include "Binary_Search_Tree.hpp"
#include "Binary_tree.h"
#include <iostream>

int GetHeight(btreeNode* Binary_Search_Tree)
{
	int leftH, rightH;

	if (Binary_Search_Tree == NULL)
		return 0;

	leftH = GetHeight(GetLeftTree(Binary_Search_Tree));
	rightH = GetHeight(GetRightTree(Binary_Search_Tree));

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

int getHeightDiff(btreeNode* Binary_Search_Tree)
{
	int left_search_height, right_search_height; 

	if (Binary_Search_Tree == NULL)
		return 0; 

	left_search_height = GetHeight(GetLeftTree(Binary_Search_Tree));
	right_search_height = GetHeight(GetRightTree(Binary_Search_Tree));
	return left_search_height - right_search_height;
}

btreeNode* RotateLL(btreeNode* Binary_Search_Tree)
{
	btreeNode* Parent_Node; 
	btreeNode* Child_Node;

	Parent_Node = Binary_Search_Tree; 
	Child_Node = GetLeftTree(Parent_Node); 
	ChangeLeftTree(GetRightTree(Child_Node),Parent_Node); 
	ChangeRightTree(Parent_Node,Child_Node);
	return Child_Node; 
}

btreeNode* RotateRR(btreeNode* Binary_Search_Tree)
{
	btreeNode* Parent_Node;
	btreeNode* Child_Node;
	
	Parent_Node = Binary_Search_Tree;
	Child_Node = GetRightTree(Parent_Node);
	ChangeRightTree(GetLeftTree(Child_Node),Parent_Node);
	ChangeLeftTree(Parent_Node,Child_Node);
	return Child_Node;
}

btreeNode* RotateLR(btreeNode* Binary_Search_Tree)
{
	btreeNode* Parent_Node;
	btreeNode* Child_Node;

	Parent_Node = Binary_Search_Tree;
	Child_Node = GetLeftTree(Parent_Node);
	ChangeLeftTree(RotateRR(Child_Node),Parent_Node);
	return RotateLL(Parent_Node);
}

btreeNode* RotateRL(btreeNode* Binary_Search_Tree)
{
	btreeNode* Parent_Node;
	btreeNode* Child_Node;

	Parent_Node = Binary_Search_Tree;
	Child_Node = GetRightTree(Parent_Node);
	ChangeRightTree(RotateLL(Child_Node),Parent_Node);
	return RotateRR(Parent_Node);
}

btreeNode* Rebalance(btreeNode** Parent_Root)
{
	int Height_Difference = getHeightDiff(*Parent_Root);

	if (Height_Difference > 1)
	{
		if (getHeightDiff(GetLeftTree((*Parent_Root)))>0)
		{
			*Parent_Root = RotateLL(*Parent_Root);
		}
		else
		{
			*Parent_Root = RotateLR(*Parent_Root);
		}
	}

	if (Height_Difference < -1)
	{
		if (getHeightDiff(GetRightTree((*Parent_Root))) < 0)
		{
			*Parent_Root = RotateRR(*Parent_Root);
		}
		else
		{
			*Parent_Root = RotateRL(*Parent_Root);
		}
	}
	return *Parent_Root; 
}