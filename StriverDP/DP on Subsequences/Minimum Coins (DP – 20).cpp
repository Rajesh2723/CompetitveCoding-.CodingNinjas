/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
  */
class Solution {
public:
int f(int index,vector<int>&coins,int amount,vector<vector<int>>&dp){
     if(amount==0)return 0;
     if(index<0|| amount<0)return INT_MAX-1;
     
    if(dp[index][amount]!=-1){
        return dp[index][amount];
    }
    int notpick=f(index-1,coins,amount,dp);
     
     
       int pick=1+ f(index,coins,amount-coins[index],dp);
     
    return dp[index][amount]=min(pick,notpick);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans= f(n-1,coins,amount,dp);
        return (ans < INT_MAX-1)?ans:-1;
        
    }
};
