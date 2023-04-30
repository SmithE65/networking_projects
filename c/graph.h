#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include "linked_list/linkedlist.h"

#define IF_NAME_SIZE 16
#define NODE_NAME_SIZE 16
#define TOPOLOGY_NAME_SIZE 32
#define NODE_INTERFACE_MAX 10

typedef struct Node Node;
typedef struct Link Link;

typedef struct Interface
{
    char name[IF_NAME_SIZE];
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
    Interface *interface[NODE_INTERFACE_MAX];
    LinkedList node;
} Node;

typedef struct Graph
{
    char topology_name[TOPOLOGY_NAME_SIZE];
    LinkedList node;
} Graph;

#endif