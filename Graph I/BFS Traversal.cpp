/*
Problem statement
Given an undirected graph G(V, E), print its BFS traversal.

Here you need to consider that you need to print BFS path starting from vertex 0 only.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.

E is the number of edges present in graph G.

Note :
1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
2 <= V <= 1000

1 <= E <= 1000

Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
  */
// #include<bits/stdc++.h>
// using namespace std;
// void bfs(int start,vector<int>adj[],vector<bool>&vis){
//     vis[start]=true;
//     queue<int>q;
//     q.push(start);
//     while(!q.empty()){
//         int node=q.front();
//         q.pop();
//         cout<<node<<" ";
//         for(auto x:adj[node]){
//             if(!vis[x]){
//                 vis[x]=true;
//                 q.push(x);
//             }
//         }
        
//     }
// }
// int main(){
    
//      int n,e;
//      cin>>n>>e;
//      vector<int>adj[n];
//      vector<vector<int>> edges;
//      for(int i=0; i<e; i++){
//     int u, v;
//     cin >> u >> v;
//     edges.push_back({u, v});
// }
// for(auto it : edges){
//     adj[it[0]].push_back(it[1]);
//     adj[it[1]].push_back(it[0]);
// }

//     vector<bool>vis(n,false);
//     bfs(0,adj,vis);
//     return 0;
// }
arr[0] -> [0, 0, 0]
arr[1] -> [0, 0, 0]
arr[2] -> [0, 0, 0]

#include<iostream>
#include<queue>
using namespace std;
void print(int** arr, int n, int starting_vertex, bool* visited)
{
	queue<int> q;
	q.push(starting_vertex);
	visited[starting_vertex] = true;
	while (!q.empty())
	{
		cout << q.front()<<" ";
		int current_element = q.front();
		for (int i = 1; i < n; i++)
		{
			if (i == current_element)
			{
				continue;
			}
			if (visited[i])
			{
				continue;
			}
			if (arr[current_element][i] == 1)
			{
				q.push(i);
				visited[i] = true;
			}
		}
		q.pop();
	}
}
int main()
{
	int v, e;
	cin >> v >> e;
	int** arr = new int* [v];
	for (int i = 0; i < v; i++)
	{
		arr[i] = new int[v];
		for (int j = 0; j < v; j++)
		{
			arr[i][j] = 0;
		}
	}
	while (e--)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        {
            print(arr, v, i, visited);
        }
    }
	
}

