/*
Problem statement
Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:

1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
Refer to the example below for clarification.
Note that the sum of the elements of an empty subset is 0.

For example :
If N = 4, D = 3, ARR = {5, 2, 5, 1}
There are only two possible partitions of this array.
Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.
*/
#include <bits/stdc++.h> 
int f(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
    
    if (dp[index][target] != -1) {
        return dp[index][target];
    }
    if (index == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == arr[0] || target == 0) return 1;
        return 0;
    }
    int nottake = f(index - 1, target, arr, dp);
    int take = 0;
    if (arr[index] <= target) {
        take = f(index - 1, target - arr[index], arr, dp);
    }
    return dp[index][target] = (take + nottake) % 1000000007;
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum=0;
     for(int i=0;i<arr.size();i++){
         totalsum+=arr[i];
     }
     if(totalsum-d<0){
         return 0;
     }
     if((totalsum-d)%2==1){
         return 0;
     }
     int s2=(totalsum-d)/2;
     vector<vector<int>>dp(n,vector<int>(s2+1,-1));
     return f(n-1,s2,arr,dp);
}


