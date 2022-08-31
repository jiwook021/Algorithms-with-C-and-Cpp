#include <iostream>
#include <cstdio>
#include <memory>
#include "doublelinkedlist.hpp"

int random_number()
{
	return rand() % 9+1;
}

int main()
{
	time_t t;
 	srand((unsigned) time(&t));	
	LinkedList list;

	for (int i=0;i<10;i++)
	{
	list.insert(random_number());
	}
	for (int i=0;i<10;i++)
	{
	list.insert(random_number(), random_number());
	}
	list.print();
	for (int i=0;i<10;i++)
	{
	list.search(random_number());
	}
	list.print();

	for (int i=0;i<3;i++)
	{
	list.remove(random_number());
	}	
	list.print();
	return 0;
}