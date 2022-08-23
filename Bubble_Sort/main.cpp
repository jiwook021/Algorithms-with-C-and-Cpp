#include <iostream>

int temp; 

int main()
{ 
    int arr [] = {10,7,5,3,4,1,2,6,8,9};  
    int LEGNTH = sizeof(arr)/sizeof(arr[0]);
    for(int i =0; i<LENGTH-1; i++)
    {
        for(int j=0; j <LENGTH-i-1; j++)
        {
            if (arr[j+1]<arr[j]) 
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }

        }
    }

    std::cout<<"Array: \n";
    for(int i =0; i <LENGTH; i++)
    {
        std::cout<< arr[i] <<" "; 
    } 
    return 0;
}