/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
If S (sum of elements of the input array) is odd , there is no way we can divide it into two equal halves, so we can simply return false.
If S is even, then we need to find a subsequence in the input array whose sum is equal to S/2 because if we find one subsequence with sum S/2, the remaining elements sum will be automatically S/2. So, we can partition the given array. Hence we return true.
*/
//memoization code
class Solution {
public:
bool f(int index,int target,vector<int>&nums,vector<vector<int>>& dp){
    if(index==0){
        return nums[0]==target;
    }
    if(target==0){
        return true;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    int nottake=f(index-1,target,nums,dp);
    int take=false;
    if(nums[index]<=target){
        take=f(index-1,target-nums[index],nums,dp);
    }
    return dp[index][target]= take||nottake;//here made a mistake of not storing it and just returning 
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];          
        }
        if(totalsum%2==1){//array should be even size to divide 
            return false;
        }else{
            int k=totalsum/2;
             vector<vector<int>> dp(n, vector<int>(k + 1, -1));
            return f(n-1,k,nums,dp);
        }
    }
};
