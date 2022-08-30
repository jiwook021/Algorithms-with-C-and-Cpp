#include <iostream> 
#include <stdlib.h> 
#include <time.h>
#include <iomanip> 

void Insertionsort(int arr[],int n); 

#define ArrayLength 100


void Insertionsort(int arr[],int n)
{
    int i,j;
    int insData; 
    for(i=1;i<n;i++)
    {
        insData=arr[i];
        for(j=i-1; j>=0;j--)
        {
            if(arr[j]>insData)
                arr[j+1]= arr[j];
            else 
                break;
        }

        arr[j+1] =insData; 
    }
}

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

int main(void)
{
    clock_t starttime,endtime;
    starttime = clock();

    srand (time(NULL));   
    int arr [ArrayLength];

    InputRandomNumber_ToArray(arr);

    printf("Before Insertion Sort\n");
    PrintArray(arr);   
    Insertionsort(arr, sizeof(arr)/sizeof(int) ); 
    
    printf("\n\nAfter Insertion Sort\n");
    PrintArray(arr);
   

    printf("\n\n");
    endtime = clock();   
    double time_taken = double(endtime - starttime)/ double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program is : " << std::fixed << time_taken << std::setprecision(10);
    std::cout << " sec " << std::endl;
    
    return 0; 
}