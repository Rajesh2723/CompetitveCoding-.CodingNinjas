/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 

Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
 

Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.
  */
class DSU{
	vector<int> parent;//parent node for each of them
	vector<int> subtree_size;
	int N;
public:

	DSU(int n){
		N = n;
		parent = vector<int>(n+1, 0);
		subtree_size = vector<int>(n+1, 1);

		for(int i=1; i<=n; i++) parent[i] = i;
	}

	int findRoot(int u){
		while(u != parent[u]){
			parent[u] = parent[parent[u]]; //Path compression
			u = parent[u];
		}

		return u;
	}


	void combine(int u, int v){
		int ru = findRoot(u);
		int rv = findRoot(v);

		if(ru == rv) return;

		if(subtree_size[ru] > subtree_size[rv]){
			parent[rv] = ru;
			subtree_size[ru] += subtree_size[rv];
		} else{
			parent[ru] = rv;
			subtree_size[rv] += subtree_size[ru];
		}

	}

};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu = DSU(n);
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            dsu.combine(u,v);
        }
        int ru = dsu.findRoot(source);
			int rv = dsu.findRoot(destination);
            if(ru==rv){
                return true;
            }else{
                return false;
            }
    }
};
