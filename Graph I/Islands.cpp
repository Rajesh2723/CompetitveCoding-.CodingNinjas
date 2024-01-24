/*
Problem statement
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 0 to N - 1) and M pair of integers (u and v) denoting island, u is connected to island v and vice versa. Can you count the number of connected groups of islands?

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 1000
1 <= M <= min((N*(N-1))/2, 1000)
0 <= u[i] ,v[i] < N
Output Return Format :
The count the number of connected groups of islands
Sample Input :
1
2 1
0 1
Sample Output :
1
  */
#include<bits/stdc++.h>
using namespace std;

void getcount(int** edges,int n,int start,bool* visited){
    queue<int> vertices;
    vertices.push(start);
    visited[start] = true;
    
    while(!vertices.empty()){
        int current = vertices.front();
        vertices.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[current][i] == 1 && i != current){//i equals current means parent is same as current one
                visited[i] = true;
                vertices.push(i);
            }
        }
    }
    return;
}


int solve(int n,int m,vector<int>u,vector<int>v)
{
	int** edges = new int*[n];
for(int i = 0; i < n; i++) {
    edges[i] = new int[n]();
    for(int j = 0; j < n; j++) {
        edges[i][j] = 0;
    }
}
    for(int i=0;i<m;i++){
        int start = u[i];
        int end = v[i] ;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;    //everytime function is called we get one connected component
            getcount(edges,n,i,visited);
        }
    }
    return count;
}
 

int main() {
    int t;
    cin>>t;
    while(t--){
         int n, m;
    cin >> n >> m;

    vector<int> u(m), v(m);//m->edges
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i];
    }

     cout<<solve(n, m, u, v)<<endl;
    }
   

    return 0;
}
