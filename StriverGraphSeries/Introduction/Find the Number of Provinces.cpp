/*
Problem statement
You are given ‘n’ cities, some of which are connected by bidirectional roads. You are also given an ‘n x n’ matrix i.e. ‘roads’, where if city ‘i’ and ‘j’ are connected by a road then ‘roads[i][j]'= 1, otherwise ‘roads[i][j]' = 0.



A province is a group of cities that are either directly or indirectly connected to each other through roads.



The goal is to count and return the total number of such provinces in the given matrix.



Example:
n = 4, roads = [ [1, 1, 1, 0],
                 [1, 1, 1, 0],
                 [1, 1, 1, 0],
                 [0, 0, 0, 1] ]

So, there are ‘2’ provinces.
Note:
1. A city is connected to itself. So, for every city ‘i’, ‘roads[i][i] = 1’.
Detailed explanation ( Input/output format, Notes, Images )
Sample input 1:
3
1 0 0 
0 1 0 
0 0 1 
Sample output 1:
3
Explanation of sample input 1:
Test Case 1:
n = 3, roads = [ [1, 0, 0],
                 [0, 1, 0],
                 [0, 0, 1] ]

So, there are ‘3’ provinces.
Sample input 2:
4
1 1 0 0 
1 1 0 0 
0 0 1 1 
0 0 1 1 
Sample output 2:
2
Explanation of sample input 2:
n = 4, roads = [ [1, 1, 0, 0],
                 [1, 1, 0, 0],
                 [0, 0, 1, 1],
                 [0, 0, 1, 1] ]

So, there are ‘2’ provinces.
Constraints:
1 <= 'n' <= 200
roads[i][j] is 1 or 0.
roads[i][j] == roads[j][i]

Time limit: 1 sec
*/
#include<bits/stdc++.h>

void dfs(int node, vector<int> adj[], int visited[]) {
    visited[node] = 1;

    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(it, adj, visited);
        }
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    vector<int> adj[n];//it holds vector of vectors used mainly in graphs 
    int visited[n] = {0};
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (roads[i][j] == 1 && i != j) {//self loop is skipped
              /*
              adj[0]: [1, 2]
              adj[1]: [0, 2]
              adj[2]: [0, 1]
              adj[3]: [] // Node 3 has no outgoing edges

                */
              
                adj[i].push_back(j);
                // adj[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {//first node always not visited
            count++;
            dfs(i, adj, visited);
        }
    }

    return count;
}
