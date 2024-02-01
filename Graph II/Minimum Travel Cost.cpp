/*
Problem statement
Ninjaland is a country having 'N' states numbered from 1 to 'N'. These 'N' states are connected by 'M' bidirectional roads. Each road connects to different states and has some cost to travel from one state to another. Now, the chief wants you to select 'N' - 1 roads in such a way that the tourist bus can travel to every state at least once at minimum 'COST'.

For example :
Consider a country having 4 states numbered from 1 to 4. These 4 states are connected by 5 bidirectional roads given as :
1 --- 2 with cost = 8
2 --- 3 with cost = 6
3 --- 4 with cost = 5
1 --- 4 with cost = 2
1 --- 3 with cost = 4

The map of the country can be represented as:


Now, the best way to choose 3 roads is:


The cost of travelling from any state to all other states is  2 + 4 + 6 i.e. 12.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 10
1 <= 'N' <= 1000
'N' - 1 <= 'M' <= 2000
1 <= 'C' <= 10^6 

Time limit: 1 sec
Sample Input 1:
1
4 4
1 2 3
1 4 5
2 3 1
3 4 8  
Sample Output 1 :
1 2 3
2 3 1
1 4 5
Explanation for 1:
Here 'N' = 4, So we need to pick 3 roads such that all states are visited and cost is minimum. Now the possible ways are.

1. (1, 2) (2, 3) (1, 4): In this case, the total cost of travelling is 3 + 1 + 5 = 9.
2. (1, 2) (2, 3) (3, 4): In this case, the total cost of travelling is 3 + 1 + 8 = 12.
3. (1, 2) (1, 4) (3, 4): in this case, the total cost of travelling is 3 + 5 + 8 = 16.
4. (1, 4) (2, 3) (3, 4): In this case, the total cost of travelling is 5 + 1 + 8 = 14.

Clearly, the cost is minimal in the first case so we pick (1, 2) ( 2, 3) (1, 4) with cost of travel 9. Refer above for diagram. 
Sample Input 2:
1
3 3
1 2 5
2 3 4
3 1 2
Sample Output 2 :
2 3 4
3 1 2
Explanation for 2:
The given graph is:


Here 'N' = 3, So we need to pick 2 roads such that all states are visited and the cost is minimum. Now the possible ways are.

1. (1, 2) (2, 3) : In this case, the total cost of travelling is 5 + 4 = 9.
2. (1, 3) (2, 3) : In this case, the total cost of travelling is 2 + 4 = 6.
3. (1, 2) (1, 3) : in this case, the total cost of travelling is 5 + 2 = 7.

Clearly, the cost is minimal in the second case so we pick (1, 3) ( 2, 3)  with the cost of travel 6.
*/
// #include<bits/stdc++.h>
// using namespace std;
// typedef pair<int,pair<int,int>>pi;
// void prims(vector<pi>adj[],int n,int m,vector<vector<int>>&ans){
//     priority_queue<pair<int,pair<int,int>>,vector<pi>,greater<pi>>pq;
//     vector<bool> visited(n+1, false);
//     pq.push({0,{1,0}});
//     while(!pq.empty()){
//         int wt=pq.top().first;
//         int u=pq.top().second.first;
//         int v=pq.top().second.second;
//         pq.pop();
//         if(visited[u]){
//             continue;
//         }
//         visited[u]=true;
//         ans.push_back({u,v,wt});
//         for(auto x:adj[u]){
//              int wt1=x.first;
//               int u1=x.second.first;
//             int v1=x.second.second;
//             if(!visited[v1]){
//                 pq.push({wt1,{u,v1}});
//             }
//         }

//     }
// }
// vector<vector<int>> findMST(vector<vector<int>> &road, int n, int m)
// {
//      vector<vector<int>>ans;
//      vector<pi>adj[n+1];
//      for(auto it:road){
//             int u=it[0];
//             int v=it[1];
//             int wt=it[2];
//         adj[u].push_back({wt,{u,v}});
//         adj[v].push_back({wt,{u,v}});
//      }
//      prims(adj,n,m,ans);

//      return ans;
// }
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pi;

void prims(vector<pi> adj[], int n, int m, vector<vector<int>> &ans) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<bool> visited(n + 1, false);
    pq.push({0, {1, 0}});  // Start from node 1

    while (!pq.empty()) {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        if (u != 1) {
            ans.push_back({parent, u, wt});
        }

        for (auto x : adj[u]) {
            int wt1 = x.first;
            int u1 = x.second.first;
            int v1 = x.second.second;
            
            if (!visited[v1]) {
                pq.push({wt1, {v1, u}});
            }
        }
    }
}

vector<vector<int>> findMST(vector<vector<int>> &road, int n, int m) {
    vector<vector<int>> ans;
    vector<pi> adj[n + 1];

    for (auto it : road) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({wt, {u, v}});
        adj[v].push_back({wt, {v, u}});
    }

    prims(adj, n, m, ans);

    return ans;
}
