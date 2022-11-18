#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <stdint.h>

static const uint8_t ArrayLength = 100;

static void Insertionsort(uint8_t arr[],int n)
{
    static uint8_t insData;     
    int j; 
    int i;
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

static void PrintArray(uint8_t arr[ArrayLength])
{
    for(int i =0; i < ArrayLength; i++)
    {
        printf("%d ",arr[i]); 
    }
}

static void InputRandomNumber_ToArray(uint8_t arr[ArrayLength])
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
    uint8_t arr [ArrayLength];

    InputRandomNumber_ToArray(arr);

    printf("Before Insertion Sort\n");
    PrintArray(arr);

    Insertionsort(arr, sizeof(arr)/sizeof(uint8_t) ); 
    
    printf("\n\nAfter Insertion Sort\n");
    PrintArray(arr);
   

    printf("\n\n");
    endtime = clock();   
    
    double time_taken = (double)(endtime - starttime)/ (double)(CLOCKS_PER_SEC);
    printf("Time taken by program is : %.10f sec\n", time_taken);
    
    return 0; 
}