#include <iostream>
#include "Binary_tree.h"
#include "Binary_Search_Tree.hpp"

int main()
{
	btreeNode* avlRoot;	
	BSTMakeAndInit(&avlRoot);
	for(int i = 1; i<=7; i++)
	{
		BSTInsert(&avlRoot, i);	
	}
	std::cout<<"\nTravel Pre Order"<<std::endl; 
	Travelpreorder(avlRoot);
	std::cout<<"\nTravel in Order"<<std::endl; 
	Travelinorder(avlRoot);
	std::cout<<"\nTravel Post Order"<<std::endl; 
	Travelpostorder(avlRoot);
	btreeNode* sNode; 
	std::cout<<"\n\nSearching for 6 Using Binaray Search Tree"<<std::endl;
	sNode = BSTSearch(avlRoot, 6);
	if (sNode == nullptr)
		printf("Failed Search \n");
	else
		printf("\nSucessfully Found key: %d \n", BSTGetNodeData(sNode));
	std::cout<<"\n\nSearching for 21 Using Binaray Search Tree"<<std::endl;
	sNode = BSTSearch(avlRoot, 21);
	if (sNode == nullptr)
		printf("Failed Search \n");
	else
		printf("\nSucessfully Found key: %d \n", BSTGetNodeData(sNode));
			std::cout<<"\n\nSearching for 21 Using Binaray Search Tree"<<std::endl;
	sNode = BSTSearch(avlRoot, 5);
	if (sNode == nullptr)
		printf("Failed Search \n");
	else
		printf("\nSucessfully Found key: %d \n", BSTGetNodeData(sNode));

	return 0; 
}