#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <stdbool.h>
#include <string.h>

#include "simulator/graph.h"

extern Graph *build_first_topology();

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
    printf("Hello, world!\n");
    printf("C Version: %ld\n\n", __STDC_VERSION__);

    Graph *graph = build_first_topology();
    DumpGraph(graph);

    return 0;
}
