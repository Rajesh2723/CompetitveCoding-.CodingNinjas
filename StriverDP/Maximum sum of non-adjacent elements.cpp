/*
Maximum sum of non-adjacent elements (DP 5)
In this article we will solve the problem: Maximum sum of non-adjacent elements (DP 5)

Problem Statement:

Given an array of ‘N’  positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

Note: A subsequence of an array is a list with elements of the array where some elements are deleted ( or not deleted at all) and the elements should be in the same order in the subsequence as in the array.
  As we need to find the sum of subsequences, one approach that comes to our mind is to generate all subsequences and pick the one with the maximum sum. 

To generate all the subsequences, we can use the pick/non-pick technique. This technique can be briefly explained as follows:

At every index of the array, we have two options.
First, to pick the array element at that index and consider it in our subsequence.
Second, to leave the array element at that index and not to consider it in our subsequence.
  */
class Solution {
public:
    int rob(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
    int f(int ind,vector<int>& nums, vector<int>& dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick= nums[ind]+ f(ind-2,nums,dp);
        int notPick= f(ind-1,nums,dp);
        return dp[ind]=max(pick,notPick);
    }
};
/* check this code (have to debug)
class Solution {
public:
int f(int index,vector<int>&nums,vector<int>&dp){
    if(index==0)return dp[index];
    if(index<0)return 0;
    if(dp[index]!=-1){
        return dp[index];
    }
     
     int pick=nums[index]+f(index-2,nums,dp);
     int notpick=f(index-1,nums,dp);    
    return dp[index]=max(pick,notpick);
    
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(n-1,nums,dp);
    }
};
*/
//tabulation code
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[n-1];
    }
};
