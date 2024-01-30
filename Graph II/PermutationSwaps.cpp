/*
Problem statement
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

He also believes that there are M good pairs of integers (ai, bi). Kevin can perform following operation with his permutation:

Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 100000
1 ≤ M ≤ 100000
1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
1 ≤ ai < bi ≤ N
Time Limit: 1 second
Sample Input 1:
2
4 1
1 3 2 4
1 4 2 3
3 4
4 1
1 3 2 4
1 4 2 3
2 4
Sample Output 1:
NO 
YES
  */
#include <bits/stdc++.h>
using namespace std;
 int visit[100005];
 int p[100005],q[100005];
 int n;
 vector<int> A,B;
 vector<int> g[100005];
void bfs(int i){
    queue <int> qe;
    qe.push(i);
    while(!qe.empty()){
        int k = qe.front();
        qe.pop();
        A.push_back(p[k]);
    B.push_back(q[k]);
        visit[k] = 1;
        for(int i=0;i<g[k].size();i++){
            if(!visit[g[k][i]]){
                qe.push(g[k][i]);
                visit[g[k][i]]=1;
            }    
        }  
    }
}
int main()
{
    int t;
    int m,a,b,i;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(i=0;i<n;i++){
            visit[i]=0;
            g[i].clear();
        }
        for(i=0;i<n;i++)
        cin>>p[i];
        for(i=0;i<n;i++)
        cin>>q[i];
        for(i=0;i<m;i++){
            cin>>a>>b;
           
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
        }
        int flag = 1;
        for(i=0;i<n;i++){
            A.clear();
            B.clear();
            if(!visit[i]){
                bfs(i);
                sort(A.begin(),A.end());
                sort(B.begin(),B.end());
                if(A!=B)
                flag = 0;
            }
            if(flag==0)
            break;
        }
        if(flag)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    return 0;
}
