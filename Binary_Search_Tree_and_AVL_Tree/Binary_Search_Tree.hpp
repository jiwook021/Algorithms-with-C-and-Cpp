#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__
#include "Binary_tree.h"

void BSTMakeAndInit(btreeNode ** pRoot); 
const int BSTGetNodeData(btreeNode* bst); 
btreeNode* BSTInsert(btreeNode** pRoot, int data); 
btreeNode* BSTSearch(btreeNode* bst, int target);
btreeNode* BSTRemove(btreeNode** pRoot, int target);
#endif