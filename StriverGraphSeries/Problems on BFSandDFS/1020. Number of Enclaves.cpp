/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
  */
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||j==0||i==n-1||j==m-1)and grid[i][j]==1){//if border values are 1 we are visiting them and pushing them to queue so that its adjacent values get visited if not there we get island values which we need to return.
                    q.push({i,j});
                    vis[i][j]=1;
                }else{
                    vis[i][j]=0;
                }
            }
        }
    int count=0;
      int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1 and vis[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and grid[i][j]==1){//if not visited and grid[i][j]==1 means border values we visited if we cant reach values inside from border then we cant find the route to it so we will just count them
                    count++;
                }
            }
        }
        return count;
    }
};
