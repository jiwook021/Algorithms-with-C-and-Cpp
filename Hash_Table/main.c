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

    np = MakePersonData(19970707, "kim", "Seoul");
    TBLInsert(&myTbl, GetSSN(np),np);
    np = MakePersonData(19980709, "lim", "Seoul");
    TBLInsert(&myTbl, GetSSN(np),np);
    np = MakePersonData(19970708, "jim", "Seoul");
    TBLInsert(&myTbl, GetSSN(np),np);


    sp = TBLSearch(&myTbl, 19970707);
    if (sp!= NULL)
        ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 19970708);
    if (sp!= NULL)
        ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 19930702);
    if (sp!= NULL)
        ShowPerInfo(sp);


    rp = TBLDelete(&myTbl,19970707);
       if (rp!= NULL)
           free(rp);

       rp = TBLDelete(&myTbl,19980709);
          if (rp!= NULL)
              free(rp);

          rp = TBLDelete(&myTbl,19970707);
             if (rp!= NULL)
                 free(rp);


    return 0;
}
