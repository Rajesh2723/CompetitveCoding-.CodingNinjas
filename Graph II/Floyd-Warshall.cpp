/*
Problem statement
You are given an undirected weighted graph G with n vertices. And Q queries, each query consists of two integers a and b and you have print the distance of shortest path between a and b.

Note: If there is no path between a and b print 10^9

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= M <= 10^4
1 <= Q <= 10^4
1 <= wt <= 10^5 (for each edge)
Note: Graph may contain multiple edges.

Sample Input:
1
3 6
3 1 4
1 3 17
2 3 2
1 3 7
3 2 11
2 3 15
3
1 1 
2 2 
2 3 
Sample output:
0
0
2
  */
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& graph, int N) {
    // Floyd-Warshall algorithm
    for (int k = 0; k <=N; ++k) {
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <=N; ++j) {
               if(i==j){
                   graph[i][j]=0;
                   continue;
               }else{
                     graph[i][j]=min(graph[i][j],graph[i][k] + graph[k][j]);
               }
               


                // if (graph[i][k] != INF && graph[k][j] != INF &&
                //     graph[i][k] + graph[k][j] < graph[i][j]) {
                //     graph[i][j] = graph[i][k] + graph[k][j];
                // }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        // Initialize the graph with INF as the initial distance
        vector<vector<int>> graph(N+1 , vector<int>(N+1 , INF));

        // Input the edges and their weights
        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u][v] =min(graph[u][v],w);
            graph[v][u] =min(graph[v][u],w); // Assuming the graph is undirected
        }

        floydWarshall(graph, N);

        // Output the distances for each query
        int Q;
        cin >> Q;

        for (int q = 0; q < Q; ++q) {
            int a, b;
            cin >> a >> b;

            if (graph[a][b] == INF) {
                cout << 1e9 << endl;
            } else {
                cout << graph[a][b] << endl;
            }
        }
    }

    return 0;
}
