//
// Created by bluman on 5/4/23.
//

#include <assert.h>
#include <string.h>
#include "interface.h"
#include "../util.h"

void AddInterface(Node *node, Interface *interface)
{
    size_t index = GetNextAvailableSlotIndex(node);
    assert(index >= 0);
    node->Interfaces[index] = interface;
    interface->Parent = node;
}

void InsertLink(Interface *a, Interface *b, unsigned int cost)
{
    assert(a);
    assert(b);
    assert(!a->Connection);
    assert(!b->Connection);
    a->Connection = b;
    b->Connection = a;
    a->LinkCost = cost;
    b->LinkCost = cost;
}

Interface *CreateInterface(char *name, char *ipAddress, char mask)
{
    Interface *result = calloc(1, sizeof(Interface));
    assert(result);
    strncpy(result->Name, name, INTERFACE_NAME_SIZE - 1);
    result->Properties.IpAddress = ParseIpAddress(ipAddress);
    result->Properties.HasIpAddress = true;
    result->Properties.Mask = mask;
    return result;
}
