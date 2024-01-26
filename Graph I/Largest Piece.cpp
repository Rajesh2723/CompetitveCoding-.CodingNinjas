/*
Problem statement
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 1000
Sample Input :
1
2
11
01
Sample Output :
3
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000;
int solve(int n, int row, int col, vector<vector<int>> &arr, vector<vector<bool>> &visited) {
    visited[row][col] = true;
    queue<pair<int, int>> q;
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, +1, 0, -1};
    q.push({row, col});
    int ans = 0;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        ans++;
        for (int i = 0; i < 4; i++) {
            int nrow = drow[i] + r;
            int ncol = dcol[i] + c;
            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < n and !visited[nrow][ncol] and arr[nrow][ncol] == 1) {
                q.push({nrow, ncol});
                visited[nrow][ncol] = true;
            }
        }
    }
    return ans;
}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> arr(n,vector<int>(n));
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            string s;cin>>s;
            for(int j=0;j<n;j++){
                if(s[j]=='1') arr[i][j]=1;
                else arr[i][j]=0;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] and arr[i][j]){
                    ans=max(ans,solve(n,i,j,arr,visited));
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
