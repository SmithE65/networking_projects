using Simulator;

namespace TestApp;

internal static class GraphExtensions
{
    public static void Print(this Graph graph)
    {
        System.Console.WriteLine($"Topology Name: {graph.Name}");

        foreach (var node in graph.Nodes)
        {
            node.Print();
        }
    }
}

internal static class NodeExtensions
{
    public static void Print(this Node node)
    {
        System.Console.WriteLine($"Node Name = {node.Name}\n\tlo addr: {node.IpAddress}/{node.Mask}");

        if (node.Interfaces is null)
        {
            return;
        }

        foreach (var inf in node.Interfaces)
        {
            inf.Print();
        }
    }
}

internal static class InterfaceExtensions
{
    public static void Print(this Interface net)
    {
        System.Console.WriteLine($"Interface Name = {net.Name}\n\tNbr Node %s, Local Node : %s, cost = {net.Cost}");
        System.Console.WriteLine($"\tIP Addr: {net.IpAddress}/{net.Mask}");
    }
}