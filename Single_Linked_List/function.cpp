#define _CRT_SECURE_NO_WARNINGS
#include "Linked_List.hpp"
#include <stdio.h>
#include <stdlib.h>


void example1()
{
	LinkedList list;
	list.vInsertion(1);
	list.vInsertion(2);
	list.vInsertion(3);
	list.vSearch(1);
	list.vInsertion(4);
	list.vInsertion(5, 3);
	list.vPrint();
	list.vSearch(4);
	list.vRemove(1);
	list.vPrint();
}

void example2()
{
	LinkedList list;
	int iInput, iSelection;
	while (true)
	{
		printf("\n(0 to insert) (1 to remove) and a number\n\n");
		scanf("%d %d", &iSelection, &iInput);
		if (iSelection == 0)
		{
			list.vInsertion(iInput);
		}
		if (iSelection == 1)
		{

			list.vRemove(iInput);
		}
		if ((iSelection == -1) && (iInput == -1))
		{
			return;
		}
		list.vPrint();
	}
}

