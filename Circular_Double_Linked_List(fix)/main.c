#include "Circular_doublelinkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int random_number()
{
	return rand() % 20;
}

int idelete_random_number()
{
	return rand() % 10;
}


void example1()
{
	for(int i=0;i<=15;i++)
	{
		vInsert(i);
	}
	vPrint();
	
	time_t t;
 	srand((unsigned) time(&t));	
	
	for(int i=0; i<15;i++)
	{
		vSearch((random_number()));
	}
	
	
	for(int i=0;i<=10;i++)
	{
		vRemove(idelete_random_number());
	}
	
	vPrint();

}

void example2()
{
	int iInput, iSelection;
	while (1)
	{
		printf("\n\nInsert Node with 0 or Delete Node with 1 and Number\n");
		scanf("%d %d", &iSelection, &iInput);
		if (iSelection == 0)
		{
			vInsert(iInput);
		}
		if (iSelection == 1)
		{
			vRemove(iInput);
		}
		if ((iSelection == -1) && (iInput == -1))
		{
			return;
		}
		vPrint();
	}
}

int main()
{
	example1();
	example2();
	return 0;
}