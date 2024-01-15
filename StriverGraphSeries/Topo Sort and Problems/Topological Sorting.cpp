/*
Problem statement
Given a DAG(direct acyclic graph), print Topological Sorting of a given graph

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= V <= 1000
0 <= E <= 3000
0 <= U, V <= V-1

Time Limit: 1sec
Sample Input 1:
1
5 4
0 2
1 2
3 1
0 4
Sample Output 1:
Correct
Sample Output 1 Explanation:
One correct sort order is : 3 1 0 4 2.
  */
#include<bits/stdc++.h>
void dfs(int node, vector<int>adj[],vector<int>&vis,stack<int>&s){
     vis[node]=1;
     for(auto it:adj[node]){
          if(!vis[it])dfs(it, adj,vis,s);
     
     }
     s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
     // vector<int>ans;
     stack<int>s;
     vector<int>adj[nodes];
      for(auto i:graph){
           adj[i[0]].push_back(i[1]);
      }
     vector<int>vis(nodes,0);
     for(int i=0;i<nodes;i++){
          if(!vis[i]){
               dfs(i, adj,vis,s);
          }
     }
     vector<int>ans;

     while(!s.empty()){
          ans.push_back(s.top());
          s.pop();
     }
     return ans;
}
