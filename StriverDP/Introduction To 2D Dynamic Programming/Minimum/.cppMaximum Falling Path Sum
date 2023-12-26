/*
We are given an ‘N*M’ matrix. We need to find the maximum path sum from any cell of the first row to any cell of the last row.

At every cell we can move in three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
*/
class Solution {
public:
long long  f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
    if(i<0 ||j>=matrix.size()||j<0){
        return INT_MAX;//since we are calculating min value so return maximum value
    }
    if(i==0){//if it reached i=0 then the value in the first row returned
        return matrix[0][j];
    }
    if(dp[i][j]!=INT_MAX){
        return dp[i][j];
    }
     
       long long up=f(i-1,j,matrix,dp)+matrix[i][j];
   
       long long right=f(i-1,j+1,matrix,dp)+matrix[i][j];
  
      
          long long  diag=f(i-1,j-1,matrix,dp)+matrix[i][j];
    
     
    return dp[i][j]=min({up,right,diag});
}
    long long minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();//rows
        int n=matrix[0].size();//columns
        long long maxi=INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));//-1 had some answers so intitialised with INT_MAX
        for(int j=0;j<n;j++){
                long long ans=f(m-1,j,matrix,dp);//calling from bottom to top
                maxi=min(maxi,ans);
        }
        return maxi;
    }
};
