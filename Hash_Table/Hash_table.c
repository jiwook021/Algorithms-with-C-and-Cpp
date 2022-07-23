#include "Hash_Table.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GetSSN(Person *p)
{
    return p->ssn;
}

void ShowPerInfo(Person *p)
{
    printf("SSN: %d \n", p->ssn);
    printf("Name: %s \n", p->name);
    printf("Address: %s \n\n", p->addr);
}

Person * MakePersonData(int ssn, char *name, char *addr)
{
    Person *newP = (Person*) malloc (sizeof(Person));
    newP->ssn = ssn;
    strcpy(newP->name,name);
    strcpy(newP->addr, addr);
    return newP;
}


void TBLinit(Table *pt, HashFunc* f)
{
    for (int i= 0; i<MAX_TBL; i++)
        (pt->tbl[i]).status = EMPTY;

    pt->hf = f;
}

void TBLInsert(Table *pt, Key k, Value v)
{
    int hv = pt->hf(k);
    pt->tbl[hv].val = v;
    pt->tbl[hv].key = k;
    pt->tbl[hv].status = INUSE;
}

Value TBLDelete(Table *pt, Key k)
{
    int hv = pt ->hf(k);

    if((pt->tbl[hv]).status != INUSE)
    {
        return NULL;
    }
    else
    {
        (pt->tbl[hv]).status = DELETED;
        return (pt -> tbl[hv]).val;
    }

}

Value TBLSearch(Table *pt, Key k)
{
    int hv = pt ->hf(k);

    if((pt->tbl[hv]).status != INUSE)
        return NULL;
    else
        return (pt->tbl[hv]).val;
}

