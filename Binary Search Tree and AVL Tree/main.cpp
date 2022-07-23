#include <iostream>
#include "Binary_tree.h"
#include "Binary_Search_Tree.h"

int main()
{
	/*
	btreeNode* bstRoot;
	btreeNode* sNode; 

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 3);

	sNode = BSTSearch(bstRoot, 1);

	if (sNode == nullptr)
		printf("Failed Search \n");
	else
		printf("Sucessful key: %d \n", BSTGetNodeData(sNode));

		*/

	btreeNode* avlRoot;
	btreeNode* clNode;
	btreeNode* crNode;

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


	return 0; 
}