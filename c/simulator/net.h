#ifndef __NET_H__
#define __NET_H__

#include <stdbool.h>

#define IP_ADDRESS_SIZE 4
#define MAC_ADDRESS_SIZE 8

typedef struct Node Node;
typedef struct Link Link;
typedef struct Interface Interface;

typedef struct IpAddress
{
    char Address[IP_ADDRESS_SIZE];
} IpAddress;

typedef struct MacAddress
{
    char Address[MAC_ADDRESS_SIZE];
} MacAddress;

typedef struct NodeNetworkProperties
{
    bool IsLoopback;
    IpAddress IpAddress;
} NodeNetworkProperties;

typedef struct InterfaceNetworkProperties
{
    MacAddress MacAddress;
    bool HasIpAddress;
    IpAddress IpAddress;
    char Mask;
} InterfaceNetworkProperties;

void AssignMacAddress(Interface *interface);
void InitializeInterfaceNetworkProperties(InterfaceNetworkProperties *props);
void SetLoopbackAddress(Node *node, const char *ipAddress);
void SetIpAddress(Node *node, const char *localInterface, const char *ipAddress, char mask);

#endif