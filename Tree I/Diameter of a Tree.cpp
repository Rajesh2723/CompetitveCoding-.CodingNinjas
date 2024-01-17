/*
Problem statement
You are given a tree with N vertex and N - 1 edge and you are supposed to find the diameter of the tree.

Diameter of a tree is defined as the maximum distance between any pair of leaves of a tree.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
2 <= N <= 10^4
1 <= u, v <= N
Sample Input:
1
8
1 7
5 1
2 7
5 6
8 1
3 6
2 4
Sampe output:
6
  */
//logic:finding the maximum and second (maxmimum->maximum+secondmaximum+2)for each node of a tree.
#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+5;
vector<int> tree[N];
int height[N];
int max_ht[N];

int ans = 0;

void dfs(int s, int p, int ht=0){
	height[s] = ht;
	max_ht[s] = ht;
	int maxim = 0, secondmaxim = 0;

	for(int v: tree[s]){
		if(v != p){
			dfs(v, s, ht+1);
			max_ht[s] = max(max_ht[s], max_ht[v]);
			if(max_ht[v] > maxim){
				secondmaxim = maxim;
				maxim = max_ht[v];
			} else if(max_ht[v] > secondmaxim){
				secondmaxim = max_ht[v];
			}
		}
	}

	int max_distance = max(0, max(maxim - ht, maxim + secondmaxim - 2*ht));//if there is a single node 
	ans = max(ans, max_distance);
}
int main(){
    int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		for(int i=0; i<=n; i++){
			tree[i].clear();
			height[i] = max_ht[i] = 0;
		}

		for(int i=0; i<n-1; i++){
			int u, v;
			cin>>u>>v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		ans = 0;
		dfs(1, 0);//starting from node 1.

		cout<<ans<<"\n";

	}
	// return 0;
     
    return 0;
}
