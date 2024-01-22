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
//indegree concept....
#include<bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
     vector<int>ans;
     vector<int>indegree(nodes+1);
     vector<int>adj[nodes+1];
     for(auto it:graph){
         adj[it[0]].push_back(it[1]);
         indegree[it[1]]++;
     }
     queue<int>q;
     int count=0;
     for(int i=0;i<nodes;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
     while(!q.empty()){
         int node=q.front();
         q.pop();
         ans.push_back(node);
         for(auto x:adj[node]){
             indegree[x]--;
             if(indegree[x]==0){
                 q.push(x);
             }
         }
     }
      
return ans;
}
