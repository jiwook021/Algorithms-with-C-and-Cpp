#include <iostream>
#include <set>

static int ary[10] = {1,2,3,4,1,1,1}; 



int main()
{
    std::set<int> set (ary, ary+1000);

    //[heap [1mb], stack [mb]]
    //heap 
    //stack 
    //data 
    for(std::set<int>::iterator it=set.begin(); it!= set.end();++it) 
    {
        std::cout<< *it <<' ';
    }

    int aray[10000]; 
    
    for(int i = 0; i<5000;i++)
    {
        aray[i] = i;
    }


    return 0;
}
