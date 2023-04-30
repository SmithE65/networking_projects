#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdint.h>

typedef struct LinkedList
{
    struct LinkedList *prev;
    struct LinkedList *next;
} LinkedList;

#define GET_STRUCT_OFFSET(struct_name, field_name) (uintptr_t) & ((struct_name *)0)->field_name

void emplace_back(LinkedList *node, LinkedList *newNode);

#endif