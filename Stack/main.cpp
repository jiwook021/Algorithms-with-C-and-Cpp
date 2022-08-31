#include <iostream>
#include "stack.hpp"

int main()
{
	stack test; 


	time_t t;
   	srand((unsigned) time(&t));
	const uint8_t size = 30; 

	for(uint8_t i =0; i < size; i++)
    {
		test.push(rand() % 88+11);
		std::cout << "Peek: "<<test.peek(); 
		std::cout<<std::endl;
	}

	for(uint8_t i =1; i < size; i++)
    {
		test.pop(); 
		std::cout << "\tPeek: "<<test.peek(); 
		std::cout<<std::endl;
	}
	
}


