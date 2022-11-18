#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <stdint.h>

const static uint16_t ArrayLength = 100;

static void PrintArray(int arr[ArrayLength])
{
    for(int i =0; i <ArrayLength; i++)
    {
        printf("%d ",arr[i]); 
    }
}

static void InputRandomNumber_ToArray(int arr[ArrayLength])
{
    for(int i =0; i <ArrayLength; i++)
    {
         arr [i] = rand() % 10 + 1;
    }
}

static void vBubbleSort(int arr[ArrayLength])
{
    int temp;  
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
}

int main()
{ 
    clock_t starttime,endtime;
    starttime = clock();
    srand (time(NULL));

   
    int arr [ArrayLength];

    InputRandomNumber_ToArray(arr);

    printf("Before Bubble Sort Array: \n");
    PrintArray(arr);

    vBubbleSort(arr);
    printf("\n\nAfter Bubble Sort Array: \n");
    PrintArray(arr);
    printf("\n");
    
    endtime = clock();
    
    double time_taken = (double)(endtime - starttime)/ (double)(CLOCKS_PER_SEC);
    printf("Time taken by program is : %10f sec\n",time_taken);

    return 0;
}