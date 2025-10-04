/*
Given a Directed Acyclic Graph (DAG) with V vertices labeled from 0 to V-1.The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Find any Topological Sorting of that Graph.



In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).



The function should return an array representing the topological order. The output will be validated by our driver code, which checks the correctness of your topological sort. It will print True if the order is valid, otherwise False.


Examples:
Input: V = 6,adj=[ [ ], [ ], [3], [1], [0,1], [0,2] ]







Output: [5, 4, 2, 3, 1, 0]

Explanation: A graph may have multiple topological sortings. 

The result is one of them. The necessary conditions 

for the ordering are:

According to edge 5 -> 0, node 5 must appear before node 0 in the ordering.

According to edge 4 -> 0, node 4 must appear before node 0 in the ordering.

According to edge 5 -> 2, node 5 must appear before node 2 in the ordering.

According to edge 2 -> 3, node 2 must appear before node 3 in the ordering.

According to edge 3 -> 1, node 3 must appear before node 1 in the ordering.

According to edge 4 -> 1, node 4 must appear before node 1 in the ordering.



The above result satisfies all the necessary conditions. 

[4, 5, 2, 3, 1, 0] is also one such topological sorting 

that satisfies all the conditions.
  */
class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[]){
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
};
