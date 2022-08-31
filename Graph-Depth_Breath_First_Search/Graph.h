#ifndef GRAPH_H
#define GRAPH_H


#include <stdint.h>
#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
    int numV;
    int numE;
    List * adjList;
    int* visitInfo;
}ALGraph;

void GraphInit(ALGraph *pg, uint8_t nv);
void GraphDestory(ALGraph *pg);
void AddEdge(ALGraph *pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph * pg);
void DFShowGraphVertex(ALGraph* pg, int startV);
void BFShowGraphVertex(ALGraph *pg, int startV);

#endif // GRAPH_H
