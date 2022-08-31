#include "Binary_tree.hpp"
#include <iostream>

btreeNode::btreeNode(int data)
{
	this->data = data;
	left = nullptr;
	right = nullptr;
}

int btreeNode::GetData()
{
	return this->data;
}

void btreeNode::SetData(int data)
{
	this->data=data; 
}

btreeNode* btreeNode::GetLeftTree()
{
	return left;
}

btreeNode* btreeNode::GetRightTree()
{
	return right;
}

void btreeNode::MakeLeftTree(btreeNode* sub)
{
	if (left != NULL)
		delete left;

	left = sub;
}

void btreeNode::MakeRightTree(btreeNode* sub)
{
	if (right != NULL)
		delete right;

	right = sub;
}

btreeNode* btreeNode::RemoveLeftTree()
{
	btreeNode* delNode = NULL;

	if (this != NULL) {
		delNode = this->left;
		this->left = NULL; 
	}
	return delNode;
}

btreeNode* btreeNode::RemoveRightTree()
{
	btreeNode* delNode = NULL;
	if (this != NULL) {
		delNode = this->right;
		this->right = NULL;
	}
	return delNode;
}

void btreeNode::ChangeLeftTree(btreeNode* sub)
{
	left = sub; 
}

void btreeNode::ChangeRightTree(btreeNode* sub)
{
	right = sub; 
}

void Travelinorder(btreeNode * root)
{
	if (root == nullptr)
	{
		return;
	}
	Travelinorder(root->GetLeftTree());
	std::cout << root->GetData()<< " ";
	Travelinorder(root->GetRightTree());
}

void Travelpreorder(btreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	std::cout << root->GetData() << " ";
	Travelpreorder(root->GetLeftTree());
	Travelpreorder(root->GetRightTree());
}

void Travelpostorder(btreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	Travelinorder(root->GetLeftTree());
	Travelinorder(root->GetRightTree());
	std::cout << root->GetData() << " ";
}
