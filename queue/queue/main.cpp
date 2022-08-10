#include <iostream>
#include "queue.h"

int main()
{
	queue test; 
	test.enqueue(1);
	std::cout << test.peek() << std::endl; 
	test.enqueue(2);
	std::cout << test.peek() << std::endl;
	test.enqueue(3);
	std::cout << test.peek() << std::endl;
	test.enqueue(4);
	std::cout << test.peek() << std::endl;
	test.enqueue(5);
	
	test.dequeue(); 
	std::cout << test.peek() << std::endl;
	test.dequeue();
	std::cout << test.peek() << std::endl;
	test.dequeue();
	std::cout << test.peek() << std::endl;
	test.dequeue();
	std::cout << test.peek() << std::endl;
	test.dequeue();
	std::cout << test.peek() << std::endl;

}


