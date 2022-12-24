#include "Hash_Table.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void TBLinit(Table *pt, HashFunc* f)
{

    /*  table pt->(slot)tbl memory
        tbl[1]                       tbl[2]      ....           tbl[MAX_TBL]  
          |                            |                          |     
        [][][status=EMPTY]     [][][status=EMPTY]           [][][status=EMPTY] 
    */
    for (int i= 0; i<MAX_TBL; i++)
        (pt->tbl[i]).status = EMPTY;

    /*
    pt memory 
    hf address points to hash function f
    */
    pt->hf = f;
}

Person * MakePersonData(int ssn, char *name, char *addr)
{
    Person *newP = (Person*) malloc(sizeof(Person));
    newP->ssn = ssn; 
    strcpy(newP->name,name);
    strcpy(newP->addr, addr);
    return newP;//return memory address of newP
}

const int GetSSN(Person *p)
{
    return p->ssn;
}

void TBLInsert(Table *pt, Key k, Value v)
{
    int hv = pt->hf(k); //hashfunction(k) return value = hv 

    /*  table pt->(slot)tbl memory
        tbl[hashfuntion(k)]            
          |                                                          
        [key][val][status=INUSE]      
    */
    pt->tbl[hv].key = k;
    pt->tbl[hv].val = v;
    pt->tbl[hv].status = INUSE;

    printf("Inserted SSN: %d ", v->ssn);
    printf("Name: %s ", v->name);
    printf("Address: %s \n", v->addr);
}

void ShowPerInfo(Person *p)
{
    printf("SSN: %d \n", p->ssn);
    printf("Name: %s \n", p->name);
    printf("Address: %s \n\n", p->addr);
}




Value TBLDelete(Table *pt, Key k)
{
    int hv = pt ->hf(k); //return of hashfunction(k)

    if((pt->tbl[hv]).status != INUSE)//if status is deleted or empty just return NULL
    {
        return NULL;
    }
    
    else
    {
        (pt->tbl[hv]).status = DELETED;//change the status to deleted 
        return (pt -> tbl[hv]).val;
    }
}

Value TBLSearch(Table *pt, Key k)
{
    int hv = pt ->hf(k);

    if((pt->tbl[hv]).status != INUSE) //if status is deleted or empty just return NULL
        return NULL;
    else
        return (pt->tbl[hv]).val;
}