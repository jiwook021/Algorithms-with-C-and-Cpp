#include <iostream>
#include "Binary_tree.hpp"
#include "Binary_Search_Tree.hpp"

int main()
{
	/*
	btreeNode* bstRoot;
	btreeNode* sNode; 

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 3);
*/
	

	btreeNode* avlRoot;
	
	BSTMakeAndInit(&avlRoot);

	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);

	Travelpreorder(avlRoot);


	btreeNode* sNode; 
	sNode = BSTSearch(avlRoot, 6);

	printf("\nSearching for 6\n");

	if (sNode == nullptr)
		printf("Failed Search \n");
	else
		printf("Sucessful key: %d \n", BSTGetNodeData(sNode));

	return 0; 
}