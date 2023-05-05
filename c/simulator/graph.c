#include "graph.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "../common/linkedlist.h"

void set_string(char *dest, const char *src, size_t max)
{
    strncpy(dest, src, max - 1);
    dest[max] = '\0';
}

Graph *CreateNewGraph(char *name)
{
    Graph *graph = calloc(1, sizeof(Graph));
    assert(graph);
    set_string(graph->topology_name, name, TOPOLOGY_NAME_SIZE);
    return graph;
}

Node *CreateGraphNode(Graph *graph, char *name)
{
    assert(graph);
    Node *node = calloc(1, sizeof(Node));
    assert(node);
    set_string(node->name, name, NODE_NAME_SIZE);

    emplace_back(&graph->node, &node->node);

    return node;
}

void add_interface(Node *node, Interface *interface)
{
    size_t index = GetNextAvailableSlotIndex(node);
    assert(index >= 0);
    node->interfaces[index] = interface;
    interface->parent = node;
}

void InsertLink(Node *node1, Node *node2, char *interface1_name, char *interface2_name, unsigned int cost)
{
    Link *link = malloc(sizeof(Link));
    assert(link);
    link->cost = cost;
    set_string(link->interface1.name, interface1_name, INTERFACE_NAME_SIZE);
    set_string(link->interface2.name, interface2_name, INTERFACE_NAME_SIZE);
    link->interface1.link = link;
    link->interface2.link = link;
    add_interface(node1, &link->interface1);
    add_interface(node2, &link->interface2);
}

void DumpNode(Node *node);
void DumpInterface(Interface *interface);

void DumpGraph(Graph *graph)
{
    assert(graph);
    assert(graph->node.next);
    printf("Topology Name = %s\n", graph->topology_name);

    LinkedList *currentNode = graph->node.next;
    while (currentNode != NULL)
    {
        Node *networkNode = GetNodeFromLinkedList(currentNode);
        DumpNode(networkNode);
        currentNode = currentNode->next;
    }

    printf("\n\n");
}

void PrintIpAddress(IpAddress *address)
{
    printf("%d.%d.%d.%d",
           (unsigned char)address->Address[0],
           (unsigned char)address->Address[1],
           (unsigned char)address->Address[2],
           (unsigned char)address->Address[3]);
}

void DumpNode(Node *node)
{
    assert(node);
    printf("\nNode Name = %s\n\tlo addr: ", node->name);

    if (node->Properties.IsLoopback)
    {
        PrintIpAddress(&node->Properties.IpAddress);
        printf("/32\n");
    }

    for (size_t i = 0; i < NODE_INTERFACE_MAX; i++)
    {
        Interface *interface = node->interfaces[i];

        if (interface == NULL)
        {
            break;
        }

        DumpInterface(interface);
    }
}

void DumpInterface(Interface *interface)
{
    assert(interface);

    Link *link = interface->link;
    Node *neighbor = GetNeighborNode(interface);

    printf("Interface Name = %s\n\tNbr Node %s, Local Node : %s, cost = %u\n",
           interface->name,
           neighbor->name,
           interface->parent->name,
           link->cost);

    printf("\tIP Addr: ");

    if (interface->Properties.HasIpAddress)
    {
        PrintIpAddress(&interface->Properties.IpAddress);
        printf("/%d\n", interface->Properties.Mask);
    }
}
