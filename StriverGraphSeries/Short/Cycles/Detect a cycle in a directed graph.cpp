/*
Given a directed graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Determine if the graph contains any cycles.


Examples:
Input: V = 6, adj= [ [1], [2, 5], [3], [4], [1], [ ] ]







Output: True



Explanation: The graph contains a cycle: 1 -> 2 -> 3 -> 4 -> 1.

Input: V = 4, adj= [[1,2], [2], [], [0,2]]



Output: False



Explanation: The graph does not contain a cycle.
*/
class Solution{
public:

    vector<int>topoSort(int V,vector<int>adj[]){
        vector<int>ans;
        vector<int>inDegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0)q.push(it);
            }
        }
        return ans;
    }

    bool isCyclic(int N, vector<int> adj[]) {
        vector<int>topo;
        topo=topoSort(N,adj);
        if(topo.size()<N)return true;

        return false;

    }
};
