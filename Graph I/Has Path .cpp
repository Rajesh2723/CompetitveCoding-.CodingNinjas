/*
Problem statement
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.

E is the number of edges present in graph G.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
1
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
1
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
  */
#include<bits/stdc++.h>
using namespace std;

void bfs(int src, vector<bool>& visited, vector<int> adj[]) {
    queue<int> q;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int first = q.front();
        q.pop();

        for (auto x : adj[first]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int v, e;
        cin >> v >> e;

        vector<int> adj[v];
        for (int i = 0; i < e; i++) {
            int u, w;
            cin >> u >> w;
            adj[u].push_back(w);
            adj[w].push_back(u);
        }

        int v1, v2;
        cin >> v1 >> v2;

        vector<bool> visited(v, false);
        bfs(v1, visited, adj);

        if (!visited[v2]) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }

    return 0;
}
