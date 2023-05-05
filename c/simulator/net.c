#include "net.h"

#include <assert.h>
#include <memory.h>

#include "graph.h"
#include "../util.h"

void AssignMacAddress(Interface *interface)
{
}

void InitializeInterfaceNetworkProperties(InterfaceNetworkProperties *props)
{
    assert(props);
    memset(props->MacAddress.Address, 0, MAC_ADDRESS_SIZE);
    props->HasIpAddress = false;
    memset(props->IpAddress.Address, 0, IP_ADDRESS_SIZE);
    props->Mask = 0;
}

void SetLoopbackAddress(Node *node, const char *ipAddress)
{
    assert(node);
    node->Properties.IpAddress = ParseIpAddress(ipAddress);
    node->Properties.IsLoopback = true;
}

void SetIpAddress(Node *node, const char *localInterface, const char *ipAddress, char mask)
{
    assert(node);
    Interface *interface = GetInterfaceByName(node, localInterface);
    assert(interface);
    interface->Properties.IpAddress = ParseIpAddress(ipAddress);
    interface->Properties.HasIpAddress = true;
    interface->Properties.Mask = mask;
}
