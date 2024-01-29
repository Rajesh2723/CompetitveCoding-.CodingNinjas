/*
Problem statement
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

Find and print the total weight of Minimum Spanning Tree (MST) using Prim's algorithm.

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
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

long long primMST(vector<vector<pii>>& graph, int V) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap to store (weight, vertex) pairs
    vector<bool> visited(V, false);
    
    long long totalWeight = 0;

    // Start with the first vertex (assuming the graph is connected)
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        // If the vertex is already included in the MST, skip it
        if (visited[u]) {
            continue;
        }

        // Include the current vertex in the MST
        visited[u] = true;
        totalWeight += weight;

        // Explore all adjacent vertices of the current vertex
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            // If the neighbor is not visited and the weight is less than the current best known weight
            if (!visited[v]) {
                pq.push({w, v});
            }
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

        vector<vector<pii>> graph(V);

        // Input the edges and their weights
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        // Find and print the total weight of the Minimum Spanning Tree using Prim's algorithm
        cout << primMST(graph, V) << endl;
    }

    return 0;
}
