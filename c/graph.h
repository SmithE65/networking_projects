#ifndef GRAPH_H
#define GRAPH_H

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "common/linkedlist.h"

#define INTERFACE_NAME_SIZE 16
#define NODE_NAME_SIZE 16
#define TOPOLOGY_NAME_SIZE 32
#define NODE_INTERFACE_MAX 10

typedef struct Node Node;
typedef struct Link Link;

typedef struct Interface
{
    char name[INTERFACE_NAME_SIZE];
    Node *parent;
    Link *link;
} Interface;

typedef struct Link
{
    Interface interface1;
    Interface interface2;
    unsigned int cost;
} Link;

typedef struct Node
{
    char name[NODE_NAME_SIZE];
    Interface *interfaces[NODE_INTERFACE_MAX];
    LinkedList node;
} Node;

typedef struct Graph
{
    char topology_name[TOPOLOGY_NAME_SIZE];
    LinkedList node;
} Graph;

static inline Node *node_from_linked_list(LinkedList *listNode)
{
    return (Node *)((void *)listNode - GET_STRUCT_OFFSET(Node, node));
}

static inline Node *get_neighbor_node(Interface *interface)
{
    if (interface == NULL || interface->link == NULL)
    {
        return NULL;
    }

    Link *link = interface->link;
    return &link->interface1 == interface ? link->interface2.parent : link->interface1.parent;
}

static inline size_t get_node_interface_available_slot(Node *node)
{
    assert(node);

    for (int i = 0; i < NODE_INTERFACE_MAX; i++)
    {
        if (node->interfaces[i] == NULL)
        {
            return i;
        }
    }

    return -1;
}

static inline Interface *get_interface_by_name(Node *node, char *name)
{
    assert(node);
    assert(name);

    for (int i = 0; i < NODE_INTERFACE_MAX; i++)
    {
        Interface *interface = node->interfaces[i];

        if (interface == NULL)
        {
            return NULL;
        }

        if (strcmp(name, interface->name) == 0)
        {
            return interface;
        }
    }
}

static inline Node *get_node_by_name(Graph *graph, char *name)
{
    assert(graph);
    assert(name);

    LinkedList *listNode = &graph->node;

    while (listNode->next != NULL)
    {
        Node *node = node_from_linked_list(listNode->next);

        if (node == NULL)
        {
            return NULL;
        }

        if (strcmp(name, node->name) == 0)
        {
            return node;
        }

        listNode = listNode->next;
    }
}

Graph *create_new_graph(char *name);
Node *create_graph_node(Graph *graph, char *name);
void insert_link(Node *node1, Node *node2, char *interface1_name, char *interface2_name, unsigned int cost);

#endif