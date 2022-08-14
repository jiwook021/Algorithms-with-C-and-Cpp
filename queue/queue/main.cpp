#include <iostream>
#include "queue.hpp"

int main()
{
	queue test; 
	test.enqueue(1);
	std::cout << "\nPeek: "<<test.peek() << std::endl; 
	test.enqueue(2);
	std::cout << "\nPeek: "<< test.peek() << std::endl;
	test.enqueue(3);
	std::cout << "\nPeek: "<< test.peek() << std::endl;
	test.enqueue(4);
	std::cout << "\nPeek: "<< test.peek() << std::endl;
	test.enqueue(5);
	
	test.dequeue(); 
	std::cout << "\nPeek: "<< test.peek() << std::endl;
	test.dequeue();
	std::cout << "\nPeek: "<< test.peek() << std::endl;
	test.dequeue();
	std::cout << "\nPeek: "<< test.peek() << std::endl;
	test.dequeue();
	std::cout << "\nPeek: "<< test.peek() << std::endl;
	test.dequeue();
	
	printf("\n\n");
}


