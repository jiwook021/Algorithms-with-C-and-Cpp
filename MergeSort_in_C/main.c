#include <stdio.h>

void merge(int arr[], int tmp[],int start, int mid, int end)
{
    for(int i=start;i<=end;i++)
    {
        tmp[i] = arr[i];
    }
    int part1= start;
    int part2= mid+1;
    int index = start;
    while(part1 <= mid && part2 <=end)
    {
        if (tmp[part2]>tmp[part1])
        {
           arr[index++] = tmp[part1++];
        }
        else
        {
            arr[index++] = tmp[part2++];
        } 
    }
    while(part1<=mid)
    {
        arr[index++] = tmp[part1++];   
    }
}

void mergesort(int arr[],int tmp[], int start,int end)
{
    if(start<end)
    {
        int mid = (start + end)/2;     
        mergesort(arr,tmp,start,mid);
        mergesort(arr,tmp,mid+1,end);    
        merge(arr,tmp,start,mid,end);
    }
}

void Mergesort(int arr[])
{ 
    int tmp[8];
    mergesort(arr,tmp,0,8);
}

int main()
{
    int arr[8] = {10,2,3,4,5,6,7,3};
    Mergesort(arr);
    for(int i =0;i<8;i++)
    {
        printf("%d\n",arr[i]);
    }
}
