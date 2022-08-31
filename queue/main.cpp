#include <iostream>
#include <iomanip> 
#include "queue.hpp"

int main()
{
	clock_t starttime,endtime;
    starttime = clock();


	time_t t;
   	srand((unsigned) time(&t));
	const uint8_t size = 40; 
	
	queue test; 

	for(uint8_t i =0; i < size; i++)
    {
		test.enqueue(rand() % 80+11);
		std::cout << "Peek: "<<test.peek(); 
	}
	
	printf("\n\n");

	for(uint8_t i =0; i < size; i++)
    {
	std::cout << "\nPeek: "<< test.peek()<<"\t";
	test.dequeue(); 
	}
	
	printf("\n\n");

	endtime = clock();
    double time_taken = double(endtime - starttime)/ double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program is : " << std::fixed << time_taken << std::setprecision(10) << " sec " << std::endl;
	printf("\n");
	
}


