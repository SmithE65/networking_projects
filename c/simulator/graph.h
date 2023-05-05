#ifndef GRAPH_H
#define GRAPH_H

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "net.h"
#include "interface.h"

#define TOPOLOGY_NAME_SIZE 32

typedef struct Graph
{
    char topology_name[TOPOLOGY_NAME_SIZE];
    Node **Nodes;
    size_t Count;
} Graph;

static inline Node *GetNodeByName(Graph *graph, char *name)
{
    assert(graph);
    assert(name);

    for (int i = 0; i < graph->Count; ++i) {
        if (strcmp(name, graph->Nodes[i]->Name) == 0)
        {
            return graph->Nodes[i];
        }
    }

    return NULL;
}

Graph *CreateNewGraph(char *name);
Node *CreateGraphNode(Graph *graph, char *name);

void DumpGraph(Graph *graph);

#endif