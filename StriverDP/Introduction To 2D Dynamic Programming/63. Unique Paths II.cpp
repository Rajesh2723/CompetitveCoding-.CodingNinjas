/*
Problem Description: 

We are given an “N*M” Maze. The maze contains some obstacles. A cell is ‘blockage’ in the maze if its value is -1. 0 represents non-blockage. There is no path possible through a blocked cell.

We need to count the total number of unique paths from the top-left corner of the maze to the bottom-right corner. At every cell, we can move either down or towards the right.
*/
class Solution {
public:
int f(int i,int j,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
    if(i>0 and j>0 and obstacleGrid[i][j]==1){
        return 0;
    }
     
     if(i<0 || j<0 || obstacleGrid[i][j]==1){
             return 0;
     }
    
     if(i==0 and j==0){
         return 1;
     }
     if(dp[i][j]!=-1){
         return dp[i][j];
     }
    int up=f(i-1,j,obstacleGrid,dp);
    int left=f(i,j-1,obstacleGrid,dp);
    return dp[i][j]=up+left;

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int m=obstacleGrid.size();//rows
        int n=obstacleGrid[0].size();//columns
        vector<vector<int>>dp(m,vector<int>(n,-1));
       
        return f(m-1,n-1,obstacleGrid,dp);
    }
};
