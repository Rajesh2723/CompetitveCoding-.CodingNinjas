/*
Problem Statement:  Frog Jump with K Distance/ Learn to write 1D DP

Problem Statement:

This is a follow-up question to “Frog Jump” discussed in the previous article. In the previous question, the frog was allowed to jump either one or two steps at a time. In this question, the frog is allowed to jump up to ‘K’ steps at a time. If K=4, the frog can jump 1,2,3, or 4 steps at every index.
  */
#include<bits/stdc++.h>
int f(int index,int k,vector<int>&height,vector<int>&dp){
    if(index==0)return 0;
    if(dp[index]!=-1){
        return dp[index];
    }
    int mini=INT_MAX;
     
    for(int i=1;i<=k;i++){//it can take the steps from 1 to k so for that for loop 
        if(index-i>=0){
            int jumps=f(index-i,k,height,dp)+abs(height[index]-height[index-i]);//i can take from 1 to k jumps 
            mini=min(mini,jumps);
        }
        
    }
    dp[index]=mini;
    return dp[index];
    
}
int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n+1,-1);
    return f(n-1,k,height,dp);
}
