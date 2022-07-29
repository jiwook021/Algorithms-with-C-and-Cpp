#define _CRT_SECURE_NO_WARNINGS
#include "Circular_doublelinkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void example1()
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	print();
	search(4);
	vRemove(3);
	print();

}
void example2()
{
	int iInput, iSelection;
	while (1)
	{
		scanf("%d %d", &iSelection, &iInput);
		if (iSelection == 0)
		{
			insert(iInput);
		}
		if (iSelection == 1)
		{
			vRemove(iInput);
		}
		if ((iSelection == -1) && (iInput == -1))
		{
			return;
		}
		print();
	}
}

int main()
{
	example1();
	printf("\n\nInsert Node with 0 or Delete Node with 1 and Number\n");
	example2();
	return 0;
}