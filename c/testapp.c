#include <stdio.h>

#include "simulator/graph.h"

extern Graph *build_first_topology();

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
    printf("Hello, world!\n");

    Graph *graph = build_first_topology();
    DumpGraph(graph);

    return 0;
}
