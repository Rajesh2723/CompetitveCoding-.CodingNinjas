/*
Problem statement
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.

Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.

Note : Order of vertices in output doesn't matter.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
2 <= V, E <= 10^3
Sample Input 1 :
1
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
  */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
    struct Edge {
        int destination;
        int weight;
    };

// Function to perform Dijkstra's Algorithm
void dijkstra(vector<vector<Edge>>& graph, int V, int E, int source) {
    vector<int> distance(V, INT_MAX); // Initialize distances to all vertices as infinity
    distance[source] = 0; // Distance from source to itself is 0

    // Create a min heap to store vertices and their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Add the source vertex to the priority queue
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second; // Extract the vertex with the minimum distance
        pq.pop();

        // Iterate through all adjacent vertices of u
        for (Edge& edge : graph[u]) {
            int v = edge.destination;
            int w = edge.weight;

            // Relaxation step
            if (distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }

    // Print the result
    for (int i = 0; i < V; ++i) {
        cout << i << " " << distance[i] << endl;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int V, E;
        cin >> V >> E;

        // Create a graph represented as an adjacency list
        vector<vector<Edge>> graph(V);

        // Input the edges and weights
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w}); // Considering the graph is undirected
        }

        // Perform Dijkstra's Algorithm
        dijkstra(graph, V, E, 0);
    }

    return 0;
}
