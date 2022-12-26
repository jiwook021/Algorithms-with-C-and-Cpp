#include "Priority_Queue.h"
#include <stdbool.h>
#include <stdio.h>

void heapInit(heap* ph)
{
	ph->numOfData = 0; 
}

int HIsEmpty(heap* ph)
{
	if (ph->numOfData == 0)
		return true;
	else
		return false;
}

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}


int GetRChildIDX(int idx)

{
	return GetLChildIDX(idx) + 1; 
}
// pr 3
//  	0[1] 
// 	1[2]  	   2[3] 
//3[4] 4[5]  5[6] 6[7]
//
//
void HInsert(heap* ph, HData data, Priority pr)
{
	int idx = ph->numOfData + 1; 
	HeapElem nelem ={ pr, data };
	//ph->heapArr[ph->numOfData + 1] = x;
	while (idx != 1)
	{
		if(pr<(ph->heapArr[GetParentIDX(idx)].pr))
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx); 
		}

		else 
			break;
	} 
	ph->heapArr[idx] = nelem; 
	ph->numOfData += 1; 
	printf("\nInserted %d with priority of %d ",(nelem.data),(nelem.pr));

}

int getHiPriChiledIDX(heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	else
	{
		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}

}

HData Hdelete(heap* ph)
{
	HData retData = (ph->heapArr[1]).data; 
	HeapElem lastElem = ph->heapArr[ph->numOfData]; 

	int parentIdx = 1; 
	int childIdx; 

	while (childIdx = getHiPriChiledIDX(ph, parentIdx))
	{
		if (lastElem.pr <= ph->heapArr[childIdx].pr)
			break;
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1; 
	return retData; 
}
