#include "simulator/graph.h"
#include "simulator/net.h"

Graph *build_first_topology()
{
    Graph *graph = CreateNewGraph("First Topology");

    Node *R0_re = CreateGraphNode(graph, "R0_re");
    Node *R1_re = CreateGraphNode(graph, "R1_re");
    Node *R2_re = CreateGraphNode(graph, "R2_re");

    Interface *eth00 = CreateInterface("eth0/0", "20.1.1.1", 24);
    Interface *eth01 = CreateInterface("eth0/1", "20.1.1.2", 24);
    Interface *eth02 = CreateInterface("eth0/2", "30.1.1.1", 24);
    Interface *eth03 = CreateInterface("eth0/3", "30.1.1.2", 24);
    Interface *eth04 = CreateInterface("eth0/4", "40.1.1.1", 24);
    Interface *eth05 = CreateInterface("eth0/5", "40.1.1.2", 24);

    AddInterface(R0_re, eth00);
    AddInterface(R1_re, eth01);
    AddInterface(R1_re, eth02);
    AddInterface(R2_re, eth03);
    AddInterface(R0_re, eth04);
    AddInterface(R2_re, eth05);

    InsertLink(eth00, eth01, 5);
    InsertLink(eth02, eth03, 4);
    InsertLink(eth04, eth05, 9);

    SetLoopbackAddress(R0_re, "122.1.1.0");
    SetLoopbackAddress(R1_re, "122.1.1.1");
    SetLoopbackAddress(R2_re, "122.1.1.2");

    return graph;
}