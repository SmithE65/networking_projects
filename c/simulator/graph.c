#include "graph.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

void set_string(char *dest, const char *src, size_t max) {
    strncpy(dest, src, max - 1);
    dest[max] = '\0';
}

Graph *CreateNewGraph(char *name) {
    Graph *graph = calloc(1, sizeof(Graph));
    assert(graph);
    set_string(graph->topology_name, name, TOPOLOGY_NAME_SIZE);
    graph->Count = 4;
    graph->Nodes = calloc(graph->Count, sizeof(Node));
    return graph;
}

void AddNode(Graph *graph, Node *node) {
    for (int i = 0; i < graph->Count; ++i) {
        if (graph->Nodes[i] == NULL) {
            graph->Nodes[i] = node;
            return;
        }
    }

    graph->Count = graph->Count * 2;
    Node **expanded = realloc(graph->Nodes, graph->Count);
    if (expanded != NULL) {
        graph->Nodes = expanded;
    }
}

Node *CreateGraphNode(Graph *graph, char *name) {
    assert(graph);
    Node *node = calloc(1, sizeof(Node));
    assert(node);
    set_string(node->Name, name, NODE_NAME_SIZE);
    AddNode(graph, node);

    return node;
}

void DumpNode(Node *node);

void DumpInterface(Interface *interface);

void DumpGraph(Graph *graph) {
    assert(graph);
    assert(graph->Nodes);
    printf("Topology Name = %s\n", graph->topology_name);

    for (int i = 0; i < graph->Count; ++i) {
        DumpNode(graph->Nodes[i]);
    }

    printf("\n\n");
}

void PrintIpAddress(IpAddress *address) {
    printf("%d.%d.%d.%d",
           (unsigned char) address->Address[0],
           (unsigned char) address->Address[1],
           (unsigned char) address->Address[2],
           (unsigned char) address->Address[3]);
}

void DumpNode(Node *node) {
    assert(node);
    printf("\nNode Name = %s\n\tlo addr: ", node->Name);

    if (node->Properties.IsLoopback) {
        PrintIpAddress(&node->Properties.IpAddress);
        printf("/32\n");
    }

    for (size_t i = 0; i < NODE_INTERFACE_MAX; i++) {
        Interface *interface = node->Interfaces[i];

        if (interface == NULL) {
            break;
        }

        DumpInterface(interface);
    }
}

void DumpInterface(Interface *interface) {
    assert(interface);

    Node *neighbor = GetNeighborNode(interface);

    printf("Interface Name = %s\n\tNbr Node %s, Local Node : %s, cost = %u\n",
           interface->Name,
           neighbor->Name,
           interface->Parent->Name,
           interface->LinkCost);

    printf("\tIP Addr: ");

    if (interface->Properties.HasIpAddress) {
        PrintIpAddress(&interface->Properties.IpAddress);
        printf("/%d\n", interface->Properties.Mask);
    }
}
