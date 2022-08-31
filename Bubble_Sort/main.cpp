#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <iomanip> 


#define ArrayLength 100

void PrintArray(int arr[ArrayLength])
{
    for(int i =0; i <ArrayLength; i++)
    {
        std::cout<< arr[i] <<" "; 
    }
}

void InputRandomNumber_ToArray(int arr[ArrayLength])
{
    for(int i =0; i <ArrayLength; i++)
    {
         arr [i] = rand() % 10 + 1;
    }
}
int main()
{ 

    int temp; 
    clock_t starttime,endtime;
    starttime = clock();
    
    
    srand (time(NULL));
    
    int arr [ArrayLength];

    InputRandomNumber_ToArray(arr);

    std::cout<<"Before Bubble Sort Array: \n";

    PrintArray(arr);
    
    for(int i =0; i<ArrayLength-1; i++)
    {
        for(int j=0; j <ArrayLength-i-1; j++)
        {
            if (arr[j+1]<arr[j]) 
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }

        }
    }

    std::cout<<"\n\nAfter Bubble Sort Array: \n";
    
    PrintArray(arr);
    
    std::cout<<std::endl;
    
    endtime = clock();
    
    double time_taken = double(endtime - starttime)/ double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program is : " << std::fixed << time_taken << std::setprecision(10);
    std::cout << " sec " << std::endl;

    return 0;
}