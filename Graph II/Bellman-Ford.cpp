/*
Problem statement
you are given a weighted directed graph G with n vertices and m edges, and two specified vertex src and des. You want to find the length of shortest paths from vertex src to des. The graph may contain the edges with negative weight.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 200
1 <= M <= min(800, N*(N-1))
1 <= a,b <= N
-10^5 <= wt <= 10^5
Sample Input:
1
3 6
3 1
3 1 -2
1 3 244
2 3 -2
2 1 201
3 2 220
1 2 223
Sample output:
-2
  */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
struct Edge {
    int src, dest, weight;
};

int bellmanFord(vector<Edge>& graph, int src, int des, int n) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < n; ++i) {
        for (const Edge& edge : graph) {
            if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    return (dist[des] != INT_MAX) ? dist[des] : int(1e9);
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, M;
        cin >> N >> M;

        int src, des;
        cin >> src >> des;

        vector<Edge> graph;
        for (int i = 0; i < M; ++i) {
            int a, b, wt;
            cin >> a >> b >> wt;
            graph.push_back({a - 1, b - 1, wt});  // Adjusting vertices to 0-based indexing
        }

        int result = bellmanFord(graph, src - 1, des - 1, N);//passing them as 0 based indexing.
        cout << result << endl;
    }

    return 0;
}
