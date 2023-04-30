#include <assert.h>
#include "graph.h"

Graph *build_first_topo()
{
    Graph *graph = create_new_graph("First Topo");

    Node *R0_re = create_graph_node(graph, "R0_re");
    Node *R1_re = create_graph_node(graph, "R1_re");
    Node *R2_re = create_graph_node(graph, "R2_re");

    insert_link(R0_re, R1_re, "eth0", "eth1", 5);
    insert_link(R1_re, R2_re, "eth2", "eth3", 4);
    insert_link(R0_re, R2_re, "eth4", "eth5", 9);

    return graph;
}