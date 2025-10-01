/*
iven a undirected Graph consisting of V vertices numbered from 0 to V-1 and E edges. The ith edge is represented by [ai,bi], denoting a edge between vertex ai and bi. We say two vertices u and v belong to a same component if there is a path from u to v or v to u. Find the number of connected components in the graph.



A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.


Examples:


Input: V=4, edges=[[0,1],[1,2]]

Output: 2

Explanation: Vertices {0,1,2} forms the first component and vertex 3 forms the second component.
  */
class Solution {
  public:
  void dfs(int node,vector<int>adj[],vector<int>&visited){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            visited[it]=1;
            dfs(it,adj,visited);
        }
    }
  }
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {

      vector<int>visited(V,0);
      int E=edges.size();
      int count=0;
      vector<int>adj[V];
      for(int i=0;i<E;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      for(int i=0;i<V;i++){
        if(!visited[i]){
          count++;
          dfs(i,adj,visited);
        }
      }
      return count;
    }
};
