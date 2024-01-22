/*
Problem statement
Given a directed graph, check whether the graph contains a cycle or not. Your function should return true if the given graph contains at least one cycle, else return false.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= V <= 10^3
0 <= E <= 10^3
0 <= A, B < V

Time Limit: 1 sec
Sample Input 1:.
2
4 4
0 1
1 2
2 3
3 0
3 3
1 0
1 2
0 2
Sample Output 1:
true
false
Explanation for Sample Input 1:
In the first case,
From node 0 we can reach 0 again by following this sequence of nodes in the path: 0,1,2,3,0. As we can see in the image below.
Example

In the second case,
There is no cycle in the given graph. As we can see in the image below.
Example

Sample Input 2:
2
3 2
0 1
0 2
3 3
1 1
0 2
1 2
Sample Output 2:
false
true
  */
//logic we can use is topological sorting ,take indegree and if count is same as operaions we did then there is no extra edge to form cycle,else return true;
#include<bits/stdc++.h>
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<int>adj[v+1];
	vector<int>indegree(v+1);
	for(auto it:edges){
		adj[it[0]].push_back(it[1]);
		indegree[it[1]]++;
	}
	queue<int>q;
	 int count=0;
	vector<int>vis(v);
	for(int i=0;i<v;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int node=q.front();
		q.pop();
		count++;
		for(auto x:adj[node]){
			indegree[x]--;
			if(indegree[x]==0){
				q.push(x);
			}
		}
	}
	if(count==v){
		return 0;
	}
	return 1;
}
