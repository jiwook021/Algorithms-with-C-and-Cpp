#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <iomanip> 


static const uint8_t ArrayLength = 100;

static void PrintArray(int arr[ArrayLength])
{
    for(int i =0; i <ArrayLength; i++)
    {
        std::cout<< arr[i] <<" "; 
    }
}

static void InputRandomNumber_ToArray(int arr[ArrayLength])
{
    for(int i =0; i <ArrayLength; i++)
    {
         arr [i] = rand() % 10 + 1;
    }
}

static void MergeTwoArea(int arr[],int left, int mid, int right)
{
    int fIdx =left;
    int rIdx = mid+1; 
    int i;

    int *sortArr = (int*)malloc(sizeof(int)*(right+1));
    int sIdx = left; 

    while(fIdx <= mid && rIdx <= right)
    {    
        if(arr[fIdx]<=arr[rIdx])
            sortArr[sIdx] = arr[fIdx++];
        else 
            sortArr[sIdx] = arr[rIdx++]; 

        sIdx++; 
    }

    if(fIdx> mid)
    {
        for(i=rIdx; i<=right; i++ ,sIdx++)
            sortArr[sIdx] = arr[i];
    }
    else 
    {
        for(i=fIdx; i<=mid; i++,sIdx++)
            sortArr[sIdx] = arr[i];
    }

    for(i = left; i<=right;i++)
    {
        arr[i]=sortArr[i];
    }

    free(sortArr);
}

static void MergeSort(int arr[],int left,int right)
{
    int mid; 
    if(left<right) 
    {
        mid = (left+right)/2; 
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        MergeTwoArea(arr,left,mid,right);   
    }
}

int main(void)
{
    clock_t starttime,endtime;
    starttime = clock();
    srand (time(NULL));
    

    int arr [ArrayLength];
    
    InputRandomNumber_ToArray(arr);
    printf("\nBefore Merge Sort: ");
    PrintArray(arr);   
    MergeSort(arr,0,sizeof(arr)/sizeof(int)-1); 
    printf("\nAfter Merge Sort: ");
    PrintArray(arr);   
    printf("\n\n");

    endtime = clock();   
    double time_taken = double(endtime - starttime)/ double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program is : " << std::fixed << time_taken << std::setprecision(10);
    std::cout << " sec " << std::endl;
    return 0; 
}