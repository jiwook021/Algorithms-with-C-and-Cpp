#include <iostream>
#include "stack.h"

int main()
{
	stack test; 

	test.push(1);
	test.push(2);
	std::cout << test.peek() << std:: endl;
	test.pop(); 
	std::cout << test.peek() << std::endl;
}


