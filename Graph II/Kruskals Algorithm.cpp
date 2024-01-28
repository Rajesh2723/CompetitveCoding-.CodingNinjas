/*
Problem statement
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

Find and print the total weight of Minimum Spanning Tree (MST) using Kruskal's algorithm.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
2 <= V, E <= 10^5
1 <= wt <= 10^4
Sample Input 1 :
1
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
9
  */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Comparison function for sorting edges based on weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Find operation in union-find
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union operation in union-find
void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the total weight of Minimum Spanning Tree using Kruskal's algorithm
int kruskal(vector<Edge>& edges, int V, int E) {
    // Sort edges based on weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Allocate memory for subsets
    Subset subsets[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int totalWeight = 0; // Total weight of MST

    // Iterate through sorted edges
    for (Edge edge : edges) {
        int root1 = find(subsets, edge.src);
        int root2 = find(subsets, edge.dest);

        // Check if including this edge creates a cycle
        if (root1 != root2) {
            totalWeight += edge.weight;
            unionSets(subsets, root1, root2);
        }
    }

    return totalWeight;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int V, E;
        cin >> V >> E;

        // Read edges
        vector<Edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
        }

        // Find and print the total weight of Minimum Spanning Tree
        int result = kruskal(edges, V, E);
        cout << result << endl;
    }

    return 0;
}
