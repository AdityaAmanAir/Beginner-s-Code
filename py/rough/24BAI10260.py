# NAME : ADITYA AMAN
# REG NO. : 24BAI10129

import heapq
import matplotlib.pyplot as plt
import networkx as nx

# Implementation of Dijkstra's pathfinding algorithm
def dijkstra(graph, start):
    """
    Finds shortest paths from a starting node to all other nodes.
    
    Inputs:
        graph: Dictionary showing node connections and weights
        start: Starting node identifier
    
    Returns:
        Two dictionaries: 
        - shortest distances to each node
        - previous nodes for path backtracking
    """
    # Setup initial distances
    dist = {n: float('inf') for n in graph}  # All nodes start at infinity
    dist[start] = 0  # Starting node has zero distance
    prev = {n: None for n in graph}  # For rebuilding paths
    heap = [(0, start)]  # Our priority queue

    while heap:
        current_dist, current = heapq.heappop(heap)
        
        # Skip if we've already got a better path
        if current_dist > dist[current]:
            continue
        
        # Check all neighboring nodes
        for neighbor, weight in graph[current].items():
            total_dist = current_dist + weight
            
            # Update if we found a shorter path
            if total_dist < dist[neighbor]:
                dist[neighbor] = total_dist
                prev[neighbor] = current
                heapq.heappush(heap, (total_dist, neighbor))
    
    return dist, prev

# Helper to show the actual path taken
def get_shortest_path(prev_nodes, start, end):
    """
    Backtracks from end node to start using previous node info
    """
    route = []
    current = end
    
    # Work backwards from target
    while current is not None:
        route.append(current)
        current = prev_nodes.get(current)
    
    route.reverse()  # Put in correct order
    
    # Check if we actually reached the start
    if route and route[0] == start:
        return route
    return None  # No valid path

# Visualization function with path highlighting
def plot_graph(graph, highlight_path=None):
    """
    Draws the graph structure with optional path emphasis
    """
    # Build networkx graph from our data
    g = nx.DiGraph()
    for src in graph:
        for dst, cost in graph[src].items():
            g.add_edge(src, dst, weight=cost)
    
    # Position nodes consistently
    pos = nx.spring_layout(g, seed=42)  
    fig, ax = plt.subplots(figsize=(10,6), tight_layout=True)
    
    # Base drawing elements
    nx.draw_networkx_nodes(g, pos, node_size=700, ax=ax, node_color='#a0c8f0')
    nx.draw_networkx_labels(g, pos, font_weight='bold', ax=ax)
    nx.draw_networkx_edges(g, pos, width=1.5, alpha=0.7, ax=ax)
    
    # Show all weights by default
    all_labels = nx.get_edge_attributes(g, 'weight')
    nx.draw_networkx_edge_labels(g, pos, edge_labels=all_labels, ax=ax)
    
    # Extra styling for highlighted path
    if highlight_path:
        path_edges = list(zip(highlight_path, highlight_path[1:]))
        
        # Thicker red edges for path
        nx.draw_networkx_edges(g, pos, edgelist=path_edges, 
                             width=3, edge_color='red', ax=ax)
        # Red nodes along path
        nx.draw_networkx_nodes(g, pos, nodelist=highlight_path,
                             node_color='red', node_size=700, ax=ax)
        
        # Redraw labels over red edges for clarity
        path_labels = {(u,v): g[u][v]['weight'] for u,v in path_edges}
        nx.draw_networkx_edge_labels(g, pos, edge_labels=path_labels,
                                   font_color='red', ax=ax,
                                   bbox={'facecolor':'white', 'alpha':0.8})

    ax.set_title("Network Graph" + (" with Shortest Path" if highlight_path else ""))
    ax.axis('off')
    plt.show()

# ------- Test Case 1 - Basic Example -------
network1 = {
    'A': {'B':6, 'D':1},
    'B': {'A':6, 'D':2, 'E':2, 'C':5},
    'C': {'B':5, 'E':5},
    'D': {'A':1, 'B':2, 'E':1},
    'E': {'D':1, 'B':2, 'C':5}
}

start = 'A'
dists, prevs = dijkstra(network1, start)

print("Test Case 1 Results:")
print(f"Distances from {start}: {dists}")
for n in network1:
    if n != start:
        p = get_shortest_path(prevs, start, n)
        print(f"Path to {n}: {p} (cost: {dists[n]})")

# Show visual for path to C
plot_graph(network1, get_shortest_path(prevs, start, 'C'))

# ------- Test Case 2 - Complex Network -------
network2 = {
    'S': {'A':7, 'B':2, 'C':3},
    'A': {'S':7, 'B':3, 'D':4},
    'B': {'S':2, 'A':3, 'D':4, 'H':1},
    'C': {'S':3, 'L':2},
    'D': {'A':4, 'B':4, 'F':5},
    'F': {'D':5, 'H':3},
    'G': {'H':2, 'E':2},
    'E': {'G':2, 'K':5},
    'H': {'B':1, 'F':3, 'G':2},
    'K': {'E':5, 'L':4},
    'L': {'C':2, 'K':4}
}

start_node = 'S'
distances, predecessors = dijkstra(network2, start_node)

print("\nTest Case 2 Results:")
print(f"Distances from {start_node}: {distances}")
for n in ['E', 'K', 'L']:
    path = get_shortest_path(predecessors, start_node, n)
    print(f"Path to {n}: {path} (cost: {distances[n]})")

# Display path to E
plot_graph(network2, get_shortest_path(predecessors, start_node, 'E'))

if __name__ == "__main__":
    pass  # Can add more examples here later