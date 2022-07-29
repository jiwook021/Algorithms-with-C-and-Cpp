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
	if (left != nullptr)
		delete left;

	left = sub;
}

void btreeNode::MakeRightTree(btreeNode* sub)
{
	if (right != nullptr)
		delete right;

	right = sub;
}

btreeNode* btreeNode::RemoveLeftTree()
{
	btreeNode* delNode = nullptr;

	if (this != nullptr) {
		delNode = this->left;
		this->left = nullptr; 
	}
	return delNode;
}

btreeNode* btreeNode::RemoveRightTree()
{

	btreeNode* delNode = nullptr;

	if (this != nullptr) {
		delNode = this->right;
		this->right = nullptr;
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
	std::cout << root->GetData()<< std::endl;
	Travelinorder(root->GetRightTree());
}

void Travelpreorder(btreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	std::cout << root->GetData() << std::endl;
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
	std::cout << root->GetData() << std::endl;
}

