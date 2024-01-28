/*
Problem statement
Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1
*/
// #include<bits/stdc++.h>
// using namespace std;
// int solve(vector<int>&u,vector<int>&v,int n,int m){

//     vector<vector<int>>edges(n,vector<int>(n,0));
//     for(int i=0;i<m;i++){
//         int start=u[i];
//         int end=v[i];
//         edges[start][end]=1;
//         edges[end][start]=1;
//     }
//     int count=0;
//    for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (edges[i][j] == 1 && i != j) {
//                 for (int k = 0; k < n; k++) {
//                     if (edges[j][k] == 1 && j != k && i != k) {
//                         if (edges[i][k] == 1 && i != k) {
//                             count++;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return count;

// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<int>u(m),v(m);
//     for(int i=0;i<m;i++){
//         int x;
//         cin>>x;
//         u.push_back(x);
//     }
//     for(int i=0;i<m;i++){
//         int x;
//         cin>>x;
//         v.push_back(x);
//     }
//     cout<<solve(u,v,n,m)<<endl;
// }
//  #include <bits/stdc++.h>
// using namespace std;

// int solve(vector<int>&u,vector<int>&v,int n,int m) {
//     vector<vector<int>> edges(n + 1);
//     int visit[n + 1];
//     memset(visit, 0, sizeof(visit));

//     for(int i=0;i<m;i++){
//         int start=u[i];
//         int end=v[i];
//         edges[start].push_back(end);
//         edges[end].push_back(start);
//     }

//     int count = 0;
//      for (int i = 1; i <= n; i++) {
//         memset(visit, 0, sizeof(visit));
//         for (int j = 0; j < edges[i].size(); j++) {
//             visit[edges[i][j]] = 1;
//         }
//         for (int k = 0; k < edges[i].size(); k++) {
//             int u = edges[i][k];
//             for (int j = 0; j < edges[u].size(); j++) {
//                 int v = edges[u][j];
//                 if (v == i) continue;
//                 if (visit[v]) {
//                     count++;
//                 }
//             }
//         }
//     }
//     return count / 6;
// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<int>u,v;
//     for(int i=0;i<m;i++){
//         int x;
//         cin>>x;
//         u.push_back(x);
//     }
//     for(int i=0;i<m;i++){
//         int x;
//         cin>>x;
//         v.push_back(x);
//     }
//     cout<<solve(u,v,n,m)<<endl;
// }
#include<iostream>
#include<vector>
using namespace std;


int solve(int n,int m,vector<int> u,vector<int> v)
{
	int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i=0;i<m;i++){
        int start,end;
        start = u[i] - 1;
        end = v[i] - 1;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }

    int count = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(edges[i][j] == 1 && i != j){
               for(int k=0;k<n;k++){
                   if(edges[j][k] == 1 && j != k && i != k){
                       if(edges[i][k] == 1){
                           count++;
                       }
                   }
               }
           }
        }
    }
    
    return count/6;
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
