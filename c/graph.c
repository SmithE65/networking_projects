#include "graph.h"

#include <assert.h>
#include <string.h>

#include "common/linkedlist.h"

void set_string(char *dest, const char *src, size_t max)
{
    strncpy(dest, src, max - 1);
    dest[max] = '\0';
}

Graph *create_new_graph(char *name)
{
    Graph *graph = calloc(1, sizeof(Graph));
    assert(graph);
    set_string(graph->topology_name, name, TOPOLOGY_NAME_SIZE);
    return graph;
}

Node *create_graph_node(Graph *graph, char *name)
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
    size_t index = get_node_interface_available_slot(node);
    assert(index >= 0);
    node->interfaces[index] = interface;
    interface->parent = node;
}

void insert_link(Node *node1, Node *node2, char *interface1_name, char *interface2_name, unsigned int cost)
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
