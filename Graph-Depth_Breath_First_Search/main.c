#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

void testDFS()
{
    ALGraph graph;

    GraphInit(&graph,5);
    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, C, D);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, A);

    ShowGraphEdgeInfo(&graph);
    DFShowGraphVertex(&graph,A);
    GraphDestory(&graph);
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

    ShowGraphEdgeInfo(&graph);
    printf("==========BFS==========\n");
    BFShowGraphVertex(&graph,A);

    GraphDestory(&graph);
}

int main()
{
    testBFS();
    printf("\n");
    return 0;
}
