/*
Problem statement
Ninja has gained weight in lockdown and has decided to shed this extra weight by joining the famous Infinite Gym. His gym is actually an infinite grid, where he works out according to the instructions of his trainer.

Each day, his trainer gives him two integers n, m. Ninja begins from cell (0,0) and has to reach cell (n,m).

Also, when Ninja is standing at cell (i, j), he can move to (i, j+1) and (i+1, j) only (right and bottom cells). Calculate the total number of ways he can do so.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10^5
0 <= N , M <= 18
0 <= N + M <= 18
Output Format:
For each test case print the total number of ways in new line.
Sample Input 1:
1
3 6
Sample Output 1:
84
Sample Input 2:
4
2 5
2 2
5 7
4 3
Sample Output 2:
21
6
792
35
  */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f(int i,int j,int n,int m,vector<vector<int>>&dp){
    if(i==n and j==m){
        return 1;
    }
    if(i<0||j>m||i>n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll right=f(i,j+1,n,m,dp);
    ll bottom=f(i+1,j,n,m,dp);
    return dp[i][j]=right+bottom;
}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        cout<<f(0,0,n,m,dp)<<endl;
    }
    return 0;
}
