/*
Problem statement
You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].

Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed graph else return false.

For Example :
In the following directed graph has a cycle i.e. B->C->E->D->B.

Note :
1. The cycle must contain at least two nodes.
2. It is guaranteed that the given graph has no self-loops in the graph.
3. The graph may or may not be connected.
4. Nodes are numbered from 1 to N.
5. Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 ≤ T ≤ 5

2 <= N <= 100
1 <= M <= min(100,N(N-1)/2)
1 <= EDGES[i][0], EDGES[i][1] <= N

Where ‘T’ is the number of test cases.

Time Limit: 1 sec
Sample Input 1 :
1
5
6
1 2
4 1
2 4
3 4
5 2
1 3
Sample Output 1 :
true
Explanation For Input 1 :
The given graph contains cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1.
Sample Input 2 :
2
5
4
1 2
2 3
3 4
4 5
2
1
1 2
Sample Output 2 :
false
false
Explanation For Input 2 :
The given graphs don’t contain any cycle
*/
//topo fails when it generates elements less than n and if it generates equal to n then its a toposort it wont form cycle.
#include<bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  // Write your code here.

  vector<vector<int>> adj(n+1);

  vector<int> indegree(n+1,0);

  for(auto i:edges) {

    adj[i.first].push_back(i.second);

    indegree[i.second]++;

  }

  int cnt=0;

  queue<int> q;

  for(int i=1;i<=n;i++) {

    if(indegree[i]==0) {

      q.push(i);

    }

  }

 

  while(!q.empty()) {

    int front = q.front();

    q.pop();

    cnt++;

    for(auto j:adj[front]) {

      indegree[j]--;

      if(indegree[j]==0) {

        q.push(j);

      }

    }

  }

  if(cnt==n) {

    return 0;

  }

  return 1;

}
