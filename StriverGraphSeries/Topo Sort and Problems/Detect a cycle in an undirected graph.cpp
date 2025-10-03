/*
Given an undirected graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Determine if the graph contains any cycles.

Note: The graph does not contain any self-edges (edges where a vertex is connected to itself).


Examples:




Input: V = 6, adj= [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]]

Output: True

Explanation: The graph contains a cycle: 0 ->1 -> 2 -> 5 -> 4 -> 1.

*/
class Solution{
public:
    bool bfs(int start,vector<bool>&visited,vector<int>adj[],int V){
        queue<pair<int,int>>q;
        q.push({start,-1});
        while(!q.empty()){
            int src=q.front().first;
            int prt=q.front().second;
            q.pop();
            for(auto it:adj[src]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push({it,src});
                }else if(it!=prt){
                    return true;
                }
            }

        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        bool ans=false;
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                visited[i]=true;
                ans=bfs(i,visited,adj,V);
                if(ans)
                break;
            }
        }
        return ans;
    }
};
