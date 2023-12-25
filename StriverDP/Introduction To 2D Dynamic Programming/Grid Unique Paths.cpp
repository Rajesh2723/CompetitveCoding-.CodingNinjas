/*
Given two values M and N, which represent a matrix[M][N]. We need to find the total unique paths from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).

At any cell we are allowed to move in only two directions:- bottom and right.
*/
//memoization approach (for counting we are just using the return 1 and return 0 method)
class Solution {
public:
int f(int i,int j,vector<vector<int>>&dp){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=f(i-1,j,dp);
    int left=f(i,j-1,dp);
    return dp[i][j] = up + left;

}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp);
    }
};
