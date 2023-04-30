#include "linkedlist.h"
#include <assert.h>
#include <stdlib.h>

void emplace_back(LinkedList *node, LinkedList *newNode)
{
    assert(node);

    while (node->next != NULL)
    {
        node = node->next;
    }

    node->next = newNode;
}
