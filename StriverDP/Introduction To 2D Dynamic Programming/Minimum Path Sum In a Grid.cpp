/*
We are given an “N*M” matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix, such that there is a minimum cost past that we select.

At every cell, we can move in only two directions: right and bottom. The cost of a path is given as the sum of values of cells of the given matrix.


  */
class Solution {
public:
int f(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i==0 and j==0){
        return grid[i][j];
    }
    if(i<0 ||j<0){
        return INT_MAX;//if it goes out of bound we return INT_MAX so that it wont consider for the evalution of minimum value 
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // if(i==0){
    //         int sum=0;
    //         for(int j=0;j<grid[i].size();j++){
    //             sum+=grid[0][j];
    //         }
    //         return sum;
    // }
    int up=INT_MAX,left=INT_MAX;
    if(i>0){
         up=f(i-1,j,grid,dp)+grid[i][j];
    }
    if(j>0){
          left=f(i,j-1,grid,dp)+grid[i][j];
    }
   
    return dp[i][j]=min(up,left);
    
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,grid,dp);
    }
};
