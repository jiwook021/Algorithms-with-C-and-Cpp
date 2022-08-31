#ifndef ___Priority_Queue__H____
#define ___Priority_Queue__H____

typedef char HData; 
typedef int Priority;

#define HEAP_LEN 100 

typedef struct _heapElem

{
	Priority pr;
	HData data;
}HeapElem; 


typedef struct _heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];

} heap;

void heapInit(heap *ph);
int HIsEmpty(heap* ph);
void HInsert(heap* ph, HData data, Priority pr); 
HData Hdelete(heap *ph); 

#endif 

