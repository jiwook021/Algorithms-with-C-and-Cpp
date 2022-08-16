#include <iostream>
#include "stack.hpp"

int main()
{
	stack test; 

	test.push(1);
	test.push(2);
	std::cout << "Peek: " << test.peek() << std:: endl;
	test.pop(); 
	std::cout << "Peek: " << test.peek() << std::endl;
}


