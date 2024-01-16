#include<bits/stdc++.h>

using namespace std;

const int N = (int)(1e5+5);

vector<int> tree[N]; 


void dfs(int s, int p){
	cout<<s<<" ";
	for(int v: tree[s]){
		if(v != p){
			dfs(v, s);
		}
	}
}

void bfs(int root){
	queue<int> q;
	q.push(root);
	vector<bool> visited(N, false);

	visited[root] = true;

	cout<<"Running BFS---\n";

	while(!q.empty()){
		int u = q.front();
		cout<<u<<" ";
		q.pop();

		for(int v: tree[u]){
			if(!visited[v]){
				visited[v] = true;
				q.push(v);
			}
		}
	}
	cout<<endl;

}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	cin>>n;

	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	cout<<"Running DFS---\n";
	dfs(1, 0);

	cout<<endl;

	bfs(1);

	return 0;
}
