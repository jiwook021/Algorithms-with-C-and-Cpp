#ifndef ___Priority_Queue__H____
#define ___Priority_Queue__H____

typedef char HData; 
typedef int Priority;

#define HEAP_LEN 100 
/*
Priority Queue is an extension of the queue with the following properties:  

Every item has a priority associated with it.
An element with high priority is dequeued before an element with low priority.
If two elements have the same priority, they are served according to their order in the queue.

A Binary Heap is a Binary Tree with the following properties:  

It is a Complete Tree. This property of Binary Heap makes them suitable to be stored in an array.
A Binary Heap is either Min Heap or Max Heap. 
In a Min Binary Heap, the key at the root must be minimum among all keys present in Binary Heap. 
The same property must be recursively true for all nodes in Binary Tree.
Similarly, in a Max Binary Heap, the key at the root must be maximum among all keys present in Binary Heap. 
The same property must be recursively true for all nodes in Binary Tree.
*/
typedef struct _heapElem
{
	Priority pr;
	HData data;
}HeapElem; 

//[heapElem[pr, data] numofdata][0] ... [heapElem[pr, data] numofdata][HEAP_LEN]
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

