#include <iostream>
#include <iomanip> 
#include "LB_queue.h"

int main()
{
	//to mesure performence time	
	clock_t starttime,endtime;
    starttime = clock();
	time_t t;
   	srand((unsigned) time(&t));


	
	const uint8_t size = 40; 
	Queue test; 
	
	for(uint8_t i =0; i < size; i++)
    {
		test.enqueue(rand() % 80+11);
		std::cout << "Currnet Peek: "<<test.peek(); 
		printf("\n");
	}
	printf("\n");

	for(uint8_t i =0; i < size; i++)
    {
	std::cout << "Peek: "<< test.peek()<<"\t";
	std::cout <<"Dequeue: "<< test.dequeue() << std::endl;
	}
	printf("\n\n");

	
	
	
	
	endtime = clock();
    double time_taken = double(endtime - starttime)/ double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program is : " << std::fixed << time_taken << std::setprecision(10) << " sec " << std::endl;
	printf("\n");
	
}


