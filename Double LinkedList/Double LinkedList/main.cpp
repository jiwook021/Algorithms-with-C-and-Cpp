#include <iostream>
#include <cstdio>
#include "doublelinkedlist.h"

int main()
{
	LinkedList list;

	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5, 3);

	list.print();
	list.search(7); 

	list.remove(3);

	list.print();

	return 0;
}