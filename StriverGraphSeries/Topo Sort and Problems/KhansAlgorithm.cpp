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
*/based on incoming edges to a node we are calculating indegree.
#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int n) {
    int indeg[n]={0};
    vector<int>adj[n];
    for(auto i:graph)
    {
      adj[i[0]].push_back(i[1]);0->1//indegree of 1 becomes 1;
      indeg[i[1]]++;
    }

    queue<int>q;

    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0)q.push(i);
    }

    vector<int>ans;
    while(!q.empty())
    {
        int node=q.front();q.pop();
        ans.push_back(node);
        for(auto i:adj[node])
        {
            indeg[i]--;
            if(indeg[i]==0)q.push(i);
        }
    }
    return ans;
}
