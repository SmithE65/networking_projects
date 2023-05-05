//
// Created by bluman on 5/4/23.
//

#ifndef NETWORKING_PROJECTS_INTERFACE_H
#define NETWORKING_PROJECTS_INTERFACE_H

#include <stdlib.h>
#include <string.h>
#include "node.h"

#define INTERFACE_NAME_SIZE 16

typedef struct Interface
{
    char Name[INTERFACE_NAME_SIZE];
    Node *Parent;
    Interface *Connection;
    unsigned int LinkCost;
    InterfaceNetworkProperties Properties;
} Interface;

static inline Node *GetNeighborNode(Interface *interface)
{
    if (interface == NULL || interface->Connection == NULL)
    {
        return NULL;
    }

    return interface->Connection->Parent;
}

static inline size_t GetNextAvailableSlotIndex(Node *node)
{
    assert(node);

    for (int i = 0; i < NODE_INTERFACE_MAX; i++)
    {
        if (node->Interfaces[i] == NULL)
        {
            return i;
        }
    }

    return -1;
}

static inline Interface *GetInterfaceByName(Node *node, const char *name)
{
    assert(node);
    assert(name);

    for (int i = 0; i < NODE_INTERFACE_MAX; i++)
    {
        Interface *interface = node->Interfaces[i];

        if (interface == NULL)
        {
            return NULL;
        }

        if (strcmp(name, interface->Name) == 0)
        {
            return interface;
        }
    }

    return NULL;
}

void AddInterface(Node *node, Interface *interface);
void InsertLink(Interface *a, Interface *b, unsigned int cost);
Interface *CreateInterface(char *name, char *ipAddress, char mask);

#endif //NETWORKING_PROJECTS_INTERFACE_H
