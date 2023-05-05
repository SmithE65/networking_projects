#include "simulator/graph.h"
#include "simulator/net.h"

Graph *build_first_topology()
{
    Graph *graph = CreateNewGraph("First Topology");

    Node *R0_re = CreateGraphNode(graph, "R0_re");
    Node *R1_re = CreateGraphNode(graph, "R1_re");
    Node *R2_re = CreateGraphNode(graph, "R2_re");

    InsertLink(R0_re, R1_re, "eth0/0", "eth0/1", 5);
    InsertLink(R1_re, R2_re, "eth0/2", "eth0/3", 4);
    InsertLink(R0_re, R2_re, "eth0/4", "eth0/5", 9);

    SetLoopbackAddress(R0_re, "122.1.1.0");
    SetIpAddress(R0_re, "eth0/4", "40.1.1.1", 24);
    SetIpAddress(R0_re, "eth0/0", "20.1.1.1", 24);

    SetLoopbackAddress(R1_re, "122.1.1.1");
    SetIpAddress(R1_re, "eth0/1", "20.1.1.2", 24);
    SetIpAddress(R1_re, "eth0/2", "30.1.1.1", 24);

    SetLoopbackAddress(R2_re, "122.1.1.2");
    SetIpAddress(R2_re, "eth0/3", "30.1.1.2", 24);
    SetIpAddress(R2_re, "eth0/5", "40.1.1.2", 24);

    return graph;
}