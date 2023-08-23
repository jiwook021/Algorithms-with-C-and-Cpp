#include "Linked_List.h"

int random_number()
{
	return rand() % 9+1;
}

void example1(LinkedList* list)
{
	time_t t;
 	srand((unsigned) time(&t));	
	const uint8_t size = 16;
	bool errorcheck;
	for (int i=0;i<size;i++)
	{
		errorcheck = vInsertion(random_number(),list);
		if(false==errorcheck)
		{
			printf("\nERROR INSERTING"); 
		}
	}
	for (int i=0;i<size;i++)
	{
		errorcheck = vInsertionMid(random_number(), random_number(),list); //after insertion mid there is insertion problem
		if(false==errorcheck)
		{
			printf("\nERROR INSERTINGMID"); 
		}
	}
	printf("\nResult Linked List\n");
	vPrint(list);
	for (int i=0;i<size;i++)
	{
		if(i%4==0)
		printf("\n");
		vSearch(random_number(),list);
	}
	printf("\nResult Linked List\n");
	vPrint(list);
	for (int i=0;i<size*2;i++)
	{
		if(i%4==0)
			printf("\n");
		errorcheck =vRemove(random_number(),list);
		if(false==errorcheck)
		{
			printf("\nERROR Removing"); 
		}
	}	
	printf("\nResult Linked List\n");
	vPrint(list);
	vsort_single_linked_list(list);
	vPrint(list);
}

void example2(LinkedList* list)
{
	int iInput, iSelection;
	while (true)
	{
		printf("\nint(0 to insert) (1 to remove) (2 to search) space int (a number)\n\n");
		scanf("%d %d", &iSelection, &iInput);
		bool errorcheck;
		if (iSelection == 0)
		{
			errorcheck = vInsertion(iInput,list);
			if(false==errorcheck)
			{
				printf("\nERROR INSERTING"); 
			}
			vPrint(list);
		}
		if (iSelection == 1)
		{
			errorcheck =vRemove(iInput,list);
			if(false==errorcheck)
			{
				printf("\nERROR Removing"); 
			}
			vPrint(list);
		}
		if (iSelection == 2)
		{
			vSearch(iInput,list);		
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
	initLinkedList(&list);
	example1(&list);
	LinkedList list2;
	initLinkedList(&list2);
	example2(&list);
	return 0;
}
