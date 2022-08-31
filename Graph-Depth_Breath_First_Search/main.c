#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

void testDFS()
{
    ALGraph graph2;
  
    GraphInit(&graph2,5);
    AddEdge(&graph2, A, B);
    AddEdge(&graph2, A, D);
    AddEdge(&graph2, B, C);
    AddEdge(&graph2, C, D);
    AddEdge(&graph2, D, E);
    AddEdge(&graph2, E, A);
  
    printf("\n====Show Graph INFO====\n");
    ShowGraphEdgeInfo(&graph2);
    printf("==========DFS==========\n");
    DFShowGraphVertex(&graph2,A);
  
    GraphDestory(&graph2);
}


void testBFS()
{
    ALGraph graph;
    GraphInit(&graph,5);
    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, C, D);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, A);
    printf("\n====Show Graph INFO====\n");
    ShowGraphEdgeInfo(&graph);
    printf("==========BFS==========\n");
    BFShowGraphVertex(&graph,A);
    GraphDestory(&graph);
}

int main()
{
    testBFS();
    printf("\n\n\n");
    testDFS();
    printf("\n\n");
    return 0;
}
