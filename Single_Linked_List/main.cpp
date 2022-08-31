#include <iostream>
#include <stdlib.h>
#include "Linked_List.hpp"

int random_number()
{
	return rand() % 9+1;
}

void example1(LinkedList &list)
{
	time_t t;
 	srand((unsigned) time(&t));	

	const uint8_t size = 16;
	for (int i=0;i<size;i++)
	{
	list.vInsertion(random_number());
	}
	for (int i=0;i<size;i++)
	{
	list.vInsertion(random_number(), random_number());
	}
	printf("\nResult Linked List\n");
	list.vPrint();
	for (int i=0;i<size;i++)
	{
	if(i%4==0)
		printf("\n");
	list.vSearch(random_number());
	}
	printf("\nResult Linked List\n");
	list.vPrint();

	for (int i=0;i<size*2;i++)
	{
	if(i%4==0)
		printf("\n");
	list.vRemove(random_number());
	}	
	printf("\nResult Linked List\n");
	list.vPrint();
}

void example2(LinkedList &list)
{
	int iInput, iSelection;
	while (true)
	{
		printf("\nint(0 to insert) (1 to remove) (2 to search) space int (a number)\n\n");
		scanf("%d %d", &iSelection, &iInput);
		if (iSelection == 0)
		{
			list.vInsertion(iInput);
			list.vPrint();
		}
		if (iSelection == 1)
		{

			list.vRemove(iInput);
			list.vPrint();
		}
		if (iSelection == 2)
		{
			list.vSearch(iInput);		
		}
		if ((iSelection == -1) && (iInput == -1))
		{
			return;
		}
	}
}

int main()
{
	LinkedList list;
	LinkedList *plist = &list;
	example1(*plist);
	LinkedList list2;
	LinkedList *plist2 = &list2;
	example2(*plist2);

	return 0;
}
