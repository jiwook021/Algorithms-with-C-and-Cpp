#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define STR_LEN 100 //maximum string length for name and address
#define MAX_TBL 100

typedef struct _person
{
    int ssn;
    char name[STR_LEN];
    char addr[STR_LEN];
} Person;


const int GetSSN(Person *p);
void ShowPerInfo(Person *p);
Person *MakePersonData(int ssn, char *name, char *addr);


typedef int Key;
typedef Person* Value;
typedef enum SlotStatus 
{
    EMPTY, DELETED, INUSE
} SlotStatus;

typedef struct _slot
{
    Key key;
    Value val;
    SlotStatus status;
} Slot;



typedef int HashFunc(Key K);

typedef struct _table
{
    Slot tbl[MAX_TBL];
    HashFunc *hf;
} Table;


void TBLinit(Table *pt, HashFunc *f);
void TBLInsert(Table *pt, Key k , Value v);
Value TBLDelete(Table *pt, Key k);
Value TBLSearch(Table *pt, Key K);





#endif // HASH_TABLE_H
