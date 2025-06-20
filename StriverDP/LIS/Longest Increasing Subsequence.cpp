/*
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/
class Solution {
public:
int f(int index,int prefIndex,int n,vector<int>&nums,vector<vector<int>>&dp){
    if(index==n){
        return 0;
    }
    if(dp[index][prefIndex+1]!=-1){
        return dp[index][prefIndex+1];
    }
    int nottake=f(index+1,prefIndex,n,nums,dp);
    int take=0;
    if(prefIndex==-1||nums[index]>nums[prefIndex]){//check for prefIndex or nextNumber greater than previous.
        take=1+f(index+1,index,n,nums,dp);//swap the indexes to prefindex to current considered index.
    }
    return dp[index][prefIndex+1]=max(take,nottake);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,n,nums,dp);//pass -1 as we set prefIndex to -1 
    }
};

//tabulation
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1); // dp[i] = length of LIS ending at i

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
