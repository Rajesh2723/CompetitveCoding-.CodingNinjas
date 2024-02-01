/*
Problem statement
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.

Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N
Sample Input
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
Sample Output
2
2
*/
 
#include<bits/stdc++.h>
using namespace std;
void bfs(int src,vector<int>&cost,vector<int>adj[],int n){
    cost[src]=0;
    queue<int>q;
    vector<bool>visited(n+1,false);
    visited[src]=true;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto x:adj[node]){
           if(!visited[x]){
               visited[x]=true;
                cost[x]=cost[node]+1;
            q.push(x);
           }
           
        }
    }
    cout<<cost[n]<<endl;
}
int main(){
    
   int t;
   cin>>t;
   while(t--){
       int n,m;
       cin>>n>>m;
       vector<int>cost(n+1,-1);//accessing the nth element
       vector<int>adj[n+1];
       for(int i=0;i<m;i++){
           int a,b;
           cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
       }
       bfs(1,cost,adj,n);
   }
    return 0;
}
