using System.Collections;
using System.Collections.ObjectModel;
using System.Net;
using System.Net.NetworkInformation;

namespace Simulator;

public class Graph : IEnumerable<Node>
{
    private List<Node> _nodes { get; set; } = new List<Node>();

    public Graph(string name)
    {
        Name = name;
    }

    public string Name { get; }
    public IReadOnlyCollection<Node> Nodes => new ReadOnlyCollection<Node>(_nodes);

    public void Add(Node node)
    {
        if (_nodes.Any(x => x.Name == node.Name))
        {
            throw new InvalidOperationException($"Node with name '{node.Name}' already exists in graph '{Name}'");
        }

        _nodes.Add(node);
    }

    public Node? Find(string name) => _nodes.FirstOrDefault(x => x.Name == name);

    public bool Remove(Node node) => _nodes.Remove(node);

    public IEnumerator<Node> GetEnumerator()
    {
        return ((IEnumerable<Node>)_nodes).GetEnumerator();
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return ((IEnumerable)_nodes).GetEnumerator();
    }
}

public class Node
{
    public required string Name { get; set; }
    public bool IsLoopback { get; set; }
    public IPAddress? IpAddress { get; set; }
    public byte? Mask { get; set; } = 32;
    public IEnumerable<Interface>? Interfaces { get; set; }
}

public class Interface
{
    public required string Name { get; set; }
    public int Cost => 0;
    public IPAddress? IpAddress { get; set; }
    public byte? Mask { get; set; } = 24;
    public PhysicalAddress? MacAddress { get; set; }
}
