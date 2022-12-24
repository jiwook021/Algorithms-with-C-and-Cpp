#include "Hash_Table.h"
#include <stdio.h>
#include <stdlib.h>

int MyHashFunc(int k)
{
    return k%100;
}

int main()
{
    Table myTbl;
    Person *np;
    Person *sp;
    Person *rp;

    TBLinit(&myTbl, MyHashFunc);

    np = MakePersonData(11111111, "kim", "Seoul");
    TBLInsert(&myTbl, GetSSN(np),np);

    np = MakePersonData(22222222, "lim", "Seoul");
    TBLInsert(&myTbl, GetSSN(np),np);
    
    np = MakePersonData(33333333, "jim", "Seoul");
    TBLInsert(&myTbl, GetSSN(np),np);

    // np = MakePersonData(33333333, "mim", "Busan");
    // TBLInsert(&myTbl, GetSSN(np),np);

    int searchname1 = 22222222; 

    sp = TBLSearch(&myTbl, searchname1);
    if (sp!= NULL)
    {
        printf("\nSearched: ");
        ShowPerInfo(sp);
    }
    else
    {
        printf("Failed to Search %d ", searchname1);
    }

    int searchname2 = 44444444; 

    sp = TBLSearch(&myTbl, searchname2);
    if (sp!= NULL)
    {
        printf("Searched: ");
        ShowPerInfo(sp);
    }
    else
    {
        printf("Failed to Search %d ", searchname2);
    }

     int searchname3 = 11111111; 

    sp = TBLSearch(&myTbl, searchname3);
    if (sp!= NULL)
    {
        printf("Searched: ");
        ShowPerInfo(sp);
    }
     else
    {
       printf("Failed to Search %d ", searchname3);
    }

    // int searchname4 = 33333333; 

    // sp = TBLSearch(&myTbl, searchname4);
    // if (sp!= NULL)
    // {
    //     printf("Searched: ");
    //     ShowPerInfo(sp);
    // }
    //  else
    // {
    //    printf("Failed to Search %d ", searchname4);
    // }

    rp = TBLDelete(&myTbl,11111111);
     printf("deleted info of %s\n",rp->name );
    if (rp!= NULL)
        free(rp);

    rp = TBLDelete(&myTbl,22222222);
    printf("deleted info of %s\n",rp->name );
    if (rp!= NULL)
        free(rp);

    rp = TBLDelete(&myTbl,33333333);
    printf("deleted info of %s\n",rp->name );
    if (rp!= NULL)
        free(rp);

    printf("\nDeallocated Hash Table\n");
    return 0;
}
