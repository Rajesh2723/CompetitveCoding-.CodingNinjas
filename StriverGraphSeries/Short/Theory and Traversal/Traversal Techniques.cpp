/*
Given an undirected connected graph with V vertices numbered from 0 to V-1, the task is to implement both Depth First Search (DFS) and Breadth First Search (BFS) traversals starting from the 0th vertex. The graph is represented using an adjacency list where adj[i] contains a list of vertices connected to vertex i. Visit nodes in the order they appear in the adjacency list.


Examples:




Input: V = 5, adj = [[2, 3, 1], [0], [0, 4], [0], [2]]

Output:[0, 2, 4, 3, 1], [0, 2, 3, 1, 4]

Explanation:

DFS: Start from vertex 0. Visit vertex 2, then vertex 4, backtrack to vertex 0, then visit vertex 3, and finally vertex 1. The traversal is 0 → 2 → 4 → 3 → 1.

BFS: Start from vertex 0. Visit vertices 2, 3, and 1 (in the order they appear in the adjacency list). Then, visit vertex 4 from vertex 2. The traversal is 0 → 2 → 3 → 1 → 4.

Input: V = 4, adj = [[1, 3], [2, 0], [1], [0]]

Output: [0, 1, 2, 3], [0, 1, 3, 2]

Explanation:

DFS: Start from vertex 0. Visit vertex 1, then vertex 2, backtrack to vertex 0, then visit vertex 3. The traversal is 0 → 1 → 2 → 3.

BFS: Start from vertex 0. Visit vertices 1 and 3, then visit vertex 2 from vertex 1. The traversal is 0 → 1 → 3 → 2.
  */
class Solution {
  public:
  void dfs(vector<int>&visited,vector<int>&ans,int V,vector<int>adj[],int node){
    visited[node]=1;
    ans.push_back(node);
    for(auto it:adj[node]){
        if(!visited[it]){
            visited[it]=1;
            dfs(visited,ans,V,adj,it);
        }
    }
  }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<int>visited(V,0);
        dfs(visited,ans,V,adj,0);
        return ans;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<int>visited(V,0);
        queue<int>q;
        visited[0]=1;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
