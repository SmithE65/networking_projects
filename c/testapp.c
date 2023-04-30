#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#include "common/linkedlist.h"
#include "graph.h"

// typedef struct Employee
// {
//     char name[30];
//     unsigned int salary;
//     char designation[30];
//     unsigned int id;
//     LinkedList node;
// } Employee;

// void print_employee_details(LinkedList *node)
// {
//     // get employee and print its details
//     while (node != NULL)
//     {
//         Employee *e = (Employee *)(((void *)node) - GET_STRUCT_OFFSET(Employee, node));
//         printf("ID: %d\t", e->id);
//         printf("Name: %s\n", e->name);
//         printf("Role: %s\n", e->designation);
//         printf("Salary: %d\n", e->salary);
//         printf("\n\n");
//         node = e->node.next;
//     }
// }

int main(int argc, char **argv)
{
    printf("Hello, world!\n");

    Node n1 = {"node1"};
    Node n2 = {"node2"};
    Link l = {{"eth0", &n1}, {"eth1", &n2}, 0};
    n1.interfaces[0] = &l.interface1;
    n2.interfaces[0] = &l.interface2;
    l.interface1.link = &l;
    l.interface2.link = &l;

    Node *result_node = get_neighbor_node(&n1.interfaces[0]->link->interface1);
    assert(result_node);

    printf("Should be 'node2': '%s'\n", result_node->name);

    int slot = get_node_interface_available_slot(&n1);
    printf("Should be '1': '%d'\n", slot);

    return 0;
}

// Employee e1 = {"Froederick", 30000, "Boss-man", 1};
// printf("&e: %p\n", &e1);
// printf("&e.node: %p\n", &e1.node);
// printf("offset: %ld\n", GET_STRUCT_OFFSET(Employee, node));
// printf("test: %p\n", (Employee *)(((void *)&e1.node) - GET_STRUCT_OFFSET(Employee, node)));

// Employee e1 = {"Froederick", 30000, "Boss-man", 1};
// Employee e2 = {"Bobbward", 21000, "Uniter", 2};
// Employee e3 = {"Lazagna", 35000, "Person", 3};

// e1.node.next = &e2.node;
// e2.node.prev = &e1.node;
// e2.node.next = &e3.node;
// e3.node.prev = &e2.node;

// print_employee_details(&e1.node);
