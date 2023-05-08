//
// Created by bluman on 5/7/23.
//

#ifndef NETWORKING_PROJECTS_LINK_H
#define NETWORKING_PROJECTS_LINK_H

#include "interface.h"

typedef struct Link
{
    Interface *A;
    Interface *B;
    unsigned int Cost;
} Link;

#endif //NETWORKING_PROJECTS_LINK_H
