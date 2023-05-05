//
// Created by bluman on 5/4/23.
//

#ifndef NETWORKING_PROJECTS_NODE_H
#define NETWORKING_PROJECTS_NODE_H

#include "interface.h"
#include "net.h"

#define NODE_NAME_SIZE 16
#define NODE_INTERFACE_MAX 10

typedef struct Interface Interface;

typedef struct Node
{
    char Name[NODE_NAME_SIZE];
    Interface *Interfaces[NODE_INTERFACE_MAX];
    NodeNetworkProperties Properties;
} Node;

#endif //NETWORKING_PROJECTS_NODE_H
