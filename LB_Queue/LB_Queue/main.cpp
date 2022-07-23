#include <iostream>
#include "LB_queue.h"

int main()
{
	Queue test; 
	test.enqueue(1);
	std::cout << test.peek() << std::endl; 

	test.enqueue(2);

	std::cout << test.peek() << std::endl;

	test.enqueue(3);

	std::cout << test.peek() << std::endl;

	test.enqueue(4);

	std::cout << test.peek() << std::endl;

	test.enqueue(5);
	
	std::cout << test.dequeue() << std::endl;
	std::cout << test.dequeue() << std::endl;
	std::cout << test.dequeue() << std::endl;
	std::cout << test.dequeue() << std::endl;
	
}


