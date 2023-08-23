#include "doublelinkedlist.h"

int random_number()
{
	return rand() % 9+1;
}
int random_number15()
{
	return rand() % 15+1;
}

int main()
{
	// time_t t;
 	// srand((unsigned) time(&t));	
	LinkedList list1;
	initLinkedList(&list1);
	bool check;
	for (int i=0;i<10;i++)
	{
  		check = insert(random_number(),&list1); 
		if (check == false)
		{
			printf("Error Inserting");
		}
	}
	for (int i=0;i<10;i++)
	{
		check = insertMid(random_number(), random_number(),&list1);
		if (check == false)
		{
			printf("Error Inserting Mid");
		}
	}
	printList(&list1);
	sort_double_Linkled_list(&list1);
	printf("Sorted List\n");
	printList(&list1);
	for (int i=0;i<10;i++)
	{
		search(random_number15(),&list1);
	}
	for (int i=0;i<10;i++)
	{
		Remove(random_number(),&list1);
	}	
	printList(&list1);
	return 0;
}

