/*
Problem statement
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
  */
//memoization code
#include <bits/stdc++.h> 
bool findPartition(int index,vector<int>&nums,vector<vector<int>>&dp,int k){
     if(k==0){
         return true;
     }
     if(dp[index][k]!=-1){
         return dp[index][k];
     }
    if(index==0){
         return nums[0]==k;
    }
     
    bool take=false;
    if(k>=nums[index]){//target should be greater than a number to take
        take=findPartition(index-1,nums,dp,k-nums[index]);
       
    }
     bool nottake=findPartition(index-1,nums,dp,k);
     
    return dp[index][k]= take|nottake;
}
bool subsetSumToK(int n, int k, vector<int> &nums) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));//creating dp with changing states parameters(index,target)
        return findPartition(n-1,nums,dp,k);
}
 

    
